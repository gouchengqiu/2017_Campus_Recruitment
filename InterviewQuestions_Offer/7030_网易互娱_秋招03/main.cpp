#include <string>
#include <iostream>

int** longestCommonSubsequence(const std::string& vStrA, const std::string& vStrB, int& voLines, int& voCols)
{
	int LengthA = vStrA.length();
	int LengthB = vStrB.length();
	int** ppDynamicTable = new int*[LengthA+1];
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
				ppDynamicTable[i][k] = 0;
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

int main()
{
	int Length1, Length2;
	std::cin >> Length1;
	std::cin >> Length2;

	std::string Str1, Str2;
	std::cin >> Str1;
	std::cin >> Str2;

	int TableLines = 0, TableCols = 0;
	int** ppTable = longestCommonSubsequence(Str1, Str2, TableLines, TableCols);

	std::cout << ppTable[TableLines - 1][TableCols - 1] << std::endl;

	for (unsigned int i=0; i<TableLines; ++i)
	{
		delete[] ppTable[i];
	}
	delete[] ppTable;

	return 0;
}