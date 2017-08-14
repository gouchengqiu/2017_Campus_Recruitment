#include <iostream>

void fun(bool** voTestArray)
{
	voTestArray = new bool*[10];

	for (unsigned int i=0; i<10; i++)
	{
		voTestArray[i] = new bool[5];
	}

	for (unsigned int i=0; i<10; i++)
	{
		for (unsigned int k=0; k<5; k++)
		{
			voTestArray[i][k] = i*10 + k;
		}
	}
}

int main()
{
	bool** Test;
	fun(Test);

	for (unsigned int i=0; i<10; i++)
	{
		for (unsigned int k=0; k<5; k++)
		{
			std::cout << Test[i][k] << ", ";
		}
		std::cout << std::endl;
	}
}