#include <iostream>
#include <map>

std::map<int, int> ResultSet;

struct SPoint
{
	int m_PosX;
	int m_PosY;

	//SPoint(int vX, int vY) : m_PosX(vX), m_PosY(vY) {}
};

bool isMaxPoint(unsigned int vCurrentIndex, int vTotalNum, SPoint* vPointArray)
{
	if (vTotalNum <= 0 || vPointArray == NULL || vCurrentIndex >= vTotalNum)
	{
		return false;
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

void findMaxPoints(int vTotalNum, SPoint* vPointArray)
{
	if (vTotalNum == 0 || vPointArray == NULL)
	{
		return;
	}

	for (unsigned int i=0; i<vTotalNum; ++i)
	{
		if (isMaxPoint(i, vTotalNum, vPointArray))
		{
			//std::cout << vPointArray[i].m_PosX << " " << vPointArray[i].m_PosY << std::endl;
			//ResultSet.insert(vPointArray[i].m_PosX, vPointArray[i].m_PosY);
			ResultSet.insert(std::make_pair(vPointArray[i].m_PosX, vPointArray[i].m_PosY));
		}
	}
}

int main()
{
	int N;
	std::cin >> N;

	SPoint* pPointArray = new SPoint[N]();

	for (unsigned int i=0; i<N; ++i)
	{
		std::cin >> pPointArray[i].m_PosX >> pPointArray[i].m_PosY;
	}

	findMaxPoints(N, pPointArray);

	for (auto& Data : ResultSet)
	{
		std::cout << Data.first << " " << Data.second << std::endl;
	}

	delete[] pPointArray;

	return 0;
}