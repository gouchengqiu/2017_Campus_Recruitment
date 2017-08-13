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
	if (!m_pBlock) //���ڴ�ص�ǰ�ڴ������Ϊ�գ���ζ�����ǵ�һ���ڴ���������
	{
	}

	//�ڴ�����Ϊ�գ����ڴ���������ڴ��  �򣺱�������Ѱ�һ��С����ɷ��䵥Ԫ�����ڴ��

	SMyMemoryBlock* pMyBlock = m_pBlock;
	while (pMyBlock && !pMyBlock->m_Free)
	{
		pMyBlock = pMyBlock->m_pNextBlock;
	}

	//�������ҵ��������ɷ��䵥Ԫ���ڴ�飬��"��λ"�����ڴ�����ڿ����õ����ɷ��䵥Ԫ��
	if (pMyBlock)
	{
		char* pFree = pMyBlock->m_Data + (pMyBlock->m_First*m_nUnitSize); //��Ϊ�����ڴ浥Ԫ�ߴ�һ�������Կɸ����ڴ浥Ԫ�±�����λĳ�ڴ浥Ԫ�ĵ�ַ
		pMyBlock->m_First = *((unsigned short*)pFree);//�÷��䵥Ԫ��ͷ�����ֽڴ洢��һ�����ɷ��䵥Ԫ�ı��
		pMyBlock->m_Free--;
	}
	else //û���ҵ��������ɷ��䵥Ԫ���ڴ�� ����Ҫ��������̶�����һ���ڴ��
	{
		if (!m_nGrowSize)
		{
			return NULL;
		}
		//pMyBlock = new(m_nGrowSize, m_nUnitSize); //�����ڴ��
		//fixedMemBlock(m_nGrowSize, m_nUnitSize);//�����ڴ������ڴ��ͷ��

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

	if (pMyBlock == NULL)//pMyBlockΪNULLʱ�����Σ���pFree�����ڴ��ڴ�صķ�Χ ��˲��ܷ��ظ����ڴ��
	{
	}
	pMyBlock->m_Free++;
	*((unsigned short*)pFree) = pMyBlock->m_First; //�����޸ĸ��ڴ������ɷ��䵥Ԫ�������Ϣ
	//��pMyBlock��nFirstֵ�ı�Ϊָ����������շ��䵥Ԫ�ı�� 
	//����ͨ������˵�Ԫ����ʼλ�����pMyBlock��aDataλ�õĲ�ֵ��Ȼ����Բ�����nUnitSize���õ���
	pMyBlock->m_First = (unsigned short) ((ULONG)pFree - (ULONG)(pMyBlock->m_Data)/m_nUnitSize);

	//�ж�һ���ڴ������е�Ԫ�Ƿ񶼴�������״̬ʱ����û�б��������е�Ԫ�������ж�nFree����nUnitSize�Ƿ����nSize
	if (pMyBlock->m_Free * m_nUnitSize == pMyBlock->m_Size)//�������ټ��ĳ���ڴ�������з��䵥Ԫ�Ƿ�ȫ����������״̬
	{
		//����ڴ��������ڴ浥Ԫ����������״̬
	}
	else
	{

	}
}