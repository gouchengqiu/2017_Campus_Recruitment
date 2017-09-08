#include <iostream>
#include <string>

bool isCase1(std::string vStr)
{
	int Length = vStr.length();
	int LeftIndex = -1;
	for (int i=0; i<Length-1; ++i)
	{
		if (vStr[i] == '(' && vStr[i+1] == ')')
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool isCase2(std::string vStr, int& voLeftNum)
{
	int Length = vStr.length();
	int LeftNum = 0;

	for (int i=0; i<Length - 1; ++i)
	{
		if (vStr[i] == vStr[i+1])
		{
			LeftNum++;
		}
		else
		{
			break;
		}
	}

	int RightNum = 0;
	for (int i=LeftNum+1; i<Length-1; ++i)
	{
		if (vStr[i] == vStr[i+1])
		{
			RightNum++;
		}
	}

	voLeftNum = LeftNum + 1;
	return LeftNum == RightNum;
}

int computeSteps(std::string vStr)
{
	if (isCase1(vStr))
		return 1;

	int LeftNum = 0;
	if (isCase2(vStr, LeftNum))
	{
		int Result = 1;
		for (int i=1; i<=LeftNum; ++i)
		{
			Result *= i;
		}
		return Result;
	}

	int Length = vStr.length();
	int LeftIndex = -1;
	int RightIndex = -1;
	for (int i=0; i<Length; ++i)
	{
		if (vStr[i] == '(' && i - LeftIndex == 1)
		{
			LeftIndex++;
		}
	}

	return Length;
}

int main()
{
	std::string Str;
	std::cin >> Str;

	//std::string Str = "(((())))";
	//int Res = computeSteps(Str);
	std::cout << computeSteps(Str) << std::endl;

	return 0;
}