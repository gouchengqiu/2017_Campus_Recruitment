#include <vector>
#include <iostream>

//https://www.2cto.com/kf/201603/494797.html

void combination(char* vStr, int vNumber, std::vector<char>& voResult)
{
	if (vNumber == 0)
	{
		for (auto& Data : voResult)
		{
			std::cout << Data;
		}
		return;
	}

	if (*vStr == '\0')
	{
		return;
	}

	voResult.push_back(*vStr);
	combination(vStr + 1, vNumber - 1, voResult);

	voResult.pop_back();
	combination(vStr + 1, vNumber, voResult);
}

void combine(char* vStr/*, int vLength*/)
{
	if (vStr == NULL)
	{
		return;
	}

	int Length = strlen(vStr);
	std::vector<char> Result;
	for (unsigned int i=1; i<=Length; ++i)
	{
		combination(vStr, i, Result);
	}
}

int main()
{
	char Str[] = "abc";
	combine(Str);

	return 0;
}