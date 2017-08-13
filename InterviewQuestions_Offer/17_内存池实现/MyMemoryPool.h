#pragma once
#include <stdlib.h>
#include <WTypesbase.h>
#include "MyMemoryBlock.h"

#define MEMORYPOOL_ALIGNMENT 8 

class CMyMemoryPool
{
public:
	CMyMemoryPool(unsigned short vUnitSize, unsigned short vInitSize, unsigned short vGrowSize);
	~CMyMemoryPool();

	void* alloc();
	void  free(void* vPtr);

private:
	SMyMemoryBlock* m_pBlock;
	unsigned short m_nUnitSize;
	unsigned short m_nInitSize;
	unsigned short m_nGrowSize;
};

CMyMemoryPool::CMyMemoryPool(unsigned short vUnitSize, unsigned short vInitSize, unsigned short vGrowSize)
{
	m_pBlock    = NULL;
	m_nInitSize = vInitSize;
	m_nGrowSize = vGrowSize;

	if (vUnitSize > 4)
	{
		m_nUnitSize = (vUnitSize + (MEMORYPOOL_ALIGNMENT-1)) & ~(MEMORYPOOL_ALIGNMENT-1);
	}
	else if (vUnitSize <= 2)
	{
		m_nUnitSize = 2;
	}
	else
	{
		m_nUnitSize = 4;
	}
}

CMyMemoryPool::~CMyMemoryPool()
{
}

void* CMyMemoryPool::alloc()
{
	if (!m_pBlock) //当内存池当前内存块链表为空，意味着这是第一次内存申请请求
	{
	}

	//内存链表不为空，即内存池中已有内存块  则：遍历链表，寻找还有“自由分配单元”的内存块

	SMyMemoryBlock* pMyBlock = m_pBlock;
	while (pMyBlock && !pMyBlock->m_Free)
	{
		pMyBlock = pMyBlock->m_pNextBlock;
	}

	//检查如果找到还有自由分配单元的内存块，则"定位"到该内存块现在可以用的自由分配单元处
	if (pMyBlock)
	{
		char* pFree = pMyBlock->m_Data + (pMyBlock->m_First*m_nUnitSize); //因为所有内存单元尺寸一样，所以可根据内存单元下标来定位某内存单元的地址
		pMyBlock->m_First = *((unsigned short*)pFree);//该分配单元的头两个字节存储下一个自由分配单元的编号
		pMyBlock->m_Free--;
	}
	else //没有找到还有自由分配单元的内存块 则需要重新向进程堆申请一个内存块
	{
		if (!m_nGrowSize)
		{
			return NULL;
		}
		//pMyBlock = new(m_nGrowSize, m_nUnitSize); //分配内存块
		//fixedMemBlock(m_nGrowSize, m_nUnitSize);//将此内存块插入内存池头部

		if (!pMyBlock)
		{
			return NULL;
		}

		pMyBlock->m_pNextBlock = m_pBlock;
		m_pBlock = pMyBlock;

		return (void*) (pMyBlock->m_Data);
	}
}

void CMyMemoryPool::free(void* pFree)
{
	//......
	SMyMemoryBlock* pMyBlock = m_pBlock;

	while ((ULONG)(pMyBlock->m_Data) > (ULONG)(pFree) || (ULONG)pFree >= (ULONG)(pMyBlock->m_Data) + pMyBlock->m_Size)
	{

	}

	if (pMyBlock == NULL)//pMyBlock为NULL时的情形，即pFree不属于此内存池的范围 因此不能返回给此内存池
	{
	}
	pMyBlock->m_Free++;
	*((unsigned short*)pFree) = pMyBlock->m_First; //用来修改该内存块的自由分配单元链表的信息
	//将pMyBlock的nFirst值改变为指向这个待回收分配单元的编号 
	//其编号通过计算此单元的起始位置相对pMyBlock的aData位置的差值，然后除以步长（nUnitSize）得到。
	pMyBlock->m_First = (unsigned short) ((ULONG)pFree - (ULONG)(pMyBlock->m_Data)/m_nUnitSize);

	//判断一个内存块的所有单元是否都处于自由状态时，并没有遍历其所有单元，而是判断nFree乘以nUnitSize是否等于nSize
	if (pMyBlock->m_Free * m_nUnitSize == pMyBlock->m_Size)//用来快速检查某个内存块中所有分配单元是否全部处于自由状态
	{
		//则该内存块的所有内存单元都处于自由状态
	}
	else
	{

	}
}