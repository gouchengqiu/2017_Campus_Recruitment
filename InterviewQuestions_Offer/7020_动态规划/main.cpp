//http://blog.csdn.net/baidu_28312631/article/details/47418773

#include <iostream>
#include <cmath>

int D[101][101];
int n;

int MaxSum_Method1(int i, int j)
{
	if (i == n)
	{
		return D[i][j];
	}

	int x = MaxSum_Method1(i+1, j);
	int y = MaxSum_Method1(i+1, j+1);
	return std::max(x, y) + D[i][j];
}

int MaxArray[101][101];
int MaxSum_Method2(int i, int j)
{
	if (MaxArray[i][j] != -1)
	{
		return MaxArray[i][j];
	}

	if (i == n)
	{
		MaxArray[i][j] = D[i][j];
	}
	else
	{
		int x = MaxSum_Method2(i+1, j);
		int y = MaxSum_Method2(i+1, j+1);
		MaxArray[i][j] = std::max(x, y) + D[i][j];
	}
	return MaxArray[i][j];
}

int main()
{
	//std::cin >> n;

	//for (unsigned int i=1; i<=n; ++i)
	//{
	//	for (unsigned int j=1; j<=i; ++j)
	//	{
	//		std::cin >> D[i][j];
	//	}
	//}

	n = 5;

	D[1][1] = 7;
	D[2][1] = 3, D[2][2] = 8;
	D[3][1] = 8, D[3][2] = 1, D[3][3] = 0;
	D[4][1] = 2, D[4][2] = 7, D[4][3] = 4, D[4][4] = 4;
	D[5][1] = 4, D[5][2] = 5, D[5][3] = 2, D[5][4] = 6, D[5][5] = 5;

	for (unsigned int i=1; i<=n; ++i)
	{
		for (unsigned int j=1; j<=i; ++j)
		{
			MaxArray[i][j] = -1;
		}
	}

	//std::cout << MaxSum_Method1(1, 1);
	std::cout << MaxSum_Method2(1, 1);
	return 0;
}