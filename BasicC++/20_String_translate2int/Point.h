#pragma once
#include <iostream>

class CPoint
{
public:
	CPoint();
	~CPoint();

public:
	float m_PositionX;
	float m_PositionY;
};

CPoint::CPoint()
{
	std::cout << "Construct function: \n";
}

CPoint::~CPoint()
{
	std::cout << "Destruct function: \n";
}