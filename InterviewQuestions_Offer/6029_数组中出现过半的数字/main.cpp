#include <iostream>
#include <random>
#include <exception>

bool g_bInputInvalid = false;

int randomInRange(int vMin, int vMax)
{
	int Random = rand() % (vMax - vMin + 1) + vMin;
	return Random;
}

void swap(int& voDataA, int& voDataB)
{
	int Temp = voDataA;
	voDataA = voDataB;
	voDataB = Temp;
}

int partition(int vData[], int vLength, int vStart, int vEnd)
{
	if (vData == NULL || vLength <= 0 || vStart < 0 || vEnd > vLength)
	{
		throw new std::exception("Invalid parameters.");
	}

	int Index = randomInRange(0, vLength - 1);
	swap(vData[Index], vData[vEnd]);
	int Small = -1;
	int Temp = vData[vEnd];

	for (int i=vStart; i<vEnd; ++i)
	{
		if (vData[i] < Temp)
		{
			Small++;
			if (Small != i)
			{
				swap(vData[i], vData[Small]);
			}
		}
	}

	Small++;
	swap(vData[Small], vData[vEnd]);
	return Small;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for(int i = 0; i < length; ++i)
	{
		if(numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	if(times * 2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

int numberMoreThanHalf_01(int vData[], int vLength)
{
	if (vData == 0 || vLength <= 0)
	{
		g_bInputInvalid = true;
		return 0;
	}

	int Middle = vLength >> 1;
	int Index = partition(vData, vLength, 0, vLength - 1);
	
	while (Index != Middle)
	{
		if (Index > Middle)
		{
			Index = partition(vData, vLength, 0, Index - 1);
		}
		else
		{
			Index = partition(vData, vLength, Index + 1, vLength - 1);
		}
	}

	int Result = vData[Middle];
	if (!CheckMoreThanHalf(vData, vLength, Result))
	{
		return 0;
	}

	return Result;
}

int numberMoreThanHalf_02(int vData[], int vLength)
{
	g_bInputInvalid = false;
	if (vData == NULL || vLength <= 0)
	{
		g_bInputInvalid = true;
		return 0;
	}

	int TempRecord[2] = {0, 0};
	for (unsigned int i=0; i<vLength; ++i)
	{
		if (TempRecord[1] == 0)
		{
			TempRecord[0] = vData[i];
			TempRecord[1] = 1;
		}
		else
		{
			bool Temp = TempRecord[0] == vData[i];
			if (TempRecord[0] == vData[i])
			{
				TempRecord[1] += 1;
			}
			else
			{
				TempRecord[1] -= 1;
			}
			//TempRecord[1] = (TempRecord[0] == vData[i]) ? TempRecord[1]++ : TempRecord[1]--;
		}
	}

	int Result = TempRecord[0];
	if (!CheckMoreThanHalf(vData, vLength, Result))
		return 0;

	return Result;
}

int main()
{
	int Data[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	int Result = numberMoreThanHalf_02(Data, sizeof(Data)/sizeof(Data[0]));

	return 0;
}