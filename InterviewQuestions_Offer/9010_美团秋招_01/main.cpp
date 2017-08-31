#include <iostream>

long int computeLongSubStr(long int vData[], long int vLength)
{
	if (vData == NULL || vLength <= 0)
	{
		return 0;
	}
	long int ResultNum = 1;
	long int FrontData = vData[0];
	for (long int i=1; i<vLength; ++i)
	{
		if (vData[i] != FrontData)
		{
			FrontData = vData[i];
			ResultNum++;
		}
	}

	return ResultNum;
}

int main()
{
	long int N;
	std::cin >> N;

	long int* pData = new long int[N];
	for (long int i=0; i<N; ++i)
	{
		std::cin >> pData[i];
	}

	std::cout << computeLongSubStr(pData, N) << std::endl;

	delete[] pData;

	return 0;
}