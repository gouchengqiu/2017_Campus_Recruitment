#include "Object.h"

#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h> 

//构造函数 析构函数调用时间
//int main()
//{
//	CObject Test;
//	CObject* pT = &Test;
//	//delete pT;
//
//	system("pause");
//	return 0;
//}

//对象的二维指针的内存分配与释放
int main()
{
	CObject** ppTest = new CObject*[10];//申请行

	for (unsigned int i=0; i<10; i++)
	{
		CObject* pObject = new CObject[20]();
		ppTest[i] = pObject;//申请列  ppTest为二维数组 10行 20列
	}

	for (unsigned int i=0; i<10; i++)
	{
		CObject* pTemp = ppTest[i];
		for (int k=0; k<20; k++)
		{
			std::cout << pTemp[i].getData() << std::endl;
		}
		//std::cout << ppTest[i]->getData() << std::endl;
		delete[] ppTest[i]; //释放列
	}

	delete[]  ppTest;//释放行

	_CrtDumpMemoryLeaks();

	return 0;
}