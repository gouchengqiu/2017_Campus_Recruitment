#include <iostream>
#include <vector>

int computeMin(const std::vector<std::vector<int>>& vDataSet)
{
	int WallWidth = 0;
	for (unsigned int i=0; i<vDataSet[0].size(); ++i)
	{
		WallWidth += vDataSet[0][i];
	}

	int MinNum = 1;
	for (unsigned int Temp=1; Temp<WallWidth; ++Temp)
	{
		int OneNum = 0;
		for (unsigned int i=0; i<vDataSet.size(); ++i)
		{
			//计算这一行是否存在前n个数相加等于Temp
			int TempLength = 0;
			for (unsigned int k=0; k<vDataSet[i].size(); ++k)
			{
				TempLength += vDataSet[i][k];
				
				if (TempLength == Temp)
				{
					break;
				}
				
				if (TempLength > Temp)
				{
					OneNum++;
					break;
				}
			}
		}
		
		MinNum = MinNum > OneNum ? OneNum : MinNum;
	}

	return MinNum;
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> DataSet;
	DataSet.resize(N);

	for (unsigned int i=0; i<N; ++i)
	{
		int Temp;
		std::cin >> Temp;

		while (Temp != 0)
		{
			DataSet[i].push_back(Temp);
			std::cin >>Temp;
		}
	}

	std::cout << computeMin(DataSet);

	return 0;
}