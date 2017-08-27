#include <iostream>

void quickSort(long int vArray[], long int vLeft, long int vRight)
{
	if (vLeft >= vRight)
	{
		return;
	}

	long int i = vLeft, j = vRight;
	long int Temp = vArray[vLeft];

	while (i < j)
	{
		while (i < j && vArray[j] >= Temp)
		{
			j--;
		}
		if (i < j)
		{
			vArray[i] = vArray[j];
			i++;
		}

		while (i < j && vArray[i] < Temp)
		{
			i++;
		}
		if (i < j)
		{
			vArray[j] = vArray[i];
			j--;
		}
	}

	vArray[i] = Temp;

	quickSort(vArray, vLeft, i - 1);
	quickSort(vArray, i + 1, vRight);
}

long int maxMultiplier(long int vArray[], long int vNum)
{
// 	if (vArray[0] >= 0)
// 	{
// 		return vArray[vNum - 1] * vArray[vNum - 2] * vArray[vNum - 3];
// 	}
// 
// 	if (vArray[vNum - 1] <= 0)
// 	{
// 		return vArray[0] * vArray[1] * vArray[2];
// 	}

	long int ResultA = vArray[vNum - 1] * vArray[vNum - 2] * vArray[vNum - 3];
	long int ResultB = vArray[0] * vArray[1] * vArray[2];
	long int ResultC = vArray[0] * vArray[1] * vArray[vNum - 1];

	long int Result = ResultA < ResultB ? ResultB : ResultA;
	return Result < ResultC ? ResultC : Result;
}

int main()
{
	long int N;
	std::cin >> N;

	long int* pArray = new long int[N];
	for (long int i=0; i<N; ++i)
	{
		std::cin >> pArray[i];
	}

	quickSort(pArray, 0, N - 1);

	std::cout << maxMultiplier(pArray, N);

	delete[] pArray;

	return 0;
}