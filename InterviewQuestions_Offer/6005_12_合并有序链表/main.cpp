#include "../Utility/List.h"
#include <iostream>

SListNode* mergeList(SListNode* vListHeadA, SListNode* vListHeadB)
{
	if (vListHeadA == NULL && vListHeadB == NULL)
	{
		return NULL;
	}
	
	if (vListHeadA != NULL && vListHeadB == NULL)
	{
		return vListHeadA;
	}

	if (vListHeadB != NULL && vListHeadA == NULL)
	{
		return vListHeadB;
	}

	SListNode* pNewHead = NULL;
	SListNode* pPreviusNode = NULL;
	SListNode* pTempA = vListHeadA;
	SListNode* pTempB = vListHeadB;

	while (pTempA && pTempB)
	{
		SListNode* pTempNode = new SListNode();
		if (pTempA->m_Value < pTempB->m_Value)
		{
			pTempNode->m_Value = pTempA->m_Value;
			pTempA = pTempA->m_pNext;
		}
		else
		{
			pTempNode->m_Value = pTempB->m_Value;
			pTempB = pTempB->m_pNext;
		}

		if (pNewHead == NULL)
		{
			pNewHead = pTempNode;
			pPreviusNode = pTempNode;
		}

		pPreviusNode->m_pNext = pTempNode;
		pPreviusNode = pPreviusNode->m_pNext;
	}

	while (pTempA)
	{
		SListNode* pTempNode = new SListNode();
		pTempNode->m_Value = pTempA->m_Value;
		
		pPreviusNode->m_pNext = pTempNode;
		pPreviusNode = pPreviusNode->m_pNext;
		pTempA = pTempA->m_pNext;
	}

	while (pTempB)
	{
		SListNode* pTempNode = new SListNode();
		pTempNode->m_Value = pTempB->m_Value;

		pPreviusNode->m_pNext = pTempNode;
		pPreviusNode = pPreviusNode->m_pNext;
		pTempB = pTempB->m_pNext;
	}

	return pNewHead;
}

void test(char* vTestName, SListNode* vHeadA, SListNode* vHeadB)
{
	std::cout << vTestName << " starts:\n";
	SListNode* pRevHead = mergeList(vHeadA, vHeadB);
	printList(pRevHead);
	std::cout << std::endl;
}

void test1()
{
	SListNode* pNode1 = createListNode(1);
	SListNode* pNode2 = createListNode(2);
	SListNode* pNode3 = createListNode(3);
	SListNode* pNode4 = createListNode(4);
	SListNode* pNode5 = createListNode(5);
	SListNode* pNode6 = createListNode(6);
	SListNode* pNode7 = createListNode(7);

	connectListNode(pNode1, pNode3);
	connectListNode(pNode3, pNode4);

	connectListNode(pNode2, pNode5);
	connectListNode(pNode5, pNode6);
	connectListNode(pNode6, pNode7);

	test("test1", pNode1, pNode2);

	destroyList(pNode1);
	destroyList(pNode2);
}

void test2()
{
	SListNode* pNode1 = createListNode(1);
	SListNode* pNode3 = createListNode(3);
	SListNode* pNode4 = createListNode(4);

	connectListNode(pNode1, pNode3);
	connectListNode(pNode3, pNode4);

	test("test2", pNode1, NULL);

	destroyList(pNode1);
}

void test3()
{
	SListNode* pNode1 = createListNode(1);
	SListNode* pNode2 = createListNode(2);
	SListNode* pNode3 = createListNode(3);
	SListNode* pNode4 = createListNode(4);
	SListNode* pNode5 = createListNode(5);
	SListNode* pNode6 = createListNode(6);
	SListNode* pNode7 = createListNode(7);

	connectListNode(pNode1, pNode2);
	connectListNode(pNode2, pNode3);
	connectListNode(pNode3, pNode4);

	connectListNode(pNode5, pNode6);
	connectListNode(pNode6, pNode7);

	test("test3", pNode1, pNode5);

	destroyList(pNode1);
	destroyList(pNode5);
}

void test4()
{
	test("test4", NULL, NULL);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}