// StringPermutation.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

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
//k表示当前选取到第几个数，m表示共有多少个数
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
//FUNCTION:全排列
void pailie(char* pStr , char *pBegin)
{
	if(*pBegin == '\0')  
	{  
		static int num = 1;  //局部静态变量，用来统计全排列的个数  
		printf("第%d个排列\t%s\n",num++,pStr);  
	}  
	else  
	{  
		for(char *pCh = pBegin; *pCh != '\0'; pCh++)   //第pBegin个数分别与它后面的数字交换就能得到新的排列     
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


// ====================测试代码====================
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

