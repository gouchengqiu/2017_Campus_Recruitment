#include <set>
#include <iostream>

int main()
{
	std::set<int> ITest;

	for (unsigned int i=0; i<5; i++)
	{
		ITest.insert(i);
	}

	ITest.insert(0);  //set��������ظ�Ԫ��

	for (auto& Element : ITest)
	{
		std::cout << Element << std::endl;
	}

	system("pause");

	return 0;
}