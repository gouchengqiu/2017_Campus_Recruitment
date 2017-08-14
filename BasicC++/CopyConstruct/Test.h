#pragma once
#include <iostream>

class CTest
{
public:
	CTest()
	{
		m_Data = 0;
		std::cout << "Default constructor...\n";
	}

	CTest(const CTest& vObj)
	{
		this->m_Data = vObj.m_Data;
		std::cout << "Copy constructor...\n";
	}

	void operator= (const CTest& vObj)
	{
		this->m_Data = vObj.m_Data;
		std::cout << "Operator= ...\n";
	}
	~CTest() {}

	int getData() const {return m_Data;} 
private:
	int m_Data;
};