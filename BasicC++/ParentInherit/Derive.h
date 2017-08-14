#pragma once
#include "Base.h"

class CDerive : public CBase
{
public:
	CDerive(int vDataA, int vDataB);
	~CDerive();

	virtual void method() override {std::cout << "This is child method.\n";}

private:
	int m_DataT;
};

CDerive::CDerive(int vDataA, int vDataB) : CBase(vDataA)
{
	m_DataT = vDataB;
}

CDerive::~CDerive()
{
}