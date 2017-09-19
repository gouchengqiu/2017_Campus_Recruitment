#include <iostream>

//1.快速排序  错误版本
void quickSort_1(int vData[], int vNumData)
{
	if (vNumData <= 1)
	{
		return;
	}
	int TempData = vData[0];
	int* pLargerData = new int[vNumData];
	int* pLessData   = new int[vNumData];
	int NumLarge = 0, NumLess = 0;

	for (int i=1; i<vNumData; i++)
	{
		if (TempData < vData[i])
		{
			pLargerData[NumLarge] = vData[i];
			NumLarge++;
		}
		else
		{
			pLessData[NumLess] = vData[i];
			NumLess++;
		}
	}

	quickSort_1(pLargerData, NumLarge);
	quickSort_1(pLessData, NumLess);

	for (int i=0; i<NumLess; ++i)
	{
		vData[i] = pLessData[i];
	}
	vData[NumLess] = TempData;
	for (int i=0; i<NumLarge; ++i)
	{
		vData[NumLess + 1 + i] = pLargerData[i];
	}
}

//Todo:这个函数实现不能保证完全正确。
void quickSort_2(int vArray[], int vLength)
{
	if (vLength <= 1)
	{
		return;
	}

	int MiddleData = vArray[0];
	int i = 0, j = vLength - 1;

	while (i < j)
	{
		while (i < j && vArray[j] >= MiddleData)  
		{
			--j;
		}
		if (i < j)
		{
			vArray[i] = vArray[j];
			//--j;
			//++i;
		}

		while (i < j && vArray[i] < MiddleData) 
		{
			++i;
		}
		if (i < j)
		{
			vArray[j] = vArray[i];
			//++i;
			//--j;
		}
	}
	vArray[i] = MiddleData;

	quickSort_2(vArray,     i);
	quickSort_2(vArray + i, vLength - 1 - i);
}

//Todo:快排的实现函数还是用这个吧，，，正确的。。。
void quickSort_3(int vArray[], int vStartIndex, int vEndIndex)
{
	if (vStartIndex >= vEndIndex)
	{
		return;
	}

	int i = vStartIndex, j = vEndIndex;
	int Temp = vArray[vStartIndex];

	while (i < j)
	{
		while (i < j && vArray[j] >= Temp)  //while1
		{
			j--;
		}
		if (i < j)
		{
			vArray[i] = vArray[j];
			i++;
		}

		while (i < j && vArray[i] < Temp) //while2     注意：while1和2的顺序不能变，否则会出错。
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

	quickSort_3(vArray, vStartIndex, i - 1);
	quickSort_3(vArray, i + 1, vEndIndex);
}

//Todo: method4
int getRandomInt(int vMin, int vMax)
{
	//float t = (float)(rand()) / RAND_MAX;
	//int Temp = (vMin + (vMax - vMin) * t);
	//return Temp;
	return 0;
}

void swapData(int& vDataA, int& vDataB)
{
	int Temp = vDataA;
	vDataA = vDataB;
	vDataB = Temp;
}

int partition(int vData[], int vLength, int vStartIndex, int vEndIndex)
{
	if (vData == NULL || vLength <= 0 || vStartIndex < 0 || vEndIndex >= vLength)
	{
		throw new std::exception("Invalid Parameters.");
	}

	int Index = getRandomInt(vStartIndex, vEndIndex);
	swapData(vData[Index], vData[vEndIndex]);

	int Small = vStartIndex - 1;
	for (Index=vStartIndex; Index < vEndIndex; ++Index)
	{
		if (vData[Index] < vData[vEndIndex])
		{
			++Small;
			if (Small != Index)
			{
				swapData(vData[Index], vData[Small]);
			}
		}
	}

	++Small;
	swapData(vData[Small], vData[vEndIndex]);

	return Small;
}

void quickSort_4(int vData[], int vLength, int vStartIndex, int vEndIndex)
{
	if (vData == NULL || vLength <= 0 || vStartIndex < 0 || vEndIndex >= vLength)
	{
		throw new std::exception("Invalid Parameters.");
	}

	if (vStartIndex == vEndIndex)
	{
		return;
	}

	int MiddleIndex = partition(vData, vLength, vStartIndex, vEndIndex);
	if (MiddleIndex > vStartIndex)
	{
		quickSort_4(vData, vLength, vStartIndex, MiddleIndex - 1);
	}

	if (MiddleIndex < vEndIndex)
	{
		quickSort_4(vData, vLength, MiddleIndex + 1, vEndIndex);
	}
}

//2. 冒泡排序
void bubbleSort(int vData[], int vNumData)
{
	for (int i=0; i<vNumData; ++i)
	{
		for (int k=0; k<vNumData -1 - i; ++k)
		{
			if (vData[k] > vData[k+1])
			{
				int Temp = vData[k];
				vData[k] = vData[k+1];
				vData[k+1] = Temp;
			}
		}
	}
}

#include <vector>

int main()
{
	//int Data[10] = { 5, 1, 3, 9, 2, 4, 7, 6, 8, 0};
	//quickSort_1(Data, 10);

	int Data[10] = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
	//quickSort_2(Data, 10); //error
	quickSort_3(Data, 0, 9);
	//int Data[5] = {3, 5, 4, 2, 1};
	//bubbleSort(Data, 5);

	for (int i=0; i<10; ++i)
	{
		std::cout << Data[i] << " ";
	}

	//int Data[5] = {3, 1, 2, 9, 5};
	//quickSort_4(Data, 5, 0, 4);
	//
	//for (int i=0; i<10; ++i)
	//{
	//	std::cout << Data[i] << " ";
	//}
	char* p = nullptr;
	char a[10] = {' '};
	p = &a[0];
	system("pause");

	return 0;
}