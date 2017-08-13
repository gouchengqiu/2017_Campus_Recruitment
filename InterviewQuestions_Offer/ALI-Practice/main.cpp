#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

long int sum(long int* vDataArray, int vNum)
{
	long int Sum = 0;
	for (int i=0; i<vNum; i++)
	{
		Sum += vDataArray[i];
	}
	return Sum;
}

bool partition (long int* vDataArray, int vNum)
{
	long Sum = sum(vDataArray, vNum);
	return (Sum % 2 == 0) ? true : false;
}

void parseInput(std::string& vInput, long int *Array)
{

}

int main()
{
	std::string Input;
	//std::getline(std::cin, Input);
	std::cin >> Input;//这两个输入均可以

	int pos = Input.find(',');
	int Total = 0; //记录数据个数
	while (pos != string::npos)  
	{  
		Input = Input.replace(pos, 1, 1, ' ');//将字符串中的','用空格代替
		pos = Input.find(',');
		Total++;
	}  

	long int *Array = new long int[Total+1];//分配内存
	stringstream SStream;  
	SStream << Input; //将字符串导入的流中  
	int i=0;
	while (SStream)  
	{  
		SStream >> Array[i++];  
	}  

	int Res = partition(Array, Total+1) ? 1 : 0;
	std::cout << Res << std::endl;

	delete[] Array;

	return 0;
}