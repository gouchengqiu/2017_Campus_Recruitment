#include <string>
#include <iostream>

//将string转换成int的多种方法
//http://c.biancheng.net/cpp/html/124.html

int string2Int_1(const std::string& vInputStr)
{
	return atoi(vInputStr.c_str());
}

#include <sstream>
int string2Int_2(const std::string& vInputStr)
{
	std::stringstream SS;  //std::stringstream SS(vInputStr);
	SS.str(vInputStr);

	int Data;
	SS >> Data;

	return Data;
}

//http://blog.csdn.net/na_beginning/article/details/53576123
void int2String_1(int vData, std::string& voResult)
{
	voResult = std::to_string(vData);
}

void int2String_2(int vData, std::string& voResult)
{
	//错误示范
	//std::ostringstream SS(vData);
	//voResult = SS.str();

	std::stringstream SS;
	SS << vData;

	voResult = SS.str();
}

int main()
{
	std::string Str = "12345";
	int Result1 = string2Int_1(Str);
	std::cout << Str << " " << Result1 << std::endl;

	int Result2 = string2Int_2(Str);
	std::cout << Str << " " << Result2 << std::endl;

	int DataTest = 8899;
	std::string Str1, Str2;
	int2String_1(DataTest, Str1);
	int2String_2(DataTest, Str2);

	return 0;
}