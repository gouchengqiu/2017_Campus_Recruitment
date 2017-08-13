#include <iostream>

//1. 直接选择排序
void easySelectSort(int vData[], int vNumData)
{
	for (int i=0; i<vNumData; ++i)
	{
		int MinIndex = i;
		for (int k=i+1; k<vNumData; ++k)
		{
			if (vData[MinIndex] > vData[k])
			{
				MinIndex = k;
			}
		}
		if (MinIndex != i)
		{
			int Temp = vData[MinIndex];
			vData[MinIndex] = vData[i];
			vData[i] = Temp;
		}
	}
}

void merge(int vArrayA[], int vLengthA, int vArrayB[], int vLengthB, int vResult[])
{
	int i = 0, j = 0, ResultIndex = 0;

	while (i < vLengthA && j < vLengthB)
	{
		if (vArrayA[i] <= vArrayB[j])
		{
			vResult[ResultIndex++] = vArrayA[i];
			++i;
		}

		if (vArrayB[j] <= vArrayA[i])
		{
			vResult[ResultIndex++] = vArrayB[j];
			++j;
		}
	}

	if (i < vLengthA)
	{
		for (int k=i; k<vLengthA; ++k)
		{
			vResult[ResultIndex++] = vArrayA[k];
		}
	}

	if (j < vLengthB)
	{
		for (int k=j; k<vLengthB; ++k)
		{
			vResult[ResultIndex++] = vArrayB[k];
		}
	}
}

void mergeNew(int vArray[], int vResult[], int vStartIndex, int vMiddleIndex, int vEndIndex)
{
	int i = vStartIndex;
	int j = vMiddleIndex + 1;
	int k = vStartIndex;

	while (i <= vMiddleIndex && j <= vEndIndex)
	{
		if (vArray[i] <= vArray[j])
		{
			vResult[k++] = vArray[i];
			++i;
		}

		if (vArray[j] <= vArray[i])
		{
			vResult[k++] = vArray[j];
			++j;
		}
	}

	if (i <= vMiddleIndex)
	{
		for (unsigned int m=i; m<=vMiddleIndex; ++m)
		{
			vResult[k++] = vArray[m];
		}
	}

	if (j <= vEndIndex)
	{
		for (unsigned int m=j; m<=vEndIndex; ++m)
		{
			vResult[k++] = vArray[m];
		}
	}
}

//2. 二路归并排序
void mergesort(int vArray[], int vResult[], int vStartIndex, int vEndIndex)
{
	//if (vStartIndex == vEndIndex)
	//{
	//	vResult[vStartIndex] = vArray[vStartIndex];
	//	return;
	//}

	//if (vStartIndex > vEndIndex)
	//{
	//	return;
	//}

	//int TempArray[100];
	//int MiddleIndex = floor((vEndIndex + vStartIndex)/2);
	//mergesort(vArray, TempArray, vStartIndex, MiddleIndex);
	//mergesort(vArray, TempArray, MiddleIndex + 1, vEndIndex);
	//mergeNew(TempArray, vResult, vStartIndex, MiddleIndex, vEndIndex);

	if (vStartIndex == vEndIndex)
	{
		vResult[vStartIndex] = vArray[vStartIndex];
	}
	else
	{
		int TempArray[100];
		int MiddleIndex = floor((vEndIndex + vStartIndex)/2);
		mergesort(vArray, TempArray, vStartIndex, MiddleIndex);
		mergesort(vArray, TempArray, MiddleIndex + 1, vEndIndex);
		mergeNew(TempArray, vResult, vStartIndex, MiddleIndex, vEndIndex);
	}
}

void test1()
{
	//int Data[10] = {9, 1, 3, 5, 2, 4, 7, 6, 8, 0};
	//easySelectSort(Data, 10);
	//for (int i=0; i<10; ++i)
	//{
	//	std::cout << Data[i] << " ";
	//}
}

void test2()
{
	int ArrayA[] = {1, 3, 5, 7, 9};
	int ArrayB[] = {2, 4, 8};
	int Array[100];

	int LengthA = sizeof(ArrayA)/sizeof(ArrayA[0]);
	int LengthB = sizeof(ArrayB)/sizeof(ArrayB[0]);
	merge(ArrayA, LengthA, ArrayB, LengthB, Array);

	for (unsigned int i=0; i<LengthA+LengthB; ++i)
	{
		std::cout << Array[i] << " ";
	}
}

void test3()
{
	const int Length = 7;
	int Array[Length] = {49, 38, 65, 97, 76, 13, 27};
	int Result[Length];
	mergesort(Array, Result, 0, Length - 1);

	for (unsigned int i=0; i<Length; ++i)
	{
		std::cout << Result[i] << " ";
	}
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
} 