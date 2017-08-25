#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

void connect(int** vMatrx, int N, std::vector<int>& voDisjiontSet)
{
	voDisjiontSet.resize(N);
	for (unsigned int i=0; i<N; ++i)
	{
		voDisjiontSet[i] = -1;
	}

	for (unsigned int i=0; i<N; ++i)
	{
		if (voDisjiontSet[i] == -1)
		{
			voDisjiontSet[i] = i;
		}

		for (unsigned int k=i+1; k<N; ++k)
		{
			if (vMatrx[i][k] == 1)
			{
				if (voDisjiontSet[k] == -1)
				{
					voDisjiontSet[k] = voDisjiontSet[i];
				}
				else
				{
					int RootA = k;
					while (voDisjiontSet[RootA] != RootA)
					{
						RootA = voDisjiontSet[RootA];
					}

					int RootB = i;
					while (voDisjiontSet[RootB] != RootB)
					{
						RootB = voDisjiontSet[RootB];
					}

					if (RootA != RootB)
					{
						voDisjiontSet[RootA] = RootB;
					}
				}
			}
		}
	}
}

int main()
{
	int N;
	std::cin >> N;
	std::cin >> N;

	int** ppMatrix = new int*[N];
	std::string TempStr;
	for (unsigned int i=0; i<N; ++i)
	{
		ppMatrix[i] = new int[N];

		std::cin >> TempStr;

		int Pos = TempStr.find(',');
		while (Pos != std::string::npos)
		{
			TempStr.replace(Pos, 1, 1, ' ');
			Pos = TempStr.find(',');
		}

		std::stringstream SS;
		SS << TempStr;

		int Col = 0;
		while (SS)
		{
			int Test;
			SS >> Test;
			ppMatrix[i][Col++] = Test;
			//SS >> ppMatrix[i][Col++];
		}

		TempStr.clear();
	}

	//for (unsigned int i=0; i<N; ++i)
	//{
	//	for (unsigned int k=0; k<N; ++k)
	//	{
	//		std::cin >> ppMatrix[i][k];
	//	}
	//}

	std::vector<int> DisjiontSet;
	connect(ppMatrix, N, DisjiontSet);

	std::map<int, int> ResultMap;
	for (unsigned int i=0; i<DisjiontSet.size(); ++i)
	{
		int k=i;
		while (DisjiontSet[k] != k)
		{
			k = DisjiontSet[k];
		}

		DisjiontSet[i] = k;

		if (ResultMap.find(k) == ResultMap.end())
		{
			ResultMap.insert(std::make_pair(k, 0));
			ResultMap[k] = ResultMap.size() - 1;
		}
	}

	std::cout << ResultMap.size() << std::endl;

	for (unsigned int i=0; i<N; ++i)
	{
		delete[] ppMatrix[i];
	}
	delete[] ppMatrix;

	return 0;
}