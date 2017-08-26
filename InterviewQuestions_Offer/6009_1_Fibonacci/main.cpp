#include <iostream>

int fibonacci(unsigned int vNumber)
{
	if (vNumber == 0 || vNumber == 1)
	{
		return vNumber;
	}

	int Temp1 = 0, Temp2 = 1;
	int Result = 0;
	for (unsigned int i=2; i<=vNumber; ++i)
	{
		Result = Temp1 + Temp2;
		Temp1 = Temp2;
		Temp2 = Result;
	}
	return Result;
}

void test(int vNumber, int vExcepted)
{
	if (vNumber < 0)
	{
		throw std::exception("Input error.");
	}

	if (fibonacci(vNumber) == vExcepted)
	{
		std::cout << "Test pass.\n";
	}
	else
	{
		std::cout << "Test failed.\n";
	}
}

int main()
{
	test(0, 0);
	test(1, 1);
	test(2, 1);
	test(3, 2);
	test(5, 5);
	test(10, 55);
	test(40, 102334155);

	return 0;
}