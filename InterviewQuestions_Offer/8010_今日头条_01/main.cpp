#include <iostream>
#include <map>

std::map<int, int> InputDataSet;
std::map<int, int> ResultSet;


bool isMaxPoint(unsigned int vCurrentIndex, const std::map<int, int>& vInputDataSet)
{
	vInputDataSet.
	for ()
	{
	}

	SPoint CurrentPoint = vPointArray[vCurrentIndex];
	for (unsigned int i=0; i<vTotalNum; ++i)
	{
		if (i == vCurrentIndex)
		{
			continue;
		}

		if (vPointArray[i].m_PosX > CurrentPoint.m_PosX && vPointArray[i].m_PosY > CurrentPoint.m_PosY)
		{
			return false;
		}
	}
	return true;
}

void findMaxPoints()
{
	for (unsigned int i=0; i<InputDataSet.size(); ++i)
	{
		
	}
}

int main()
{
	int N;
	std::cin >> N;

	for (unsigned int i=0; i<N; ++i)
	{
		int X, Y;
		std::cin >> X >> Y;
		InputDataSet.insert(std::make_pair(X, Y));
	}

	findMaxPoints();

	for (auto& Data : ResultSet)
	{
		std::cout << Data.first << " " << Data.second << std::endl;
	}

	return 0;
}