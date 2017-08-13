#include <iostream>

float computeMaxVecSum(int* vVector, unsigned int vVecLength, unsigned int vCountNum)
{
	_ASSERT(vCountNum <= vVecLength);

	float MaxSum = FLT_MIN;
	int Index = 0;
	while (Index + vCountNum <= vVecLength)
	{
		float TempSum = 0;
		for (unsigned int i=Index; i<Index+vCountNum; i++)
		{
			TempSum += vVector[i];
		}
		MaxSum = (MaxSum < TempSum) ? TempSum : MaxSum;
		Index++;
	}

	return MaxSum;
}

//横向
float compute1(int* vArray, int vDimension, int vNum)
{
	float MaxSum = FLT_MIN;

	int* pLineVector = new int[vDimension]; //取一行的数据
	for (unsigned int Line=0; Line<vDimension; Line++)
	{
		for (unsigned int i=0; i<vDimension; i++)
		{
			pLineVector[i] = vArray[Line*vDimension + i];
		}
		float TempLineMaxSum = computeMaxVecSum(pLineVector, vDimension, vNum);
		MaxSum = (MaxSum < TempLineMaxSum) ? TempLineMaxSum : MaxSum;
	}

	delete[] pLineVector;
	return MaxSum;
}

//纵向
float compute2(int* vArray, int vDimension, int vNum)
{
	float MaxSum = FLT_MIN;

	int* vCol = new int[vDimension]; //保存每一列的数据
	for (unsigned int Col=0; Col<vDimension; Col++)
	{
		for (unsigned int Index=0; Index<vDimension; Index++)
		{
			vCol[Index] = vArray[vDimension*Index + Col];
		}
		float TempMaxCowSum = computeMaxVecSum(vCol, vDimension, vNum);
		MaxSum = (MaxSum < TempMaxCowSum) ? TempMaxCowSum : MaxSum;
	}
	delete[] vCol;  //删除指针数组
	return MaxSum;
}

//左上
float compute3(int* vArray, int vDimension, int vNum)
{
	float Result = FLT_MIN;
	for (unsigned int i=1; i<=vDimension; i++) //长度为i的向量
	{
		if (i < vNum) continue;

		int* Vect1 = new int[i];
		int* Vect2 = new int[i];

		if (i == 1)
		{
			Vect1[i-1] = vArray[0 + vDimension-1] ;//0,N-1
			Vect2[i-1] = vArray[(vDimension-1)*vDimension + 0];//N-1,0
		}
		else
		{
			int NumElement= i;
			for (unsigned int k=0; k<i; k++)
			{
				Vect1[k] = vArray[k*vDimension + (vDimension-NumElement)];
				Vect2[k] = vArray[vDimension*(vDimension-NumElement) + k];
				NumElement--;
			}
		}

		float ResultVec1 = computeMaxVecSum(Vect1, i, vNum);
		float ResultVec2 = computeMaxVecSum(Vect2, i, vNum);

		ResultVec1 = (ResultVec1 < ResultVec2) ? ResultVec2 : ResultVec1;
		Result = (Result < ResultVec1) ? ResultVec1 : Result;

		delete[] Vect1;
		delete[] Vect2;
	}

	return Result;
}

//右下
float compute4(int* vArray, int vDimension, int vNum)
{
	float MaxSum = FLT_MIN;

	for (unsigned int ArrayNum = 1; ArrayNum <= vDimension; ArrayNum++) //根据数组的个数从二维数组中取相应方向上的值
	{
		if (ArrayNum < vNum)
			continue;

		int* pTempArrayA = new int[ArrayNum];
		int IndexRowA = 0;
		int IndexColA = ArrayNum - 1;
		pTempArrayA[0] = vArray[IndexRowA*vDimension + IndexColA];

		int* pTempArrayB = new int[ArrayNum];
		int IndexRowB = vDimension-ArrayNum;
		int IndexColB = IndexColA + (vDimension-ArrayNum);
		pTempArrayB[0] = vArray[IndexRowB*vDimension + IndexColB];

		if (ArrayNum == 1)
		{ 
			pTempArrayA[ArrayNum-1] = vArray[0]; //0, 0
			pTempArrayB[ArrayNum-1] = vArray[(vDimension-1)*vDimension+ (vDimension-1)];//N-1, N-1
		}
		else
		{
			for (unsigned int Count = 1; Count < ArrayNum; Count++)
			{
				IndexRowA++;
				IndexColA--;
				pTempArrayA[Count] = vArray[IndexRowA*vDimension + IndexColA];

				IndexRowB++;
				IndexColB--;
				pTempArrayB[Count] = vArray[IndexRowB*vDimension + IndexColB];
			}
		}

		float TA = computeMaxVecSum(pTempArrayA, ArrayNum, vNum);
		float TB = computeMaxVecSum(pTempArrayB, ArrayNum, vNum);

		TA = (TA < TB) ? TB : TA;
		MaxSum = (TA < MaxSum) ? MaxSum : TA;

		delete[] pTempArrayA;
		delete[] pTempArrayB;
	}

	return MaxSum;
}

float getMaxSum(int* vArray, int vDimension, int vNum)
{
	float Result1 = compute1(vArray, vDimension, vNum);
	float Result2 = compute2(vArray, vDimension, vNum);
	float Result3 = compute3(vArray, vDimension, vNum);
	float Result4 = compute4(vArray, vDimension, vNum);

	Result1 = (Result1 > Result2) ? Result1 : Result2;
	Result3 = (Result3 > Result4) ? Result3 : Result4;

	return (Result1 > Result3) ? Result1 : Result3;
}

int main()
{
	int Dimension, Num;
	std::cin >> Dimension >> Num;

	int* pTest = new int[Dimension*Dimension];
	for (unsigned int i=0; i<Dimension*Dimension; i++)
	{
		int Data;
		std::cin >> Data;
		pTest[i] = Data;
	}
	std::cout << getMaxSum(pTest, Dimension, Num);
	delete[] pTest;
	//Eigen::MatrixXd Matrix = Eigen::MatrixXd::Random(Dimension, Dimension);

	//int** ppTest = new int*[Dimension];
	//for (unsigned int i=0; i<Dimension; i++)
	//{
	//	ppTest[i] = new int[Dimension];
	//}

	//ppTest = {1,  2,  3,  4,};


	//int Test[4][4] = {1,  2,  3,  4,
	//	5,  6,  7,  8,
	//	9,  10, 11, 12,
	//	13, 14, 15, 16
	//};
	//float Result = getMaxSum(Test[0], 4, 2);
	//float T = Result;
}