#include <crtdbg.h>
#include <iostream>

void merge(int vArray[], int vLeft, int vMiddle, int vRight) // 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
	_ASSERT(vLeft <= vMiddle && vMiddle <= vRight);
	
	int ArrayLength = vRight - vLeft + 1;
	if (ArrayLength <= 1)
		return;

	int* pTempArray = new int[ArrayLength];
	_ASSERT(pTempArray);

	int LeftA = vLeft;
	int LeftB = vMiddle + 1;
	int Index = 0;
	while (LeftA <= vMiddle && LeftB <= vRight)
	{
		pTempArray[Index++] = vArray[LeftA] <= vArray[LeftB] ? vArray[LeftA++] : vArray[LeftB++]; // 带等号保证归并排序的稳定性
	}

	while (LeftA <= vMiddle)
	{
		pTempArray[Index++] = vArray[LeftA++];
	}

	while (LeftB <= vRight)
	{
		pTempArray[Index++] = vArray[LeftB++];
	}

	for (int i=0; i<ArrayLength; ++i)
	{
		vArray[vLeft++] = pTempArray[i]; //error: vArray[i++] = pTempArray[i];
	}
}

void mergesort_recursion(int vArray[], int vLeft, int vRight)
{
	if (vLeft == vRight) // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
	{
		return;
	}

	int Middle = (vLeft + vRight) / 2;
	mergesort_recursion(vArray, vLeft, Middle);
	mergesort_recursion(vArray, Middle + 1, vRight);
	merge(vArray, vLeft, Middle, vRight);
}

void printArray(int vArray[], int vLength)
{
	for (int i=0; i<vLength; ++i)
	{
		std::cout << vArray[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//{72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
	int Data[5] = {72, 6, 57, 88, 60};
	int Length = sizeof(Data) / sizeof(Data[0]);

	mergesort_recursion(Data, 0, Length - 1);

	printArray(Data, Length);

	return 0;
}