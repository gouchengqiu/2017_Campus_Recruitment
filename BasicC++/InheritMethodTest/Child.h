#pragma once
#include "Base.h"

class CChild : public CBase
{
public:
	CChild(){}
	virtual ~CChild(){}

	virtual void testV() override {std::cout << "Child method.\n";}
	void extraMethod() {std::cout << "Child extral method.\n";}

private:

};