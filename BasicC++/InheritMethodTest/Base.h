#pragma once
#include <iostream>

class CBase
{
public:
	CBase() {}
	virtual ~CBase() {}

	virtual void testV() {std::cout << "base method..\n";}

private:
};