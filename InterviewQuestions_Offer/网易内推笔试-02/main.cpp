#include <iostream>

void sortArray(int vData[], int vLength, int vResult[])
{
	if (vData == NULL || vLength <= 0)
		return;

	int IndexA = vLength - 1;
	int IndexB = 0;
	bool IsFirstVisited = false;

	while (IndexA >= 0)
	{
		vResult[IndexB] = vData[IndexA];
		
		if (IndexA == 0)
		{
			IndexA--;
			IsFirstVisited = true;
		}else
		{
			IndexA -= 2;
		}
		IndexB++;
	}

	if (IsFirstVisited)
	{
		IndexA += 2;
	}
	else
	{
		IndexA++;
	}

	while (IndexA < vLength)
	{
		vResult[IndexB] = vData[IndexA];
		IndexA += 2;
		IndexB++;
	}
}

int main()
{
	int N;

	std::cin >> N;

	int* pArrayData = new int[N];
	for (int i=0; i<N; ++i)
	{
		std::cin >> pArrayData[i];
	}

	int* pResultArray = new int[N];
	sortArray(pArrayData, N, pResultArray);

	for (int i=0; i<N; ++i)
	{
		std::cout << pResultArray[i];
		if (i != N - 1)
		{
			 std::cout << " ";
		}
	}

	delete pArrayData;
	delete pResultArray;

	return 0;
}