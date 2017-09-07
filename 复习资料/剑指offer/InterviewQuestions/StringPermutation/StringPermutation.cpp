// StringPermutation.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <iostream>

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;

    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if(*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

//http://blog.csdn.net/hackbuteer1/article/details/7462447
//k��ʾ��ǰѡȡ���ڼ�������m��ʾ���ж��ٸ���
void Permutation_02(char* pStr, int k, int m)
{
	if (k == m)
	{
		static int Num = 1;
		std::cout << pStr << " ";
	}else
	{
		for (int i=k; i<=m; i++)
		{
			char Temp = pStr[k];
			pStr[k] = pStr[i];
			pStr[i] = Temp;

			Permutation_02(pStr, k+1, m);

			Temp = pStr[k];
			pStr[k] = pStr[i];
			pStr[i] = Temp;
		}
	}
}

void swap(char& vBegin, char& vch)
{
	char Temp = vBegin;
	vBegin = vch;
	vch = Temp;
}

bool IsSwap(char* pBegin , char* pEnd)  
{  
	char *p;  
	for(p = pBegin ; p < pEnd ; p++)  
	{  
		if(*p == *pEnd)  
			return false;  
	}  
	return true;  
}

//********************************************************************
//FUNCTION:ȫ����
void pailie(char* pStr , char *pBegin)
{
	if(*pBegin == '\0')  
	{  
		static int num = 1;  //�ֲ���̬����������ͳ��ȫ���еĸ���  
		printf("��%d������\t%s\n",num++,pStr);  
	}  
	else  
	{  
		for(char *pCh = pBegin; *pCh != '\0'; pCh++)   //��pBegin�����ֱ�������������ֽ������ܵõ��µ�����     
		{  
			if(IsSwap(pBegin , pCh))  
			{  
				swap(*pBegin , *pCh);  
				pailie(pStr , pBegin + 1);  
				swap(*pBegin , *pCh);  
			}  
		}  
	}  
}


// ====================���Դ���====================
void Test(char* pStr)
{
    if(pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test(NULL);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);
	//Permutation_02(string4, 0, strlen(string4)-1);

	char Str[] = "122";
	pailie(Str, Str);
    return 0;
}

