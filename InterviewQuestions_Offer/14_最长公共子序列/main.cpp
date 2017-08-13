#include <string>
#include <iostream>
#include <math.h>
#include <vector>

//http://blog.csdn.net/lisonglisonglisong/article/details/41548557
int** longestCommonSubsequence(const std::string& vStrA, const std::string& vStrB, int& voLines, int& voCols) //生成动态规划表
{
	int LengthA = vStrA.length(); //m
	int LengthB = vStrB.length(); //n
	int** ppDynamicTable = new int*[LengthA+1]; //m+1行 n+1列
	for (unsigned int i=0; i<LengthA+1; i++)
	{
		ppDynamicTable[i] = new int[LengthB+1];
	}

	voLines = LengthA+1;
	voCols  = LengthB+1;

	for (unsigned int i=0; i<LengthA+1; i++)
	{
		for (unsigned int k=0; k<LengthB+1; k++)
		{
			if (i==0 || k==0)
			{
				ppDynamicTable[i][k] = 0; //第0行 第0列置为0
				continue;
			}

			if (vStrA[i-1] == vStrB[k-1])
			{
				ppDynamicTable[i][k] = ppDynamicTable[i-1][k-1] + 1;
			}
			else
			{
				ppDynamicTable[i][k] = std::max(ppDynamicTable[i][k-1], ppDynamicTable[i-1][k]);
			}
		}
	}
	return ppDynamicTable;
}

//http://blog.csdn.net/lisonglisonglisong/article/details/41596309
    
std::vector<std::string> g_ResultSet;
void getLSCString(int vIndexI, int vIndexJ, int** vTable, const std::string& vStrA, const std::string& vStrB, std::string LCSResult)
{
	while (vIndexI > 0 && vIndexJ > 0)
	{
		_ASSERT(vIndexI-1 < vStrA.length() && vIndexJ-1 < vStrB.length());
		if (vStrA[vIndexI-1] == vStrB[vIndexJ-1])
		{
			LCSResult += vStrA[vIndexI-1];
			vIndexI--;
			vIndexJ--;
		}
		else
		{
			if (vTable[vIndexI][vIndexJ-1] == vTable[vIndexI-1][vIndexJ])
			{
				getLSCString(vIndexI, vIndexJ-1, vTable, vStrA, vStrB, LCSResult);
				getLSCString(vIndexI-1, vIndexJ, vTable, vStrA, vStrB, LCSResult);
				return;
			}
			else
			{
				vTable[vIndexI][vIndexJ-1] > vTable[vIndexI-1][vIndexJ] ? vIndexJ-- : vIndexI--;
			}
		}
	}

	g_ResultSet.push_back(LCSResult);
}

int main()
{
	std::string Str1, Str2;
	// 
	// 	std::cin >> Str1;
	// 	std::cin >> Str2;
	Str1 = "BDCABA";
	Str2 = "ABCBDAB";

	int TableLines = 0;
	int TableCols = 0;
	int** ppTable = longestCommonSubsequence(Str1, Str2, TableLines, TableCols);

	std::cout << "最长公共子序列长度: " << ppTable[TableLines-1][TableCols-1] << std::endl;

	std::string Res;
	getLSCString(TableLines-1, TableCols-1, ppTable, Str1, Str2, Res);

	for (unsigned int i=0; i<g_ResultSet.size(); i++)
	{
		std::cout << g_ResultSet[i] << std::endl;
	}

	for (unsigned int i=0; i<TableLines; i++)
	{
		delete[] ppTable[i];
	}
	delete[] ppTable;

	return 0;
}