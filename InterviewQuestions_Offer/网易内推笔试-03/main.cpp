////移动棋子 https://www.nowcoder.com/test/question/done?tid=9944519&qid=112728#summary
//#include <iostream>
//
////计算一个格子上有vCount个棋子需要移动的次数
//int computeMoveTimes(int vCoordX[], int vCoordY[], int vNum, int vCount)
//{
//	if (vCount == 1)
//	{
//		return 0;
//	}
//	else//此处详细计算。。。
//	{
//		return vCount;
//	}
//}
//
//void computeSteps(int vCoordX[], int vCoordY[], int vNum)
//{
//	if (vNum <= 0 || vCoordX == NULL || vCoordY == NULL)
//	{
//		return;
//	}
//
//	for (int i=0; i<vNum; ++i)
//	{
//		std::cout << computeMoveTimes(vCoordX, vCoordY, vNum, i);
//		if (i != vNum - 1)
//		{
//			std::cout << std::endl;
//		}
//	}
//}
//
//int main()
//{
//	int Num;
//	std::cin >> Num;
//
//	int* pCoordX = new int[Num];
//	for (int i=0; i<Num; ++i)
//	{
//		std::cin >> pCoordX[i];
//	}
//
//	int* pCoordY = new int[Num];
//	for (int i=0; i<Num; ++i)
//	{
//		std::cin >> pCoordY[i];
//	}
//
//	computeSteps(pCoordX, pCoordY, Num);
//
//	delete[] pCoordX;
//	delete[] pCoordY;
//
//	return 0;
//}

//链接：https://www.nowcoder.com/questionTerminal/27f3672f17f94a289f3de86b69f8a25b
//来源：牛客网

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, x[55], y[55], ans[55];

void helper(){
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int tmp = 0;
			vector<int> dis(n, 0);

			for(int k = 0; k < n; ++k) dis[k] = abs(x[i] - x[k]) + abs(y[j] - y[k]);
			std::sort(dis.begin(), dis.end());

			for(int k = 0; k < n; ++k)
			{
				tmp += dis[k];
				ans[k] = min(ans[k], tmp);
			}
		}
	}
}

int main(int argc, char **argv)
{
	/*cin>>n;
	for(int i = 0; i < n; ++i) cin>>x[i];

	for(int i = 0; i < n; ++i) cin>>y[i];

	for(int i = 0; i < n; ++i) ans[i] = INT_MAX;*/

	n = 4;
	x[0] = 1; x[1] = 2; x[2] = 4; x[3] = 9;
	y[0] = 1; y[1] = 1; y[2] = 1; y[3] = 1;

	helper();

	for(int i = 0; i < n - 1; ++i) cout<< ans[i] << " ";
	cout<< ans[n - 1];
}