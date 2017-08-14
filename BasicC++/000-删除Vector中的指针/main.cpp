#include "Object.h"
#include <vector>

int main()
{
	std::vector<CObject*> ObjectPtrSet1;
	for (int i=0; i<10; ++i)
	{
		ObjectPtrSet1.push_back(new CObject(i));
	}

// 	delete[] ObjectPtrSet[0];
// 	delete[] ObjectPtrSet.data();
	for (int i=0; i<ObjectPtrSet1.size(); ++i)
	{
		delete ObjectPtrSet1[i];
	}


	std::vector<CObject*> ObjSet2 = std::vector<CObject*>(10);
	CObject* pObjBuffer = new CObject[10](0);
}