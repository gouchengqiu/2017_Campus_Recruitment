#pragma once
#include <stdio.h>
#include <string>

class CMyString
{
public:
	CMyString(char* vData = NULL);
	CMyString(const CMyString& vStr);
	~CMyString();

	CMyString& operator= (const CMyString& vOther);

private:
	char* m_pData;
};

CMyString::CMyString(char* vData)
{
	//int StrLength = 0;
	//if (vData == NULL)
	//{
	//	StrLength = 1;
	//}else
	//{
	//	StrLength = strlen(vData) + 1;
	//}

	//m_pData = new char[StrLength];
	//m_pData = vData; //NULL  error


	if (vData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}else
	{
		m_pData = new char[strlen(vData) + 1];
		strcpy(m_pData, vData);
		//m_pData = vData;
	}
}

CMyString::CMyString(const CMyString& vStr)
{
	CMyString(vStr.m_pData);
}

CMyString::~CMyString()
{
}

CMyString& CMyString::operator=(const CMyString& vOther)
{
	delete[] m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(vOther.m_pData) + 1];
	m_pData = vOther.m_pData;

	return *this;
}