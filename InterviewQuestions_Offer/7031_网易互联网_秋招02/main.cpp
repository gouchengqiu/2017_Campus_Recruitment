#include <iostream>
#include <string>
#include <iomanip>

float computeLength(std::string vInputStr)
{
	if (vInputStr.empty() || vInputStr.length() > 50)
	{
		return 0.00;
	}

	int DataNum = 0;
	for (int i=0; i<vInputStr.length()-1; ++i)
	{
		if (vInputStr[i] != vInputStr[i+1])
		{
			DataNum++;
		}
	}
	DataNum++;
	float Temp = vInputStr.length() /(float)DataNum;
	return Temp;
}

// typedef long long LL;
// 
// double round(double number, unsigned int bits) {
// 	LL integerPart = number;
// 	number -= integerPart;
// 	for (unsigned int i = 0; i < bits; ++i)
// 		number *= 10;
// 	number = (LL) (number + 0.5);
// 	for (unsigned int i = 0; i < bits; ++i)
// 		number /= 10;
// 	return integerPart + number;
// }

double round(double number, unsigned int bits) {
	double integerPart = floor(number);
	number -= integerPart;
	for (unsigned int i = 0; i < bits; ++i)
		number *= 10;
	number = floor(number + 0.5);
	for (unsigned int i = 0; i < bits; ++i)
		number /= 10;
	return integerPart + number;
}

int main()
{
	std::string InputStr;
	std::cin >> InputStr;

	float Res = computeLength(InputStr);
	Res = round(Res, 2);
	std::cout << Res << std::setprecision(2) << std::endl;
	return 0;
}