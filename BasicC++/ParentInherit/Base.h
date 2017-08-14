#pragma once
#include <iostream>

class CBase
{
public:
	CBase(int vData);
	virtual ~CBase();

	virtual void method(){std::cout << "This is parent class.\n";}

private:
	int m_Data;
};

CBase::CBase(int vData)
{
	m_Data = vData;
}

CBase::~CBase()
{
}