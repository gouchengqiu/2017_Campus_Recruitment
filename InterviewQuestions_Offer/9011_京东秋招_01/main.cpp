#include <iostream>
#include <string>

bool isSame(const std::string& vStrA, const std::string& vStrB)
{
	int LengthA = vStrA.length();
	int LengthB = vStrB.length();
	if (LengthA != LengthB)
	{
		return false;
	}

	for (unsigned int i=0; i<LengthA; ++i)
	{
		if (vStrA[i] != vStrB[i])
		{
			return false;
		}
	}
	return true;
}

void shortestString(const std::string& vStr)
{
	if (vStr.empty())
		return;

	if (vStr.length() == 1)
	{
		std::string Temp = vStr;
		Temp += vStr;
		std::cout << Temp << std::endl;
		return;
	}

	int TempNum = -1;
	for (int i = 0; i<vStr.length() - 1; ++i)
	{
		std::string TempA = vStr.substr(vStr.length() - 1 - i, i+1);
		std::string TempB = vStr.substr(0, i+1);
		bool bTemp = isSame(TempA, TempB);
		if (isSame(TempA, TempB))
		{
			if (i > TempNum)
			{
				TempNum = i;
			}
		}
	}

	std::string Result = vStr;
	std::string Test = vStr.substr(TempNum + 1, vStr.length() - 1 - TempNum);
	Result += Test;

	std::cout << Result << std::endl;
}

int main()
{
 	std::string ss;
 	std::cin >> ss;
 	shortestString(ss);
	//shortestString("abracadabra");

	return 0;
}