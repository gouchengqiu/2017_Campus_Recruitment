#include <iostream>
#include <set>

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

	int Index = randomInRange(vStart, vEnd);
	swap(vData[Index], vData[vEnd]);
	int Small = vStart - 1;
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

void getLeastNumbers_01(int vData[], int vLength, int voResult[], int vK)
{
	if (vData == NULL || voResult == NULL || vK >vLength || vLength <= 0 || vK <= 0)
	{
		return;
	}

	int Start = 0;
	int End = vLength - 1;
	int Index = partition(vData, vLength, Start, End);

	while (Index != vK - 1)
	{
		if (Index > vK - 1)
		{
			End = Index - 1;
			Index = partition(vData, vLength, Start, End);
		}
		else
		{
			Start = Index + 1;
			Index = partition(vData, vLength, Start, End);
		}
	}

	for (int i=0; i<vK; ++i)
	{
		voResult[i] = vData[i];
		std::cout << voResult[i] << " ";
	}
}

struct SCMP
{
	bool operator()(int vA, int vB) {return vA > vB;}
};

// ·½·¨2
void getLeastNumbers_02(int vData[], int vLength, std::multiset<int, SCMP>& voResultSet, int vK)
{
	if (vData == NULL || vLength <= 0 || vK > vLength)
	{
		return;
	}

	voResultSet.clear();
	for (int i=0; i<vLength; ++i)
	{
		if (voResultSet.size() < vK)
		{
			voResultSet.insert(vData[i]);
		}
		else
		{

			if (vData[i] < *(voResultSet.begin()))
			{
				voResultSet.erase(voResultSet.begin());
				voResultSet.insert(vData[i]);
			}
		}

		//std::cout << std::endl;
		//std::multiset<int, SCMP>::iterator Iter = voResultSet.begin();
		//for (; Iter!=voResultSet.end(); ++Iter)
		//{
		//	std::cout << *Iter << " ";
		//}
		//std::cout << std::endl;
	}
}

int main()
{
	int Data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	int Result[8];

	//getLeastNumbers_01(Data, 8, Result, 4);

	std::multiset<int, SCMP> ResultSet;
	getLeastNumbers_02(Data, 8, ResultSet, 4);

	std::multiset<int, SCMP>::iterator Iter = ResultSet.begin();
	for (; Iter!=ResultSet.end(); ++Iter)
	{
		std::cout << *Iter << " ";
	}

	return 0;
}