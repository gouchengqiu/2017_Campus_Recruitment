#include <iostream>
#include <string>

int main()
{
	std::string str ("There are two needles in this haystack with needles.");  
	std::string str2 ("needle");  

	// different member versions of find in the same order as above:  
	std::size_t found = str.find(str2);  
	if (found != std::string::npos)  
		std::cout << "first 'needle' found at: " << found << '\n';  

	found=str.find("needles are small", found+1, 9);  //查找字符串"needles are small"的前9个字符，从str的found+1开始。
	if (found!=std::string::npos)  
		std::cout << "second 'needle' found at: " << found << '\n';  

	found=str.find("haystack");  
	if (found!=std::string::npos)  
		std::cout << "'haystack' also found at: " << found << '\n';  

	found=str.find('.');  
	if (found!=std::string::npos)  
		std::cout << "Period found at: " << found << '\n';  

	// let's replace the first needle:  
	str.replace(str.find(str2),str2.length(),"preposition");  //replace 用法  
	std::cout << str << '\n';  

	return 0;  
};