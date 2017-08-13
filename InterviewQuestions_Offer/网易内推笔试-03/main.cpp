#include <iostream>

//计算一个格子上有vCount个棋子需要移动的次数
int computeMoveTimes(int vCoordX[], int vCoordY[], int vNum, int vCount)
{
	if (vCount == 1)
	{
		return 0;
	}
	else//此处详细计算。。。
	{
		return vCount;
	}
}

void computeSteps(int vCoordX[], int vCoordY[], int vNum)
{
	if (vNum <= 0 || vCoordX == NULL || vCoordY == NULL)
	{
		return;
	}

	for (int i=0; i<vNum; ++i)
	{
		std::cout << computeMoveTimes(vCoordX, vCoordY, vNum, i);
		if (i != vNum - 1)
		{
			std::cout << std::endl;
		}
	}
}

int main()
{
	int Num;
	std::cin >> Num;

	int* pCoordX = new int[Num];
	for (int i=0; i<Num; ++i)
	{
		std::cin >> pCoordX[i];
	}

	int* pCoordY = new int[Num];
	for (int i=0; i<Num; ++i)
	{
		std::cin >> pCoordY[i];
	}

	computeSteps(pCoordX, pCoordY, Num);

	delete[] pCoordX;
	delete[] pCoordY;

	return 0;
}