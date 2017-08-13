////https://www.nowcoder.com/test/question/56a487c342a64d2ea4c3a0b0144b42d0?pid=4111169&tid=6839658

#include <iostream>
#include <string>
#include <vector>

int findContinuousEqualLetter(char vLetter, const std::string& vInputStr)
{
	bool Flag = true;
	int EqualNum = 0;
	int Index = 0;
	while (Flag)
	{
		if (vInputStr[Index] == vLetter) //strcmp((const char*)vInputStr[Index], (const char*)vLetter) == 0 运行出错
		{
			EqualNum++;
			Index++;
		}
		else
		{
			Flag = false;
		}
	}
	return EqualNum;
}

void encodeStr(const std::string& vInputStr, std::vector<int>& voNumberSet, std::vector<char>& voLetterSet)
{
	for (unsigned int i=0; i<vInputStr.length(); i++)
	{
		std::string SubString = vInputStr.substr(i+1, vInputStr.length());
		int NumEquals = findContinuousEqualLetter(vInputStr[i], SubString);
		
		voNumberSet.push_back(NumEquals+1);
		voLetterSet.push_back(vInputStr[i]);
	
		i += NumEquals;
	}
}

int main()
{
	std::string TestStr;
	std::cin >> TestStr;
	//std::getline(std::cin, TestStr);这个不行

	std::vector<int> NumberSet;
	std::vector<char> LetterSet;
	encodeStr(TestStr, NumberSet, LetterSet);
	
	for (unsigned int i=0; i<NumberSet.size(); i++)
	{
		std::cout << NumberSet[i] << LetterSet[i];
	}
	return 0;
}