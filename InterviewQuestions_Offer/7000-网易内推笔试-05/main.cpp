//https://www.nowcoder.com/test/question/done?tid=9944519&qid=112725#summary

#include <iostream>
#include <string>
#include <cmath>

int maxSuccessive(const std::string& vStr)
{
	int Length = vStr.length();
	if (Length <= 1)
		return Length;

	int Max = 0, Temp = 0;
	for (unsigned int i=0; i<Length-1; ++i)
	{
		if (vStr[i] != vStr[i+1])
		{
			Temp++;
		}else
		{
			Max = std::max(Max, Temp);
			Temp = 0;
		}
	}

	Max = std::max(Max, Temp);
	return Max + 1;
}

int main()
{
	std::string Str;
	std::cin >> Str;

	std::cout << maxSuccessive(Str);
}