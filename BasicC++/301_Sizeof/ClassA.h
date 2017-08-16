#pragma once

class CClassA
{
public:
	CClassA(int vNumber) {m_NumberA = vNumber; m_NumberB = vNumber;}
	CClassA(const CClassA& vOther) {m_NumberA = vOther.m_NumberA;}

private:
	int m_NumberA;
	int m_NumberB;
};