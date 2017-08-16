//https://www.nowcoder.com/test/question/done?tid=9944519&qid=112726#summary

#include <iostream>

void sortArray(int vData[], int vLength, int vResult[])
{
	if (vData == NULL || vLength <= 0)
		return;

	//Case1: 我的做法   引入bool变量来记录第二轮到底是访问0号还是1号，有点笨了。  别人的做法就很简洁。
	/*int IndexA = vLength - 1;
	int IndexB = 0;
	bool IsFirstVisited = false;

	while (IndexA >= 0)
	{
		vResult[IndexB] = vData[IndexA];
		
		if (IndexA == 0)
		{
			IndexA--;
			IsFirstVisited = true;
		}else
		{
			IndexA -= 2;
		}
		IndexB++;
	}

	if (IsFirstVisited)
	{
		IndexA += 2;
	}
	else
	{
		IndexA++;
	}

	while (IndexA < vLength)
	{
		vResult[IndexB] = vData[IndexA];
		IndexA += 2;
		IndexB++;
	}*/

	//Case2:借鉴别人的做法

	int IndexA = vLength - 1;
	int IndexB = 0;
	while (IndexA >= 0)   // 前一半从最后一个数开始以2为步长递减
	{
		vResult[IndexB++] = vData[IndexA];
		IndexA -= 2;
	}

	IndexA = vLength % 2;
	while (IndexA < vLength - 1)  // 后一半根据整数个数的奇偶，分别从第二个或第一个数开始以2为步长递增
	{
		vResult[IndexB++] = vData[IndexA];
		IndexA += 2; 
	}
}

int main()
{
	int N;

	std::cin >> N;

	int* pArrayData = new int[N];
	for (int i=0; i<N; ++i)
	{
		std::cin >> pArrayData[i];
	}

	int* pResultArray = new int[N];
	sortArray(pArrayData, N, pResultArray);

	for (int i=0; i<N; ++i)
	{
		std::cout << pResultArray[i];
		if (i != N - 1)
		{
			 std::cout << " ";
		}
	}

	delete pArrayData;
	delete pResultArray;

	return 0;
}