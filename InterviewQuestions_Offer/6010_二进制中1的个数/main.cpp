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
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	Test(-1, 2);//����������  ���ղ����������-1�Ĳ���
	Test(0x80000001, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);

	return 0;
}