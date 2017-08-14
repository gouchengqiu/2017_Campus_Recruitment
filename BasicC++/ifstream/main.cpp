#include <fstream>
#include <string>

//int main()
//{
//	//从文件中读入。。。
//	std::ifstream Fin("read.txt");
//
//	std::string Str;
//	//std::getline(Fin, Str);
//
//	char Buf;
//	Fin >> Buf;
//	//Fin.getline(Buf, 80);
//}

#include <iostream>
int main()
{
	std::ofstream FOut("Test.txt");
	FOut << "Write to file.\n";
	std::cout << "Write to screen.\n";
	FOut.close();
}