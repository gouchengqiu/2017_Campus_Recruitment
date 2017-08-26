#include <iostream>
#include <string>
#include <sstream>

void quickSort(int vArray[], int vLeft, int vRight)
{
	if (vLeft >= vRight)
	{
		return;
	}

	int i = vLeft, j = vRight;
	int Temp = vArray[vLeft];

	while (i < j)
	{
		while (i < j && vArray[j] >= Temp)
		{
			j--;
		}
		if (i < j)
		{
			vArray[i] = vArray[j];
			i++;
		}

		while (i < j && vArray[i] < Temp)
		{
			i++;
		}
		if (i < j)
		{
			vArray[j] = vArray[i];
			j--;
		}
	}

	vArray[i] = Temp;

	quickSort(vArray, vLeft, i - 1);
	quickSort(vArray, i + 1, vRight);
}

int computeMinCost(int vDrangon[], unsigned int vDrangonNum, int vAgent[], unsigned int vAgentNum)
{
	if (vDrangon == NULL || vAgent == NULL || (vDrangonNum > 0 && vAgentNum == 0))
	{
		return -1;
	}

	quickSort(vDrangon, 0, vDrangonNum - 1);
	quickSort(vAgent, 0, vAgentNum - 1);

	if (vAgent[vAgentNum - 1] < vDrangon[vDrangonNum - 1])
	{
		return -1;
	}

	int Result = 0;
	for (unsigned int i=0; i<vDrangonNum; ++i)
	{
		for (unsigned int k=0; k<vAgentNum; ++k)
		{
			if (vAgent[k] >= vDrangon[i])
			{
				Result += vAgent[k];
				break;
			}
		}
	}

	return Result;
}

int main()
{
	unsigned int N, M;
	std::cin >> N;
	std::cin >> M;

	int* pDrangon = new int[N];
	int* pAgent = new int[M];

	int Temp;
	int i=0;
	while (i < N)
	{
		std::cin >> Temp;
		pDrangon[i++] = Temp;
	}

	i=0;
	while (i < M)
	{
		std::cin >> Temp;
		pAgent[i++] = Temp;
	}

	//int Result = computeMinCost(pDrangon, N, pAgent, M);
	std::cout << computeMinCost(pDrangon, N, pAgent, M) << std::endl;

	delete[] pDrangon;
	delete[] pAgent;

	return 0;
}