//https://www.nowcoder.com/questionTerminal/e11bc3a213d24fc1989b21a7c8b50c3f
//输入一个数组，判断经过交互任意元素顺序后，是否能形成等差数列。
#include <iostream>

void sortData(int vData[], int vStartIndex, int vEndIndex) //快排
{
	if (vEndIndex <= vStartIndex)
	{
		return;
	}

	int Temp = vData[vStartIndex];
	int i = vStartIndex, j = vEndIndex;

	while (i < j)
	{
		while (i < j && vData[j] >= Temp)
		{
			j--;
		}
		if (i < j)
		{
			vData[i] = vData[j];
			i++;
		}

		while (i < j && vData[i] < Temp)
		{
			i++;
		}
		if (i < j)
		{
			vData[j] = vData[i];
			j--;
		}
	}

	vData[i] = Temp;

	sortData(vData, vStartIndex, i - 1);
	sortData(vData, i + 1, vEndIndex);
}

int sum(int vData[], int vLength)
{
	if (vData == NULL || vLength <= 0)
	{
		throw new std::exception("Invalid Parameters.");
	}

	int Sum = 0;
	for (unsigned int i=0; i<vLength; ++i)
	{
		Sum += vData[i];
	}
	return Sum;
}

bool isArithmeticProgression(int vData[], int vLength)
{
	if (vData == NULL || vLength <= 0)
	{
		return false;
	}

	sortData(vData, 0, vLength - 1);

	//S = a(1)*n + n*(n - 1)*d/2.0
	//==>>  d = (2 * s - 2 * a(1) n) / n*(n-1)

	int Sums = sum(vData, vLength);
	float Temp = 2 * sum(vData, vLength) - 2 * vData[0] * vLength;
	float d = Temp / (vLength * (vLength - 1));

	//下面为比较d是否等于0  注意：不要直接用==比较两个浮点数，需要定义精度.
	float Epsilon = 0.000001;
	float Diff = d - int(d); 

	return fabs(Diff) <= Epsilon;
}

int main()
{
	int Num;
	std::cin >> Num;

	int* pData = new int[Num];

	for (unsigned int i=0; i<Num; ++i)
	{
		std::cin >> pData[i];
	}

	bool Result = isArithmeticProgression(pData, Num);

	if (Result)
	{
		std::cout << "Possible";
	}
	else
	{
		std::cout << "Impossible";
	}

	delete[] pData;
}