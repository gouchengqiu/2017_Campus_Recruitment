#include "../Utility/List.h"
#include <stack>
#include <assert.h>
#include <iostream>

void installMemoryLeakDetector()
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 10000;
#endif
}

void printListbyInvertedOrder(SListNode* vHead)
{
	if (vHead == NULL)
	{
		return;
	}

	std::stack<SListNode*> ListNodeStack;
	SListNode* pVisitNode = vHead;
	while (pVisitNode != NULL)
	{
		ListNodeStack.push(pVisitNode);
		pVisitNode = pVisitNode->m_pNext;
	}

	while (!ListNodeStack.empty())
	{
		assert(ListNodeStack.top());
		std::cout << ListNodeStack.top()->m_Value << " ";
		ListNodeStack.pop();
	}
}

void test1()
{
	SListNode* pListNode1 = createListNode(1);
	SListNode* pListNode2 = createListNode(2);
	SListNode* pListNode3 = createListNode(3);
	SListNode* pListNode4 = createListNode(4);
	SListNode* pListNode5 = createListNode(5);
	SListNode* pListNode6 = createListNode(6);

	connectListNode(pListNode1, pListNode2);
	connectListNode(pListNode2, pListNode3);
	connectListNode(pListNode3, pListNode4);
	connectListNode(pListNode4, pListNode5);
	connectListNode(pListNode5, pListNode6);

	//pListNode1->m_pNext = pListNode2;
	//pListNode2->m_pNext = pListNode3;
	//pListNode3->m_pNext = pListNode4;
	//pListNode4->m_pNext = pListNode5;
	//pListNode5->m_pNext = pListNode6;

	std::cout << "\n test1 begins: ";
	printListbyInvertedOrder(pListNode1);
	destroyList(pListNode1);
}

void test2()
{
	SListNode* pListNode1 = createListNode(1);
	std::cout << "\n test2 begins: ";
	printListbyInvertedOrder(pListNode1);
	destroyList(pListNode1);
}

void test3()
{
	std::cout << "\n test3 begins: ";
	printListbyInvertedOrder(NULL);
	std::cout << std::endl;
}

int main()
{
	installMemoryLeakDetector();

	test1();
	test2();
	test3();
}