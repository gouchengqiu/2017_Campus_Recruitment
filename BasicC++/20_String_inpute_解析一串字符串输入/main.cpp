#include <string>
#include <sstream>
#include <iostream>

int main()
{
	std::string Input;
	//std::getline(std::cin, Input);
	std::cin >> Input;

	int Pos = Input.find(',');
	int TotalNum = 0;

	while (Pos != std::string::npos)
	{
		Input.replace(Pos, 1, 1, ' ');
		Pos = Input.find(',');
		TotalNum++;
	}

	int* pArray = new int[TotalNum + 1]();
	std::stringstream SS;
	SS << Input;

	int i = 0;
	while (SS)
	{
		SS >> pArray[i++];
	}

	delete[] pArray;
}