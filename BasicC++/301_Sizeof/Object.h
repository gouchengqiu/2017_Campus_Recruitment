#pragma once

class CObject
{
public:
	CObject();
	~CObject();

	void functionA() {}
	void functionB() {}

private:
	char m_String;
	//int  m_Number;
};

CObject::CObject()
{
}

CObject::~CObject()
{
}