#pragma once

struct SMyMemoryBlock //�ṹ�岢��ά����Щ�Ѿ�����ĵ�Ԫ����Ϣ,��ֻά��û�з�������ɷ��䵥Ԫ����Ϣ
{
	unsigned short m_Size; //nSize���ڴ�������з��䵥Ԫ�Ĵ�С
	unsigned short m_Free; //��¼����ڴ���л��ж��ٸ����ɷ��䵥Ԫ
	unsigned short m_First;//��¼��һ���ɹ�����ĵ�Ԫ�ı��
	unsigned short m_DummyAlign1;
	SMyMemoryBlock* m_pNextBlock;
	char            m_Data[1];

	SMyMemoryBlock();//δ��
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