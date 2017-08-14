#include <fstream>

int main()
{
	// 	std::ofstream Fout;
	// 	FOut.open("File.txt");

	std::ofstream Fout("write.txt");
	Fout << "Output file stream test";

	system("pause");
	return 0;
}