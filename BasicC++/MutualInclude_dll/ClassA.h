#pragma once

class CClassB;
#include "ClassB.h"

namespace SpaceA
{
	class CClassA
	{
	public:
		CClassA();
		~CClassA();

		void setData(SpaceB::CClassB* vClass) {m_pClassB = vClass;}

	private:
		SpaceB::CClassB* m_pClassB;
	};
}