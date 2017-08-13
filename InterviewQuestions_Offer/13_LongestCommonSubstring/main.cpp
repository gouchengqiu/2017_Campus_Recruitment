#include <string>
#include <iostream>
#include <math.h>
#include <vector>

// http://blog.csdn.net/hackbuteer1/article/details/6686931  参考网上：直尺移动
int longestCommonSubstring(const std::string& vStrA, const std::string& vStrB)
{
	int LengthA = vStrA.length();
	int LengthB = vStrB.length();

	int SA_Start, SB_Start;
	int Max = 0;
	
	for (int i=0; i<LengthA+LengthB; i++)
	{
		SA_Start = SB_Start = 0;
		if (i < LengthA)
		{
			SA_Start = LengthA-i;
		}
		else
		{
			SB_Start = i-LengthB;
		}

		int CurrentMax = 0;
		for (int Index=0; SA_Start+Index<LengthA && SB_Start+Index<LengthB; Index++)
		{
			if (vStrA[SA_Start+Index] == vStrB[SB_Start+Index])
			{
				CurrentMax++;
			}
			else
			{
				Max = (Max < CurrentMax) ? CurrentMax : Max;
				CurrentMax = 0;
			}
		}

		Max = (Max < CurrentMax) ? CurrentMax : Max;
	}

	return Max;
}

//自己理解写的
int computeLCSLength(const std::string& vStrA, const std::string& vStrB)
{
	int IndexA = vStrA.length()-1;  //指向A的末位
	int IndexB = 0;                 //指向B的开始

	int Max = 0;
	int MaxCommonLetters = (vStrA.length() > vStrB.length()) ? vStrB.length() : vStrA.length();
	int CompareLetters = 1;
	for (; CompareLetters<=MaxCommonLetters; CompareLetters++)
	{
		int TempMax = 0;
		for (unsigned int i=0; i<CompareLetters; i++)
		{
			if (vStrB[IndexB + CompareLetters - 1 - i] == vStrA[IndexA - i])
			{
				TempMax++;
			}
			else
			{
				Max = Max < TempMax ? TempMax : Max;
			}
		}
		Max = Max < TempMax ? TempMax : Max;
	}
	return Max;
}

int main()
{
	std::string Str1, Str2;
	// 
	// 	std::cin >> Str1;
	// 	std::cin >> Str2;

	Str1 = "shaohui";
	Str2 = "ahui";

	int LongestCommonLength = computeLCSLength(Str1, Str2);
	int i = LongestCommonLength;

	return 0;
}