#include <iostream>

bool g_InvalidInput = false;

bool equals(double vNumberA, double vNumberB)
{
	return abs(vNumberA - vNumberB) <= 0.0000001;
}

double powerWithUnsignedExponent(double vBase, unsigned int vExponent)
{
	double Result = 1.0;
	for (unsigned int i=0; i<vExponent; ++i)
	{
		Result *= vBase;
	}
	return Result;
}

double powerWithUnsignedExponent_02(double vBase, unsigned int vExponent)
{
	if (vExponent == 0)
	{
		return 1.0;
	}

	if (vExponent == 1)
	{
		return vBase;
	}

	double Result = powerWithUnsignedExponent_02(vBase, vExponent >> 1);
	Result *= Result;

	if (vExponent & 0x1 == 1)
	{
		Result *= vBase;
	}

	return Result;
}

double power(double vBase, int vExponent)
{
	g_InvalidInput = false;

	if (equals(vBase, 0.0) && vExponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int AbsExponent = vExponent < 0 ? -vExponent : vExponent;
	double Result = powerWithUnsignedExponent(vBase, AbsExponent);
	if (vExponent < 0)
	{
		Result = 1.0 / Result;
	}
	return Result;
}

void test(char* vTestName, double vBase, int vExponent, double vExpectedRes, bool vExpectedFlag)
{
	_ASSERT(vTestName);

	double Result = power(vBase, vExponent);
	if (abs(Result - vExpectedRes) <= 0.00000001 && g_InvalidInput == vExpectedFlag)
	{
		std::cout << vTestName << " pass.\n";
	}
	else
	{
		std::cout << vTestName << " failed.\n";
	}
}

int main()
{
	test("test1", 0.0, -1, 0, true);

	test("test2", 8.0, 0, 1, false);

	test("test3", 2.0, 3, 8.0, false);

	test("test4", 2.0, -3, 0.125, false);

	test("test5", -2.0, 3, -8.0, false);

	test("test6", 0.0, 0, 1, false);

	double Result = powerWithUnsignedExponent_02(2.0, 2);

	return 0;
}