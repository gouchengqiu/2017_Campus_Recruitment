#include <iostream>
#include <string>

void printSuper(unsigned int vNumber, unsigned int vLength)
{
	if (vNumber < 1 || vNumber > 1000000000 || vLength < 2 || vLength > 100)
	{
		return;
	}

	for (int VarLength = vLength; VarLength<=100; VarLength++) //���ȴ���100��ʹ������������ҲҪ���no
	{
		double StartNumber = vNumber/(double)VarLength - (VarLength - 1)/2.0 - 1.0;
		bool IsInteger = (StartNumber - (int)StartNumber == 0) ? true : false;

		//int StartNumber = vNumber/VarLength - 1/2.0 * (VarLength - 1) - 1;���Ϊint�Ļ������floatǿ��ת��Ϊint
		//bool Test = StartNumber % 2 == 0 ; //�Ƿ��ܱ�2�������� ����߼�����  ʧ�ܵĲ���������543792409 57
		//bool TTT = (StartNumber % 2 == 0);
		//bool TT = (StartNumber % 2 != 0);

		//if (StartNumber % 2 != 0)
		//{
		//	std::cout << "No";
		//}

		if (IsInteger && StartNumber + 1 >= 0)
		{
			std::cout.precision(16); //���þ���  û������Ļ�  199999997�ͻᱻ����� 2e + 08
			for (unsigned int i=1; i<VarLength; i++)
			{
				std::cout << StartNumber + i << " ";
			}
			std::cout << StartNumber + VarLength;
			return;
		}
	}

	std::cout << "No";
}

int main()
{
	int Number = 1000000000, Length = 2;
	//std::cin >> Number >> Length;
	printSuper(Number, Length);

	//double P = 199999997;
	//std::cout.precision(20); // �����������
	//std::cout << P ;
}