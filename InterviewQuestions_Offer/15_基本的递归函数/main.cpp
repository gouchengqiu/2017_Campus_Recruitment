#include <iostream>

//NµÄ½×³Ë
int jiecheng(unsigned int vNumber)
{
	if (vNumber == 0)
	{
		return 1;
	}
	else
	{
		return vNumber*jiecheng(vNumber-1);
	}
}

int fibonacci(unsigned int vNumber)
{
	if (vNumber == 0 || vNumber == 1)
	{
		return vNumber;
	}
	else
	{
		return fibonacci(vNumber-1) + fibonacci(vNumber-2);
	}
}

//NµÄ½×³Ë
int main()
{
	//int N = 3;
	//int JiechengResult = jiecheng(N);

	//int FibonacciResult = fibonacci(N);
	char a = 101;
	a += 27;
	int b = a;

	return 0;
}