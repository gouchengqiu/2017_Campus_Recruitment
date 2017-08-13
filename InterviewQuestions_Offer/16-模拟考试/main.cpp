//https://www.nowcoder.com/questionTerminal/46eb436eb6564a62b9f972160e1699c9

#include <iostream>
#include <string>

int addNumbers(int vArray[], int vLength)
{
	int Sum = 0;
	 for (unsigned int i=0; i<vLength; i++)
	 {
		 Sum += vArray[i];
	 }

	 return Sum;
}

int* pArray;
int MinLength = 0;

void printSuper(unsigned int vNumber, unsigned int vLength)
{
	if (vNumber < 1 || vNumber > 1000000000)
	{
		return;
	}
	if (vLength < 2 || vLength > 100)
	{
		return;
	}
	
	for (int VarLength = vLength; VarLength<=100; VarLength++) //���ȴ���100��ʹ������������ҲҪ���no
	{
		int Upper = vNumber/VarLength;
		pArray = new int[VarLength];

		for (int i=Upper; i>=Upper-VarLength; i--)
		{
			if (i < 0) {break;} //����߽���� 4950 100   �պ�0�ӵ�99�ĺ���4950
			int Temp = i;
  			for (unsigned int k=0; k<VarLength; k++)
			{
				pArray[k] = Temp++;
			}

			int AddResult = addNumbers(pArray, VarLength);
			if (AddResult == vNumber)
			{
				MinLength = VarLength;
				for (unsigned int m=0; m<MinLength-1; m++)
				{
					std::cout << pArray[m] << " ";
				}
				std::cout << pArray[MinLength-1];
				return;
			}
			else if (AddResult > vNumber)
			{
				continue;
			}
			else if (AddResult < vNumber)
			{
				break;
			}
		}
		delete[] pArray; //ÿ�μ�ʱ�ͷ��ڴ棬���ⳬ���ڴ�����
	}

	std::cout << "No";
}

int main()
{
	int Number, Length;
	std::cin >> Number >> Length;
	printSuper(Number, Length);
}