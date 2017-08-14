#pragma once
#include "Base.h"

class CDerivedClass : public CBaseClass
{
public:
	CDerivedClass();
	~CDerivedClass();

	void funV() override {}
	int getData() const {return m_Data;}

private:
	int m_Data;
};

CDerivedClass::CDerivedClass() : m_Data(0)
{
}

CDerivedClass::~CDerivedClass()
{
}