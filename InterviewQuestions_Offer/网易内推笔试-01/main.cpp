#include <iostream>
#include <string>
#include <map>

int computeNum(const std::string& vStr)
{
	int Length = vStr.length();
	if (Length <= 1)
	{
		return Length;
	}
	
	std::map<char, char> CharMap;
	for (int i=0; i<Length; ++i)
	{
		CharMap.insert(std::make_pair(vStr[i], vStr[i]));
	}

	int Result = 0;
	if (CharMap.size() <= 2)
	{
		Result = CharMap.size();
	}
	else
	{
		Result = 0;
	}
	return Result;
}

int main()
{
	std::string Str;
	std::cin >> Str;

	std::cout << computeNum(Str);
}