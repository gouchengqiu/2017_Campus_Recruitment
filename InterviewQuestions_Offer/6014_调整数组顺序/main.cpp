#include <iostream>

void changeOrder(int vData[], int vNumber)
{
	if (vData == NULL || vNumber <= 0)
	{
		return;
	}

	int i=0, j=vNumber-1;
	while (i < j)
	{
		while (i < j && vData[i] % 2 == 1)
		{
			i++;
		}

		while (i < j && vData[j] % 2 == 0)
		{
			j--;
		}

		if (i < j)
		{
			int Temp = vData[i];
			vData[i] = vData[j];
			vData[j] = Temp;
			i++;
			j--;
		}
	}
}

void printData(int vData[], int vNumber)
{
	if (vData == NULL || vNumber <= 0)
	{
		return;
	}

	for (int i=0; i<vNumber; ++i)
	{
		std::cout << vData[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int Data[] = {1, 2, 3, 4, 5, 6, 7};//1, 2, 3, 4, 5, 6, 7 //2, 4, 6, 1, 3, 5, 7 // 1, 3, 5, 7, 2, 4, 6 // 
	int Length = sizeof(Data)/sizeof(int);
	changeOrder(Data, Length);
	printData(Data, Length);

	return 0;
}