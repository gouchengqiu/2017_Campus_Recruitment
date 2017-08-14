#pragma once

class CMemoryTest
{
public:
	CMemoryTest();
	~CMemoryTest();

public:
	int   m_Data;
	char* m_pArray;
};

CMemoryTest::CMemoryTest()
{
	m_Data   = 10;
	m_pArray = new char[10];
}

CMemoryTest::~CMemoryTest()
{
	m_Data = 0;
	delete[] m_pArray;
}