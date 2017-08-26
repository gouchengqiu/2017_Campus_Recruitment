#include <iostream>

int main()
{
	int S, V1, V2, T;
	std::cin >> S >> V1 >> V2 >> T;

	int Length1 = V1 * T;
	int Length2 = V2 * T;

	if (Length1 < S || Length2 < S)
	{
		std::cout << 0; 
	}
	else
	{
		int MinLength = Length1 < Length2 ? Length1 : Length2;
		int MaxLength = Length1 > Length2 ? Length1 : Length2;

		int Diff = MaxLength - MinLength;

		if (Diff < S)
		{
			std::cout << 0;
		}
		else
		{
			int Res = (MaxLength - S) / (2 * S) + 1;
			std::cout << Res;
		}
	}

	return 0;
}