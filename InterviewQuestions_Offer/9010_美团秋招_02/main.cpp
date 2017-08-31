#include <iostream>

void quickSort(long int vArray[], int vLeft, int vRight)
{
	if (vLeft >= vRight)
	{
		return;
	}

	int i = vLeft, j = vRight;
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

bool isExistSequence(long int vData[], int vLength)
{
	if (vData == NULL || vLength <= 1)
	{
		return false;
	}

	if (vLength == 2)
	{
		return vData[0] == vData[1];
	}

	quickSort(vData, 0, vLength - 1);
	return vData[vLength - 1] == vData[vLength - 2];
}

int main()
{
	int N;
	std::cin >> N;

	long int* pData = new long int[N];
	for (unsigned int i=0; i<N; ++i)
	{
		std::cin >> pData[i];
	}

	bool Res = isExistSequence(pData, N);

	if (Res)
	{
		std::cout << "Yes\n";
	}
	else
	{
		std::cout << "No\n";
	}

	delete[] pData;
	return 0;
}