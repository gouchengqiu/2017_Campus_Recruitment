#include <iostream>
#include <exception>

int minInOrder(int* vArray, int vStartIndex, int vEndIndex)
{
	if (vArray == NULL || vStartIndex < 0 || vEndIndex < 0 || (vEndIndex - vStartIndex) <= 0)
	{
		throw std::exception("Input error.");
	}

	int Result = vArray[vStartIndex];
	for (unsigned int i=vStartIndex+1; i<=vEndIndex; ++i)
	{
		if (vArray[i] < Result)
		{
			Result = vArray[i];
		}
	}

	return Result;
}

int searchMinData(int* vArray, int vLength)
{
	if (vArray == NULL || vLength <= 0)
	{
		throw std::exception("Input error.");
	}

	if (vLength == 1)
	{
		return vArray[0];
	}

	int i = 0, j = vLength - 1;
	while (j - i > 1)
	{
		int MiddleIndex = floor((i + j) / 2);
		if (vArray[MiddleIndex] > vArray[i])
		{
			i = MiddleIndex;
		}

		if (vArray[MiddleIndex] == vArray[i] && vArray[MiddleIndex] == vArray[j])//我遗漏的情况
		{
			return minInOrder(vArray, i, j);
		}

		if (vArray[MiddleIndex] < vArray[j])
		{
			j = MiddleIndex;
		}
	}

	if (j - i == 1)
	{
		return vArray[i] < vArray[j] ? vArray[i] : vArray[j];
	}

	if (j == i)
	{
		return vArray[i];
	}
}

void test(char* vStr, int* vArray, int vLength, int vExcepted)
{
	_ASSERT(vStr);
	std::cout << std::endl << vStr << " begins: \n";

	int Result = 0;
	try
	{
		Result = searchMinData(vArray, vLength);
		for (unsigned int i=0; i<vLength; ++i)
		{
			std::cout << vArray[i] << " ";
		}

		std::cout << "\nResult min data: " << Result << std::endl; 
		if (Result == vExcepted)
		{
			std::cout << "Test passed.\n";
		}else
		{
			std::cout << "Test failed.\n";
		}
	}
	catch(...)
	{
		if (vArray == NULL)
		{
			std::cout << "Test passed.\n";
		}
		else
		{
			std::cout << "Test failed.\n";
		}
	}
}

    // 典型输入，单调升序的数组的一个旋转
void test1()
{
	const int Length = 5;
	int RotateArray[Length] = {3, 4, 5, 1, 2};
	test("test1", RotateArray, Length, 1);
}

// 有重复数字，并且重复的数字刚好的最小的数字
void test2()
{
	const int Length = 6;
	int RotateArray[Length] = {3, 4, 5, 1, 1, 2};
	test("test2", RotateArray, Length, 1);
}

  // 有重复数字，但重复的数字不是第一个数字和最后一个数字
void test3()
{
	const int Length = 6;
	int RotateArray[Length] = {3, 4, 5, 1, 2, 2};
	test("test3", RotateArray, Length, 1);
}

void test4()
{
	const int Length = 5;
	int RotateArray[Length] = {1, 0, 1, 1, 1};
	test("test4", RotateArray, Length, 0);
}

void test41()
{
	const int Length = 9;
	int RotateArray[Length] = {1, -2, -1, 0, 1, 1, 1, 1, 1};
	test("test41", RotateArray, Length, -2);
}

void test5()
{
	const int Length = 1;
	int RotateArray[Length] = {1};
	test("test5", RotateArray, Length, 1);
}

void test6()
{
	test("test6", NULL, 0, 0);
}

void test7()
{
	const int Length = 5;
	int RotateArray[Length] = {1, 2, 3, 4, 5};
	test("test7", RotateArray, Length, 1);
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();//
	//test41();
	//test5();
	//test6();
	test7();

	return 0;
}