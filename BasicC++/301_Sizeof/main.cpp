#include <iostream>
#include <vector>

#include "Object.h"

struct MyStructA
{
	char a;
	int b;
	short c;
};

void test(char vArray[], int vLength)
{
	std::cout << "Sizeof vArray[]: " << sizeof(vArray) << std::endl;
}

int main()
{
	//Case1: 基本类型
	//char* p = new char[10];
	//std::cout << "Sizeof p: " << sizeof(p) << std::endl;

	//char Array[10];
	//std::cout << "Sizeof Array[10]: " << sizeof(Array) << std::endl;

	//test(Array, 10);

	//Case2: 对象类型
	CObject Test;
	int Result = sizeof(Test);

	//CClassA ObjectA = 10;
	//CClassA ObjectB = ObjectA;

	//CClassA ObjectC(20);
	//ObjectC = ObjectA;

	//return 0;
}