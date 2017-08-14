#pragma once
class CClassA;
#include "ClassA.h"

namespace SpaceB
{
	class CClassB
	{
	public:
		CClassB();
		~CClassB();

		void setData(CClassA* vClass) {m_pClassA = vClass;}

	private:
		CClassA* m_pClassA;
	};
}