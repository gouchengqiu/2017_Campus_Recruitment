#include <iostream>

int numOfBit1(int n)
{
	int Count = 0;
	while (n)
	{
		Count++;
		n = n&(n-1);
	}
}

void Test(int number, unsigned int expected)
{
	int actual = numOfBit1(number);
	if(actual == expected)
		std::cout << "Test for " << number << "passed.\n";
	else
	    std::cout << "Test for " << number << "failed.\n";
}

int main()
{
	// 输入0，期待的输出是0
	Test(0, 0);

	// 输入1，期待的输出是1
	Test(1, 1);

	// 输入10，期待的输出是2
	Test(10, 2);

	Test(-1, 2);//这样的输入  最终参与运算的是-1的补码
	Test(0x80000001, 2);

	// 输入0x7FFFFFFF，期待的输出是31
	Test(0x7FFFFFFF, 31);

	// 输入0xFFFFFFFF（负数），期待的输出是32
	Test(0xFFFFFFFF, 32);

	// 输入0x80000000（负数），期待的输出是1
	Test(0x80000000, 1);

	return 0;
}