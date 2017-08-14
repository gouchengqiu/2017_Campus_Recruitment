#pragma once
#include <iostream>

class CObject
{
public:
	CObject();
	CObject(int vA);
	~CObject();

	int getData() const {return m_Data;}

private:
	int m_Data;
};

CObject::CObject(int vA)
{
	m_Data = vA;
	std::cout << "construct\n"; 
}

CObject::CObject() : m_Data(5)
{
	std::cout << "construct\n"; 
}

CObject::~CObject()
{
	std::cout << "distruct\n";
}