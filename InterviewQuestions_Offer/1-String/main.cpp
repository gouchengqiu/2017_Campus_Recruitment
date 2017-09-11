// 统计26个大写字母出现的次数  最终以4A2B7G 形式输出  代表A出现4次
// 
// #include <iostream>
// #include <string>
// #include <map>
// 
// std::map<int, char> encodeStr(const std::string& vInputStr)
// {
// 	std::map<int, char> Result;
// 
// 	int Letter[26] = {0,};
// 	for (unsigned int i=0; i<vInputStr.length(); i++)
// 	{
// 		Letter[vInputStr[i] - 'A']++;
// 	}
// 
// 	for (unsigned int i=0; i<26; i++)
// 	{
// 		if (Letter[i])
// 		{
// 			Result.insert(std::pair<int, char>(Letter[i], (char)(65+i)));
// 		}
// 	}
// 	return Result;
// }
// 
// int main()
// {
// 	std::string TestStr;
// 	//std::cout << "Input a string:\n";
// 	std::cin >> TestStr;
// 
// 	std::map<int, char> Result = encodeStr(TestStr);
// 	std::map<int, char>::reverse_iterator RIter;
// 	for (RIter=Result.rbegin(); RIter!=Result.rend(); RIter++)
// 	{
// 		std::cout << RIter->first << RIter->second;
// 	}
// 
// 	return 0;
// }

#include <math.h>
#include <stdio.h>
double Round(double dVal, short iPlaces)
{

	double dRetval;
	double dMod = 0.0000001;

	if (dVal<0.0) dMod=-0.0000001;

	dRetval=dVal;

	dRetval+=(5.0/pow(10.0,iPlaces+1.0));

	dRetval*=pow(10.0,iPlaces);

	dRetval=floor(dRetval+dMod);

	dRetval/=pow(10.0,iPlaces);

	return(dRetval);
}

int main()
{
	double Test = 3.14159267;
	double Res = Round(Test, 5);

	round()
	return 0;
}