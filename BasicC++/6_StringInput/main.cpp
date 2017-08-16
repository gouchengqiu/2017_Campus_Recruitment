#include <iostream>
#include <string>

#include <stdio.h>
#include <math.h>

int main()
{
	//char NameTest[20];
	//std::cin >> NameTest;
	//std::cout << NameTest << std::endl;

	//char RemainStr[10];
	//std::cin >> RemainStr;
	//std::cout << RemainStr << std::endl;

	//char NameTest[20];
	//std::cin.getline(NameTest, 5);
	//std::cout << NameTest << std::endl;

	//char Temp;
	//std::cin.get(Temp);
	//std::cout << Temp << std::endl;

	//char Temp[20];
	//std::cin.get(Temp, 20);
	//std::cout << Temp << std::endl;

	//std::string StrTest;
	//getline(std::cin, StrTest);
	//std::cout << StrTest << std::endl;

	//char m[20]; 
	//gets(m);                       //²»ÄÜÐ´³Ém=gets(); 
	//std::cout << m << std::endl; 

// 	std::string StrTest;
// 	StrTest = gets();//´íÎó
// 	gets(StrTest);//´íÎó

	std::string Line;
	while (getline(std::cin, Line))
	{
		std::cout << Line << std::endl;
	}

	return 0;
}