#include "Test.h"
#include "Derived.h"

//�����£� http://blog.sina.com.cn/s/blog_5a2bbc860101hgho.html
int main()
{
	//1: const_cast
 	//const CTest* pTest = new CTest();
 	//pTest->setData(10);
// 
	//CTest* pNew = const_cast<CTest*>(pTest);
	//pNew->setData(20);

	//2: static_cast  ��ִ�а�ȫ���  
// 	CDerivedClass* pDerive = new CDerivedClass();
// 	CBaseClass* pTest1 = static_cast<CBaseClass*>(pDerive);
// 	//
// 	CBaseClass* pBase = new CBaseClass();       //�Ա�1: ����ת�������࣬����ȫ�� static_cast���ܣ�ת����pTest2��ֵ��
// 	CDerivedClass* pTest2 = static_cast<CDerivedClass*>(pBase);
// 	int Data = pTest2->getData();

	//3: dynamic cast Ҫִ�а�ȫ���
	//CDerivedClass* pDerive = new CDerivedClass();
	//CBaseClass* pTest1 = dynamic_cast<CBaseClass*>(pDerive);

	//CBaseClass* pBase = new CBaseClass();    //�Ա�1: ����ת�������࣬����ȫ�� dynamic_cast������ʱִ�а�ȫ��飬�˴�����ת����������pTest2Ϊ��ָ�롣
	//CDerivedClass* pTest2 = dynamic_cast<CDerivedClass*>(pBase);
	////int Data = pTest2->getData();
	//
	//CBaseClass* b1 = new CDerivedClass();
	//CBaseClass* b2 = new CBaseClass();

	//CDerivedClass* d1 = dynamic_cast<CDerivedClass*>(b1);
	//CDerivedClass* d2 = dynamic_cast<CDerivedClass*>(b2);
	
	//
// 	int N = 5;
// 	int* pN = &N;
	//void* pV = static_cast<void*>(pN);


	//CDerivedClass* pDerive = new CDerivedClass();
	//CTest* pInterCast[5];
	////pInterCast[0] = pDerive;
	//pInterCast[1] = reinterpret_cast<CTest*>(pDerive);
	//pInterCast[1]->setData(10);
	//int Data = pInterCast[1]->getData();


 //	double D = static_cast<double>(N);
 //	double* pD = static_cast<double*>(pN); //�޹�����ָ��ת�����������
	
// 	double D = static_cast<double>(N);
// 	double* pD = reinterpret_cast<double*>(pN); //�޹�����ָ��ת�����������

/*	void* pV = static_cast<void*>(pN);*/
}
