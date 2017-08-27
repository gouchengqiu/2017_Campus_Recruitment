#include <string>
#include <vector>
#include <iostream>

std::string multiply(const std::string& vNum1, const std::string& vNum2)
{
	int Length1 = vNum1.length();
	int Length2 = vNum2.length();
	std::vector<int> Num(Length1 + Length2, 0);

	for (int i=0; i<Length1; i++)
	{
		int N1 = vNum1[Length1 - 1 - i] - '0';
		int Temp = 0;
		for (int j=0; j<Length2; j++)
		{
			int N2 = vNum2[Length2 - 1 - j] - '0';
			Temp = Temp + Num[i + j] + N1 * N2;
			Num[i + j] = Temp % 10;
			Temp /= 10;
		}
		Num[i + Length2] = Temp;
	}

	int i = Length1 + Length2 - 1;
	while (i >= 0 && Num[i] == 0)
	{
		i--;
	}

	std::string Result = "";
	while (i >= 0)
	{
		Result += static_cast<char>('0' + Num[i--]);
	}

	return Result;
}

int main()
{
	std::string Num1, Num2;

	std::cin >> Num1 >> Num2;

	std::cout << multiply(Num1, Num2);

	return 0;
}