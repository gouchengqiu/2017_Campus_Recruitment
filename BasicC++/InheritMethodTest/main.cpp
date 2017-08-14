#include "Child.h"

int main()
{
	CBase* pObject = new CChild;
	
	pObject->testV();
	dynamic_cast<CBase*>(pObject)->testV();
	dynamic_cast<CChild*>(pObject)->extraMethod();
	dynamic_cast<CChild*>(pObject)->testV();
}