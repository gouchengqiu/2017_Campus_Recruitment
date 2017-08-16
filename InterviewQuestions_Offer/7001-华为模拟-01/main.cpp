#include <iostream>
#include <string>

bool isNumber(const char* vNumber)
{
	std::string NumStr(vNumber);

	//bool Test = std::string::npos == NumStr.find_first_not_of("0123456789");
	return std::string::npos == NumStr.find_first_not_of("0123456789");
}

long int computeLength(const char* vNumber)
{
	if (vNumber == NULL)
	{
		return 0;
	}

	long int Length0 = 0;
	while (vNumber[Length0] != '\0')
	{
		Length0++;
	}

	return Length0;
}

bool isLegalInput(const char* vNumber0, const char* vNumber1)
{
	if (vNumber0 == NULL || vNumber1 == NULL)
	{
		return false;
	}

// 	long int Length0 = computeLength(vNumber0);
// 	long int Length1 = computeLength(vNumber1);
	if (computeLength(vNumber0) != computeLength(vNumber1))
	{
		return false;
	}

	return isNumber(vNumber0) && isNumber(vNumber1);
}

long int findMatch(const char* vNumber0, const char* vNumber1)
{
	if (vNumber0 == NULL || vNumber1 == NULL)
	{
		return -1;
	}

	if (!isLegalInput(vNumber0, vNumber1))
	{
		return -1;
	}

	long int Length = computeLength(vNumber0);
	long int MaxLength = 0, Temp = 0;

	for (long int i=0; i<Length; ++i)
	{
		if (vNumber0[i] == vNumber1[i])
		{
			Temp++;
		}
		else
		{
			MaxLength = std::max(Temp, MaxLength);
			Temp = 0; //ÎÒºÃÉµ±Æ°¡°¡°¡°¡°¡°¡°¡
		}
	}

	MaxLength = std::max(Temp, MaxLength);
	return MaxLength == 1 ? 0 : MaxLength;
}

int main()
{
	std::string DataA, DataB;

	std::cin >> DataA >> DataB;

	std::cout << findMatch(DataA.c_str(), DataB.c_str());

	return 0;
}