#include <iostream>
#include <unordered_map>
#include <vector>

int Testi = 4;
int Testj = 5;
int Row = 7;

bool TwoDimensionArray[7][7] = {
	{0, 1, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0}, 
	{1, 1, 0, 1, 1, 0, 0},
	{1, 1, 1, 0, 1, 0, 0},
	{0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 1, 0}
};

//int Testi = 0;
//int Testj = 2;

//int Row = 4;
//bool TwoDimensionArray[4][4] = {
//	{0, 1, 0, 0},
//	{1, 0, 1, 0}, 
//	{0, 1, 0, 0},
//	{0, 0, 0, 0},
//};

bool isVisible(int vSrcIndex, int vDstIndex)
{
	return true;
}

int main()
{
	std::vector<int> DisjointSet(Row, -1);
	for (unsigned int i=0; i<Row; ++i)
	{
		if (DisjointSet[i] == -1)
		{
			DisjointSet[i] = i;
		}

		for (unsigned int k=i+1; k<Row; ++k)
		{
			if (TwoDimensionArray[i][k])
			{
				if (DisjointSet[k] = -1)
				{
					DisjointSet[k] = DisjointSet[i];
				}
				else
				{
					int RootA = k;
					while (DisjointSet[RootA] != RootA)
					{
						RootA = DisjointSet[RootA];
					}

					int RootB = i;
					while (DisjointSet[RootB] != RootB)
					{
						RootB = DisjointSet[RootB];
					}

					if (RootA != RootB)
					{
						DisjointSet[RootA] = RootB;
					}

					DisjointSet[k] = RootB;
				}
			}
		}
	}

	std::unordered_map<int, int> IndexMap;
	for (unsigned int i=0; i<DisjointSet.size(); ++i)
	{
		int k = i;
		while (DisjointSet[k] != k)
		{
			k = DisjointSet[k];
		}

		DisjointSet[i] = k;
		if (IndexMap.find(k) == IndexMap.end())
		{
			IndexMap.insert(std::make_pair(k, 0));
			IndexMap[k] = IndexMap.size() - 1;
		}
	}

	std::vector<std::vector<int>> ResultSet(IndexMap.size());
	for (unsigned int i=0; i<Row; ++i)
	{
		int Index = IndexMap[DisjointSet[i]];
		ResultSet[Index].push_back(i);
	}

	bool ExistI = false;
	bool ExistJ = false;
	for (unsigned int i=0; i<ResultSet.size(); ++i)
	{
		std::vector<int> SameGroup = ResultSet[i];
		for (unsigned int k=0; k<SameGroup.size(); ++k)
		{
			if (SameGroup[k] == Testi)
			{
				ExistI = true;
			}
			if (SameGroup[k] == Testj)
			{
				ExistJ = true;
			}
		}
	}

	if (ExistI && ExistJ)
	{
		std::cout << Testi << " and " << Testj << " are in the same group. \n";
	}
}