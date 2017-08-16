//独立的小易  https://www.nowcoder.com/test/question/done?tid=9944519&qid=112727#summary

#include <iostream>

int main()
{
	long int x, f, d, p;
	std::cin >> x >> f >> d >> p;

	//int Test = d / x;
	if (d / x <= f)
	{
		std::cout << d / x;
	}
	else
	{
		//int Result = (d + f*p)/(x + p);
		std::cout << (d + f*p)/(x + p);
	}
}