#pragma once

class CCircle
{
public:
	explicit CCircle(float vRadius) : m_Radius(vRadius) {}
	explicit CCircle(int vX, int vY=0) : m_X(vX), m_Y(vY) {}
	explicit CCircle(const CCircle& vCircle) : m_Radius(vCircle.m_Radius), m_X(vCircle.m_X), m_Y(vCircle.m_Y){}
	~CCircle() {}

private:
	float m_Radius;
	int   m_X;
	int   m_Y;
};