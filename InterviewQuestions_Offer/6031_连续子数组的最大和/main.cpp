#include <iostream>

int maxSum(int vData[], int vLength)
{
	//if (vData == NULL || vLength <= 0)
	//{
	//	
	//}

	int MaxSum = FLT_MIN;
	int Temp = 0;
	for (unsigned int i=0; i<vLength; ++i)
	{
		if (vData[i] < 0 && vData[i] + Temp < 0)
		{
			Temp = 0;
		}
		else
		{
			Temp += vData[i];
			MaxSum = Temp < MaxSum ? MaxSum : Temp;
		}
	}

	return MaxSum;
}

int main()
{
	int N;
	std::cin >> N;

	int* pData = new int[N];
	for (unsigned int i=0; i<N; ++i)
	{
		std::cin >> pData[i];
	}

	std::cout << maxSum(pData, N) << std::endl;
	
	delete[] pData;

	return 0;
}