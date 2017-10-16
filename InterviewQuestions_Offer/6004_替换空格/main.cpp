#include <iostream>
#include <string>

void replaceBlank(char* vString, int vStrMaxLength)
{
	if (vString == NULL || vStrMaxLength < 1)
	{
		return;
	}

	int OriginalStrLength = 0;
	int NumBlank = 0;
	int i = 0;
	while (vString[i] != '\0')
	{
		//std::cout << vString[i];
		OriginalStrLength++;
		if (vString[i] == ' ')
		{
			NumBlank++;
		}
		i++;
	}

	if (NumBlank == 0)
	{
		return;
	}

	int NewStrLength     = OriginalStrLength + NumBlank * 2;
	int OriginalStrIndex = OriginalStrLength - 1;
	int NewStrIndex      = NewStrLength - 1;

	while (NewStrIndex > OriginalStrIndex)
	{
		if (vString[OriginalStrIndex] == ' ')
		{
			vString[NewStrIndex--] = '0';
			vString[NewStrIndex--] = '2';
			vString[NewStrIndex--] = '%';
		}
		else
		{
			vString[NewStrIndex] = vString[OriginalStrIndex];
			NewStrIndex--;
		}
		OriginalStrIndex--;
	}
}

void test(char* vTestName, char* vString, int vStrMaxLength, char* vExpectedStr)
{
	replaceBlank(vString, vStrMaxLength);

	if (vTestName != NULL)
	{
		std::cout << vTestName << " begins: ";
	}

	if (vString == NULL && vExpectedStr == NULL)
	{
		std::cout << "passed.\n";
	}
	else if (vString != NULL && vExpectedStr == NULL)
	{
		std::cout << "failed.\n";
	}
	else if (strcmp(vExpectedStr, vString) == 0)
	{
		std::cout << "passed.\n";
	}
	else
	{
		std::cout << "failed.\n";
	}
}

void test1()
{
	//const int Length = 100;
	//char TestStr1[Length] = "we are happy.";
	//test("test1", TestStr1, Length, "we%20are%20happy.");
	const int Length = 100;
	char TestStr1[Length] = "Hello World";
	test("test1", TestStr1, Length, "Hello%20World");
}

void test2()
{
	const int Length = 100;
	char TestStr2[Length] = " we are happy.";
	test("test2", TestStr2, Length, "%20we%20are%20happy.");
}

void test3()
{
	const int Length = 100;
	char TestStr3[Length] = "we are happy. ";
	test("test3", TestStr3, Length, "we%20are%20happy.%20");
}

void test4()
{
	const int Length = 100;
	char TestStr3[Length] = "happy";
	test("test4", TestStr3, Length, "happy");
}

void test5()
{
	test("test5", NULL, 0, NULL);
}

void test6()
{
	const int Length = 100;
	char TestStr6[Length] = "";
	test("test6", TestStr6, Length, "");
}

void test7()
{
	const int Length = 100;
	char TestStr7[Length] = " ";
	test("test7", TestStr7, Length, "%20");
}

void test8()
{
	const int Length = 100;
	char TestStr8[Length] = "  ";
	test("test8", TestStr8, Length, "%20%20");
}

void test9()
{
	const int Length = 100;
	char TestStr9[Length] = "we  are happy.";
	test("test9", TestStr9, Length, "we%20%20are%20happy.");
}

int main()
{
	//std::string Str = "we are happy.";
	//int Length = Str.length();

	//std::cout << Str << std::endl;
	//replaceBlank((char*)Str.c_str(), 100);
	//std::cout << Str << std::endl;

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}