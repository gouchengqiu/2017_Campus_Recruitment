#include <iostream>

int main()
{
	//Case1:
	char SourceStr[] = "123456";
	char DstStr[6]; 
	char* pFirst = strcpy(DstStr, SourceStr);

	std::cout << DstStr;
	std::cout << std::endl;
	std::cout << pFirst;

	//Case2:
	//char SourceStr[] = "123456";
	//char DstStr2[6];
	//strncpy(DstStr2, SourceStr, 6);
	//std::cout << DstStr2;

	//Question:
	//char StrArray[10];
	//char* pStr1 = "1234567890";
	//strcpy(StrArray, pStr1);

	//std::cout << StrArray;

	return 0;
}