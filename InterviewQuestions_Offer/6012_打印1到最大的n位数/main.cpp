#include <iostream>

//我的写法，有点烂
bool increment_Method01(char vNumber[])
{
	if (vNumber == NULL)
	{
		return true;
	}

	int Length = strlen(vNumber);
	int Temp =  vNumber[Length - 1] - '0';
	Temp++;
	int Crement = 0;

	if (Temp >= 10)
	{
		Crement = Temp / 10;
		Temp = Temp % 10;
	}

	vNumber[Length - 1] = Temp + '0';

	for (int i=Length-2; i>=0; i--)
	{
		if (Crement > 0)
		{
			vNumber[i] = vNumber[i] + Crement;
		}
		
		Temp = vNumber[i] - '0';
		if (Temp >= 10)
		{
			Crement = Temp / 10;
			vNumber[i] = (Temp % 10) + '0';
		}
		else
		{
			break;
		}
	}

	for (int i=0; i<Length; ++i)
	{
		if (vNumber[i] - '0' != 9)
		{
			return false;
		}
	}

	return true;
}

bool increment_Method02(char vNumber[])
{
	if (vNumber == NULL)
	{
		return false;
	}

	bool IsOverflow = false;
	int Crement = 0;
	int Length = strlen(vNumber);
	for (int i = Length-1; i>=0; --i)
	{
		int nSum = vNumber[i] - '0' + Crement;
		if (i == Length - 1)
		{
			nSum++;
		}

		if (nSum >= 10)
		{
			if (i == 0)
			{
				IsOverflow = true;
			}else
			{
				//IsOverflow = false;
				Crement = nSum / 10;
				nSum = nSum % 10;
				vNumber[i] = nSum + '0';
			}
		}
		else
		{
			vNumber[i] = nSum + '0';
			break;
		}
	}

	return IsOverflow;
}

void printNumber(char vNumber[])
{
	if (vNumber == NULL)
	{
		return;
	}

	int Length = strlen(vNumber); //"0102" length = 4;

	int StratIndex = -1;
	for (int i=0; i<Length; ++i)
	{
		if (vNumber[i] != '0')
		{
			StratIndex = i;
			break;
		}
	}

	if (StratIndex == -1)
	{
		std::cout << 0 ;
		return;
	}

	for (int i=StratIndex; i<Length; ++i)
	{
		std::cout << (vNumber[i] - '0');
	}
}

void print1ToMaxofNDigits(int n)
{
	char* pNumber = new char[n+1];
	memset(pNumber, '0', n);
	pNumber[n] = '\0';

 	while (!increment_Method02(pNumber))
 	{
 		printNumber(pNumber);
 		std::cout << std::endl;
 	}

	//printNumber(pNumber);

	delete[] pNumber;
}

//递归实现
void print1ToMaxofNDigitsRecursively(char* vNumber, int vLength, int vIndex)
{
	if (vIndex == vLength - 1)
	{
		printNumber(vNumber);
		return;
	}

	for (int i=0; i<10; ++i)
	{
		vNumber[vIndex + 1] = i + '0';
		print1ToMaxofNDigitsRecursively(vNumber, vLength, vIndex + 1);
	}
}

void print1ToMaxofNDigits_02(int n)
{
	if (n <= 0)
	{
		return;
	}

	char* pNumber = new char[n + 1];
	pNumber[n] = '\0';

	for (int i=0; i<n; ++i)
	{
		pNumber[0] = i + '0';
		print1ToMaxofNDigitsRecursively(pNumber, n, 0);
	}
}

int main()
{
	//char Array[] = "000";
	//printNumber(Array);

	//print1ToMaxofNDigits(2);
	print1ToMaxofNDigits_02(3);
	return 0;
}