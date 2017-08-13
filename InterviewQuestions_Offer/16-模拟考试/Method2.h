#include <iostream>
#include <string>

void printSuper(unsigned int vNumber, unsigned int vLength)
{
	if (vNumber < 1 || vNumber > 1000000000 || vLength < 2 || vLength > 100)
	{
		return;
	}

	for (int VarLength = vLength; VarLength<=100; VarLength++) //长度大于100后即使有满足条件的也要输出no
	{
		double StartNumber = vNumber/(double)VarLength - (VarLength - 1)/2.0 - 1.0;
		bool IsInteger = (StartNumber - (int)StartNumber == 0) ? true : false;

		//int StartNumber = vNumber/VarLength - 1/2.0 * (VarLength - 1) - 1;结果为int的话会存在float强制转化为int
		//bool Test = StartNumber % 2 == 0 ; //是否能被2整除？？ 这个逻辑不对  失败的测试用例：543792409 57
		//bool TTT = (StartNumber % 2 == 0);
		//bool TT = (StartNumber % 2 != 0);

		//if (StartNumber % 2 != 0)
		//{
		//	std::cout << "No";
		//}

		if (IsInteger && StartNumber + 1 >= 0)
		{
			std::cout.precision(16); //设置精度  没有这个的话  199999997就会被输出成 2e + 08
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
	//std::cout.precision(20); // 设置输出精度
	//std::cout << P ;
}