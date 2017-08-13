#pragma once

struct SMyMemoryBlock //结构体并不维护那些已经分配的单元的信息,它只维护没有分配的自由分配单元的信息
{
	unsigned short m_Size; //nSize是内存块中所有分配单元的大小
	unsigned short m_Free; //记录这个内存块中还有多少个自由分配单元
	unsigned short m_First;//记录下一个可供分配的单元的编号
	unsigned short m_DummyAlign1;
	SMyMemoryBlock* m_pNextBlock;
	char            m_Data[1];

	SMyMemoryBlock();//未完
    ~SMyMemoryBlock(){}

	static void* operator new(size_t, unsigned short vTypes, unsigned short vUnitSize)
	{
		return ::operator new(sizeof(SMyMemoryBlock) + vTypes * vUnitSize);
	}

	static void operator delete(void* vPtr, size_t)
	{
		::operator delete(vPtr);
	}
};