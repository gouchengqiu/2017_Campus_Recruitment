#include "ClassA.h"
#include "ClassB.h"

int main()
{
	CClassA* pT1 = new CClassA();
	CClassB* pT2 = new CClassB();

	pT1->setData(pT2);
	pT2->setData(pT1);

	return 0;
}

//http://blog.csdn.net/hazir/article/details/38600419 ±àÒëÆ÷µÄÔ¤±àÒëË³Ğò