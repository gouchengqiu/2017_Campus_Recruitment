#include <vector>

 #define CRTDBG_MAP_ALLOC  //使生成的内存dump包含内存块分配的具体代码
 #include <stdlib.h>    
 #include <crtdbg.h>    

//在入口函数中包含 _CrtDumpMemoryLeaks();    
//即可检测到内存泄露  

//#define new  new(_CLIENT_BLOCK, __FILE__, __LINE__)

void installMemoryLeakDetector()
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	//_CRTDBG_LEAK_CHECK_DF: Perform automatic leak checking at program exit through a call to _CrtDumpMemoryLeaks and generate an error 
	//report if the application failed to free all the memory it allocated. OFF: Do not automatically perform leak checking at program exit.
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//the following statement is used to trigger a breakpoint when memory leak happens
	//comment it out if there is no memory leak report;
	//_crtBreakAlloc = 22455;
#endif
}


//Vector释放内存  测试1：
//int main()
//{
//	std::vector<int*> ObjectSet;
//	ObjectSet.resize(3000);
//
//	for (int i=0; i<3000; ++i)
//	{
//		ObjectSet[i] = new int();
//	}
//
//
//	for (int i=0; i<3000; ++i)
//	{
//		if (ObjectSet[i])
//		{
//			delete ObjectSet[i];
//			ObjectSet[i] = NULL;
//		}
//
//	}
//
//	_CrtDumpMemoryLeaks();
//
//	return 0;
//}

#include "Object.h"

int main()
{
	//_CrtSetBreakAlloc(171);//定位内存泄漏
	//_CrtDumpMemoryLeaks();
	//installMemoryLeakDetector();

	std::vector<CObject*> ObjectSet;
	ObjectSet.resize(300);

	for (int i=0; i<ObjectSet.size(); ++i)
	{
		ObjectSet[i] = NULL;
	}

	//CObject* pDataSet = new CObject(300);//这只new了一个对象
	CObject* pDataSet = new CObject[300]();//分配含有3000个CObject对象的内存

	//分配动态数组必须要类有默认的构造函数！  若类有其他非默认构造函数时，必须显示指定默认构造函数。 若无，则系统会自动生成默认构造函数。
	for (unsigned int i=0; i<ObjectSet.size(); ++i)
	{
		ObjectSet[i] = pDataSet + i;
		//ObjectSet[i] = & pDataSet[i]; //作用等同于上一行 
	}
	int DataA = ObjectSet[0]->getData();
	int DataB = ObjectSet[1]->getData();
	int DataC = ObjectSet[2]->getData();

	delete[] pDataSet;//这个无内存泄漏
	
	_CrtDumpMemoryLeaks();//检测“当前”的内存泄漏
	//installMemoryLeakDetector();

// 	for (unsigned int i=0; i<ObjectSet.size(); ++i)
// 	{
// 		delete ObjectSet[i];
// 	}

	//ObjectSet.clear();不会释放内存
	//std::vector<CObject*> T;
	//T.swap(ObjectSet); 网上说是最好用swap释放vector内存

	return 0;
}