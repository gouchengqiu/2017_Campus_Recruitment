#include <iostream>
#include <vector>

struct MyStructA
{
	char a;
	int b;
	short c;
};

int main()
{
	//int LengthA = sizeof(MyStructA);

	std::vector<int> DataSet;

	for (unsigned int i=0; i<5; ++i)
	{
		DataSet.push_back(i);
	}

	//DataSet.resize(7);

	//DataSet.resize(2);

	//DataSet.resize(5, 2);

	int LengthA = DataSet.size();
	int LengthB = DataSet.capacity();

	DataSet.clear();

	DataSet.reserve(2);

	LengthA = DataSet.size();
	LengthB = DataSet.capacity();

	return 0;
}