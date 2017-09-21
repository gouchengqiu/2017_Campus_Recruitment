#include <iostream>
#include <vector>

int compute(int** vData, int X, int Y)
{
	bool** ppIsVisited = new bool*[X];
	for (int i=0; i<X; ++i)
	{
		ppIsVisited[i] = new bool[Y];
	}

	int MaxData = -100, MaxIndexX, MaxIndexY;
	for (int i=0; i<X; ++i)
	{
		for (int j=0; j<Y; ++j)
		{
			ppIsVisited[i][j] = false;
			if (vData[i][j] > MaxData)
			{
				MaxData = vData[i][j];
				MaxIndexX = i;
				MaxIndexY = j;
			}
		}
	}

	ppIsVisited[MaxIndexX][MaxIndexY] = true;
	int StepSum = 0;
	bool IsFinish = false;
    while (!IsFinish)
    {
		MaxData = vData[MaxIndexX][MaxIndexY];
		int MinDiff = 100000, IndexX = -1, IndexY = -1;
		if (MaxIndexX - 1 >= 0)
		{
			int Up = vData[MaxIndexX - 1][MaxIndexY];
			int Diff = MaxData < Up ? Up - MaxData : MaxData - Up;
			if (MinDiff > Diff && !ppIsVisited[MaxIndexX - 1][MaxIndexY])
			{
				MinDiff = Diff;
				IndexX = MaxIndexX - 1;
				IndexY = MaxIndexY;
				//ppIsVisited[MaxIndexX][MaxIndexY - 1] = true;
			}
		}
		
		if (MaxIndexX + 1 < X)
		{
			int Down = vData[MaxIndexX + 1][MaxIndexY];
			int Diff = MaxData < Down ? Down - MaxData : MaxData - Down;
			if (MinDiff > Diff && !ppIsVisited[MaxIndexX + 1][MaxIndexY])
			{
				MinDiff = Diff;
				IndexX = MaxIndexX + 1;
				IndexY = MaxIndexY;
				//ppIsVisited[MaxIndexX][MaxIndexY + 1] = true;
			}
		}

		if (MaxIndexY - 1 >= 0)
		{
			int Left = vData[MaxIndexX][MaxIndexY - 1];
			int Diff = MaxData < Left ? Left - MaxData : MaxData - Left;
			if (MinDiff > Diff && !ppIsVisited[MaxIndexX][MaxIndexY - 1])
			{
				MinDiff = Diff;
				IndexX = MaxIndexX;
				IndexY = MaxIndexY - 1;
			}
		}

		if (MaxIndexY + 1 < Y)
		{
			int Right = vData[MaxIndexX][MaxIndexY + 1];
			int Diff = MaxData < Right ? Right - MaxData : MaxData - Right;
			if (MinDiff > Diff && !ppIsVisited[MaxIndexX][MaxIndexY + 1])
			{
				MinDiff = Diff;
				IndexX = MaxIndexX;
				IndexY = MaxIndexY + 1;
			}
		}

		if (IndexX != -1 && IndexY != -1)
		{
			ppIsVisited[IndexX][IndexY] = true;
			StepSum++;
			MaxIndexX = IndexX;
			MaxIndexY = IndexY;
		}
		else
		{
			IsFinish = true;
		}
    }

	return StepSum;
}

int main()
{
	std::vector<int> Result;

	int X, Y;
	std::cin >> X >> Y;
	int** pData = new int*[X];
	for (int i=0; i<X; ++i)
	{
		pData[i] = new int[Y];
		for (int k=0; k<Y; ++k)
		{
			std::cin >> pData[i][k];
		}
	}


	compute(pData, X, Y);

	for (int i=0; i<X; ++i)
	{
		delete[] pData[i];
	}
	delete[] pData;
// 	while (std::cin >> X >> Y)
// 	{
// 		int** pData = new int*[X];
// 		for (int i=0; i<X; ++i)
// 		{
// 			pData[i] = new int[Y];
// 		}
// 
// 		compute(pData, X, Y);
// 
// 		for (int i=0; i<X; ++i)
// 		{
// 			delete[] pData[i];
// 		}
// 		delete[] pData;
// 	}

	for (int i=0; i<Result.size(); ++i)
	{
		std::cout << Result[i];
	}

	return 0;
}