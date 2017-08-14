#include <iostream>
#include "MemoryTest.h"

int main()
{
	//case1:
	CMemoryTest* pTest1 = new CMemoryTest();
	delete pTest1;

	//case2:
	CMemoryTest* pTest2 = new CMemoryTest();
	free (pTest2);
}