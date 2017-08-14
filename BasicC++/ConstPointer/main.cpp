int main()
{
	//int const Data2 = 10;
	//Data2 = 20;

	int Data = 5;
	const int* pTest1       = new int(10);
	int* const pTest2       = new int;
	const int* const pTest3 = new int(20);

	*pTest1 = Data;
	pTest1 = &Data;

	*pTest2 = Data;
	pTest2 = &Data;

	*pTest3 = Data;
	pTest3 = &Data; 	  
}