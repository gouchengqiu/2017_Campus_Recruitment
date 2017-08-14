//#include "Derive.h"

//int main()
//{
//	CBase*   pTest1 = new CBase(0);
//	pTest1->method();
//
//	CDerive* pTest2 = new CDerive(1, 2);
//	pTest2->method();
//
//	CBase* pTest3 = new CDerive(3, 4);
//	pTest3->method();
//}

class CBase
{
public:
	virtual void foo() {}
	virtual void bar() {}

private:
	int b;
};

class CDerive : public CBase
{
public:
	virtual void bar() override;
	virtual void quiz();
private:
	int d;
};