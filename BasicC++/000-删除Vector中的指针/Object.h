#pragma once
#include <iostream>

class CObject
{
public:
	CObject(int vData);
	~CObject();

private:
	int m_Data;
};

CObject::CObject(int vData)
{
	m_Data = vData;
	std::cout << "Construct.\n";
}

CObject::~CObject()
{
	std::cout << "Destruct.\n";
}