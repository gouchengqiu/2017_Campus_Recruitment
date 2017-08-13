#include <iostream>

int addFrom1ToN_Recursive(int vNumber)
{
	return vNumber <= 0 ? 0 : vNumber + addFrom1ToN_Recursive(vNumber - 1);
}

int addFrom1ToN_Iterative(int vNumber)
{
	int Result = 0;
	for (int i=1; i<=vNumber; ++i)
	{
		Result += i;
	}
	return Result;
}

int main()
{
	int N1 = 10;
	int Result11 = addFrom1ToN_Recursive(N1);
	int Result12 = addFrom1ToN_Iterative(N1);

	int N2 = 5000;
	int Result21 = addFrom1ToN_Recursive(N2);
	int Result22 = addFrom1ToN_Iterative(N2);

	return 0;
}