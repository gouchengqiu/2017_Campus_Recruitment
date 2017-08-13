#include <iostream>

void printOneMatrixCircle(int** vMatrix, int vRow, int vCol, int vStartIndex)
{
	int StartIndex[2] = {vStartIndex, vStartIndex};
	int EndIndex[2]   = {vRow - 1 - vStartIndex, vCol - 1 - vStartIndex};

	//Todo:从左到右打印
	int Temp = StartIndex[1];
	while (Temp <= EndIndex[1])
	{
		std::cout << vMatrix[vStartIndex][Temp] << " ";
		Temp++;
	}

	//Todo:从上到下
	int TempCol = Temp - 1;
	Temp = StartIndex[0] + 1;
	while (Temp <= EndIndex[0])
	{
		std::cout << vMatrix[Temp][TempCol] << " ";
		Temp++;
	}

	//Todo:从右到左
	int TempRow = Temp - 1;
	Temp = EndIndex[1] - 1;
	while (Temp >= StartIndex[0])
	{
		std::cout << vMatrix[TempRow][Temp] << " ";
		Temp--;
	}

	//Todo:从下到上
	TempCol = Temp + 1;
	Temp = EndIndex[0] - 1;
	while (Temp > StartIndex[0])
	{
		std::cout << vMatrix[Temp][TempCol] << " ";
		Temp--;
	}
}

int main()
{
	int Row = 5, Col = 4;
	int** ppArray = new int*[Row];
	for (unsigned int i=0; i<Row; ++i)
	{
		ppArray[i] = new int[Col];
	}

	int Number = 1;
	for (unsigned int i=0; i<Row; ++i)
	{
		for (unsigned int k=0; k<Col; ++k)
		{
			ppArray[i][k] = Number;
			Number++;
		}
	}

	Number = 0;
	while (Row > Number * 2 && Col > Number * 2)
	{
		printOneMatrixCircle(ppArray, Row, Col, Number);
		Number++;
	}

	for (unsigned int i=0; i<Col; ++i)
	{
		delete[] ppArray[i];
	}
	delete[] ppArray;
}