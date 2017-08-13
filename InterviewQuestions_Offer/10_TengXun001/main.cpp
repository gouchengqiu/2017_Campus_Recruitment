#include <string>
#include <iostream>
#include "limits.h"

#define MAXLENGTH 1000

//https://www.nowcoder.com/test/question/28c1dc06bc9b4afd957b01acdf046e69?pid=1725829&tid=7379757Ã⁄—∂±  ‘

int computeLongestCommonSubstring(const std::string& vInputStrA, const std::string& vInputStrB)
{
	int MaxCommonLetters = INT_MIN;
	for (unsigned int i=0; i<vInputStrA.length(); i++)
	{
		int TempCommomLetters = 0;
		int CompareIndex = i;
		for (unsigned int k=0; k<vInputStrB.length(); k++)
		{
			if (vInputStrA[CompareIndex] != vInputStrB[k])
			{
				MaxCommonLetters = MaxCommonLetters < TempCommomLetters ? TempCommomLetters : MaxCommonLetters;
				break;
			}
			else
			{
				TempCommomLetters++;
				CompareIndex++;
			}
		}
	}
	return MaxCommonLetters;
}

int computeDeleteNum(const std::string& vInputStr)
{
	std::string ReverseStr(vInputStr.rbegin(), vInputStr.rend());
	int EqualLength = computeLongestCommonSubstring(vInputStr, ReverseStr);
	return vInputStr.length() - EqualLength;
}

void printResult(char** vStrArray, unsigned int vLine)
{
	for (unsigned int i=0; i<vLine; i++)
	{
		std::cout << computeDeleteNum(vStrArray[i]) << std::endl;
	}
}

int main()
{
	int NumLine = 0;
	std::cin >> NumLine;

	char** ppInputString = new char*[NumLine];
	for (unsigned int i=0; i<NumLine; i++)
	{
		ppInputString[i] = new char[MAXLENGTH]();
		std::cin >> ppInputString[i];
	}
	printResult(ppInputString, NumLine);

	for (unsigned int i=0; i<NumLine; i++)
	{
		delete[] ppInputString[i];
	}

	delete[] ppInputString;

	//std::string Test = "zgtklhfzomzjckwmluvivvcmhjrwkuvcjrxojobpdedpamdshcwwsetfbacvonecrdvugeibglvhxuymjvoryqjwullvzglqazxrdmczyvbgakjagttrezmvrlptiwoqkrtxuroeqmryzsgokopxxdpbejmtwvpnaqrgqladdszhdwxfckmewhdvihgvacueqhvwvjxoitlpfrckxkuksaqzjpwgoldyhugsacflcdqhifldoaphgdbhaciixouavqxwlghadmfortqacbffqzocinvuqpjthgekunjsstukeiffjipzzabkuiueqnjgkuiojwbjzfynafnlcaryygqjfixaoeowhkxkbsnpsvnbxuywfxbnuoemxynbtgkqtjvzqikbafjnpbeirxxrohhnjqrbqqzercqcrcswojyylunuevtdhamlkzqnjrzibwckbkiygysuaxpjrgjmurrohkhvjpmwmmtpcszpihcntyivrjplhyrqftghglkvqeidyhtmrlcljngeyaefxnywpfsualufjwnffyqnpitgkkyrbwccqggycrvoocbwsdbftkigrkcbojuwwctknzzmvhbhbfzrqwzllulbabztqnznkqdyoqnrxhwavqhzyzvmmmphzxbikpharseywpfsqyybkynwbdrgfsaxduxojcdqcjuaywzbvdjgjqtoffasiuhvxcaockebkuxpiomqmtvsqhnyxfjceqevqvnapbk";
	//int Length1 = Test.length();
	//computeDeleteNum(Test);

	return 0;
}