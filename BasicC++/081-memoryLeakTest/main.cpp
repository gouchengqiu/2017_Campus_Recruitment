#include <vector>

 #define CRTDBG_MAP_ALLOC  //ʹ���ɵ��ڴ�dump�����ڴ�����ľ������
 #include <stdlib.h>    
 #include <crtdbg.h>    

//����ں����а��� _CrtDumpMemoryLeaks();    
//���ɼ�⵽�ڴ�й¶  

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


//Vector�ͷ��ڴ�  ����1��
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
	//_CrtSetBreakAlloc(171);//��λ�ڴ�й©
	//_CrtDumpMemoryLeaks();
	//installMemoryLeakDetector();

	std::vector<CObject*> ObjectSet;
	ObjectSet.resize(300);

	for (int i=0; i<ObjectSet.size(); ++i)
	{
		ObjectSet[i] = NULL;
	}

	//CObject* pDataSet = new CObject(300);//��ֻnew��һ������
	CObject* pDataSet = new CObject[300]();//���京��3000��CObject������ڴ�

	//���䶯̬�������Ҫ����Ĭ�ϵĹ��캯����  ������������Ĭ�Ϲ��캯��ʱ��������ʾָ��Ĭ�Ϲ��캯���� ���ޣ���ϵͳ���Զ�����Ĭ�Ϲ��캯����
	for (unsigned int i=0; i<ObjectSet.size(); ++i)
	{
		ObjectSet[i] = pDataSet + i;
		//ObjectSet[i] = & pDataSet[i]; //���õ�ͬ����һ�� 
	}
	int DataA = ObjectSet[0]->getData();
	int DataB = ObjectSet[1]->getData();
	int DataC = ObjectSet[2]->getData();

	delete[] pDataSet;//������ڴ�й©
	
	_CrtDumpMemoryLeaks();//��⡰��ǰ�����ڴ�й©
	//installMemoryLeakDetector();

// 	for (unsigned int i=0; i<ObjectSet.size(); ++i)
// 	{
// 		delete ObjectSet[i];
// 	}

	//ObjectSet.clear();�����ͷ��ڴ�
	//std::vector<CObject*> T;
	//T.swap(ObjectSet); ����˵�������swap�ͷ�vector�ڴ�

	return 0;
}