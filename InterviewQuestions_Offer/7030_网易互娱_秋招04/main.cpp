#include <string>
#include <stack>
#include <iostream>

bool isExistKuohao(const std::string& vStr)
{
	for (unsigned int i=0; i<vStr.length(); ++i)
	{
		if (vStr[i] == '{' || vStr[i] == '}')
		{
			return true;
		}
	}
	return false;
}

int getRightKuoHaoIndex(const std::string& vStr)
{
	int RightKuoHaoIndex = -1;
	int FrontNum = 0;
	int BackNum = 0;
	for (unsigned int i=1; i<vStr.length(); ++i)
	{
		if (vStr[i] == '{')
		{
			FrontNum++;
		}
		else if (vStr[i] == '}')
		{
			if (FrontNum == 0)
			{
				RightKuoHaoIndex = i;
				break;
			}
			else
			{
				BackNum++;
				if (FrontNum == BackNum)
				{
					FrontNum = 0;
					BackNum = 0;
				}
			}
		}
	}

	return RightKuoHaoIndex;
}

void compressStr(const std::string& vStr, unsigned int vTimes, std::string& voOutStr)
{
	if (!isExistKuohao(vStr))
	{
		std::string Temp;
		for (unsigned int i=0; i<vTimes; ++i)
		{
			Temp += vStr;
		}
		voOutStr += Temp;
		return;
	}

	int Times = vStr[0] - '0';
	std::string TempStr = vStr.substr(1, vStr.length() - 1);
	int RightIndex = getRightKuoHaoIndex(TempStr) ;

	if (RightIndex == TempStr.length() - 1)
	{
		compressStr(TempStr.substr(1, TempStr.length() - 2), Times * vTimes, voOutStr);
	}
	else
	{
		std::string FrontStr = TempStr.substr(1, RightIndex - 1);
		std::string BackStr = TempStr.substr(RightIndex + 1, TempStr.length() - 1 - RightIndex);
		compressStr(FrontStr, Times, voOutStr);
		compressStr(BackStr, 1, voOutStr);

		for (unsigned int i=1; i<vTimes; ++i)
		{
			voOutStr += voOutStr;
		}
	}
}

int main()
{
	std::string InputStr;
	std::cin >> InputStr;

	std::string Res;
	compressStr(InputStr, 1, Res);
	std::cout << Res << std::endl;

	return 0;
}