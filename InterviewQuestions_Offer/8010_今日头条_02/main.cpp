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
		while (i < j && vArray[j] < Temp)
		{
			j--;
		}
		if (i < j)
		{
			vArray[i] = vArray[j];
			i++;
		}

		while (i < j && vArray[i] >= Temp)
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


long int computeMax(long int* vDataArray, long int vLength)
{
	if (vLength == 1)
	{
		return vDataArray[0] * vDataArray[0];
	}

	quickSort(vDataArray, 0, vLength - 1);

	long int MaxSum = vDataArray[0] * vDataArray[0];
	long int Num = 2;

	while (Num <= vLength)
	{
		long int TempSum = 0;
		for (long int i=0; i<Num; ++i)
		{
			TempSum += vDataArray[i];
		}
		TempSum *= vDataArray[Num - 1];

		if (TempSum > MaxSum)
		{
			MaxSum = TempSum;
		}

		Num++;
	}

	return MaxSum;
}

int main()
{
	long int Length;
	std::cin >> Length;

	long int* pDataArray = new long int[Length]();

	for (long int i=0; i<Length; ++i)
	{
		std::cin >> pDataArray[i];
	}

	std::cout << computeMax(pDataArray, Length);

	delete[] pDataArray;

	return 0;
}