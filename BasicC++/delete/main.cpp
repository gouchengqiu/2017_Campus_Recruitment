#include "Object.h"

#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h> 

//���캯�� ������������ʱ��
//int main()
//{
//	CObject Test;
//	CObject* pT = &Test;
//	//delete pT;
//
//	system("pause");
//	return 0;
//}

//����Ķ�άָ����ڴ�������ͷ�
int main()
{
	CObject** ppTest = new CObject*[10];//������

	for (unsigned int i=0; i<10; i++)
	{
		CObject* pObject = new CObject[20]();
		ppTest[i] = pObject;//������  ppTestΪ��ά���� 10�� 20��
	}

	for (unsigned int i=0; i<10; i++)
	{
		CObject* pTemp = ppTest[i];
		for (int k=0; k<20; k++)
		{
			std::cout << pTemp[i].getData() << std::endl;
		}
		//std::cout << ppTest[i]->getData() << std::endl;
		delete[] ppTest[i]; //�ͷ���
	}

	delete[]  ppTest;//�ͷ���

	_CrtDumpMemoryLeaks();

	return 0;
}