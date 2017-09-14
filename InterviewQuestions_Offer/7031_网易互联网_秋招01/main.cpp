#include <string>
#include <iostream>

std::string ResultStr;

void getStep(int& vNumber)
{
	if (vNumber == 1)
	{
		ResultStr += "1";
		return;
	}

	if (vNumber == 2)
	{
		ResultStr += "2";
		return;
	}

	while (vNumber > 2)
	{
		if (vNumber % 2 == 0)
		{
			vNumber = (vNumber - 2) / 2;
			ResultStr += "2";
			getStep(vNumber);
		}
		else
		{
			vNumber = (vNumber - 1) / 2;
			ResultStr += "1";
			getStep(vNumber);
		}
	}

}

int main()
{
	int N;
	std::cin >> N;

	//std::string ResultStr;

	getStep(N);

	reverse(ResultStr.begin(), ResultStr.end());
	std::cout << ResultStr << std::endl;

	return 0;
}