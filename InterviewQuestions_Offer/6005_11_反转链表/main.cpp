#include "../Utility/List.h"
#include <iostream>

SListNode* reverseList(SListNode* vListHead)
{
	if (vListHead == NULL)
	{
		return vListHead;
	}

	SListNode* pCurrentNode = vListHead;
	SListNode* pPreviousNode = NULL;
	SListNode* pReversedHead = NULL;
	while (pCurrentNode != NULL)
	{
		SListNode* pTemp = pCurrentNode->m_pNext;
		pCurrentNode->m_pNext = pPreviousNode;

		pPreviousNode = pCurrentNode;
		pCurrentNode = pTemp;

		if (pCurrentNode == NULL)
		{
			pReversedHead = pPreviousNode;
		}
	}
	return pReversedHead;
}

void test(char* vTestName, SListNode* vHead)
{
	std::cout << vTestName << " starts:\n";
	std::cout << "Original list: \n";
	printList(vHead);

	std::cout << "\n After reversed: \n";
	SListNode* pRevHead = reverseList(vHead);
	printList(pRevHead);
	std::cout << std::endl;
}

void test1()
{
	SListNode* pNode1 = createListNode(1);
	SListNode* pNode2 = createListNode(2);
	SListNode* pNode3 = createListNode(3);
	SListNode* pNode4 = createListNode(4);

	connectListNode(pNode1, pNode2);
	connectListNode(pNode2, pNode3);
	connectListNode(pNode3, pNode4);

	test("test1", pNode1);

	destroyList(pNode1);
}

void test2()
{
	SListNode* pNode1 = createListNode(1);
	test("test2", pNode1);

	destroyList(pNode1);
}

void test3()
{
	test("test3", NULL);
}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}