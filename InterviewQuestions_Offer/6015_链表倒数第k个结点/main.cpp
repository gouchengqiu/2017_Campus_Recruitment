#include "../Utility/List.h"
#include <iostream>

//我的方法： 遍历两次链表
SListNode* getLastKthNode(SListNode* vHead, unsigned int k)
{
	if (vHead == NULL || k == 0)
	{
		return NULL;
	}

	unsigned int Length = 0;
	SListNode* pTempNode = vHead;
	while (pTempNode != NULL)
	{
		Length++;
		pTempNode = pTempNode->m_pNext;
	}

	if (k > Length)
	{
		return NULL;
	}

	pTempNode = vHead;
	int TempNum = Length - k;
	while (TempNum > 0)
	{
		pTempNode = pTempNode->m_pNext;
		TempNum--;
	}
	return pTempNode;
}

//遍历一次链表
SListNode* getLastKthNode_02(SListNode* vHead, unsigned int k)
{
	if (vHead == NULL || k == 0)
	{
		return NULL;
	}

	SListNode* pFastNode = vHead;
	SListNode* pSlowNode = vHead;
	for (unsigned int i=0; i<k-1; ++i)
	{
		pFastNode = pFastNode->m_pNext;
		if (pFastNode == NULL)
		{
			std::cout << "Input error.\n";
			return NULL;
		}
	}

	while (pFastNode->m_pNext != NULL)
	{
		pSlowNode = pSlowNode->m_pNext;
		pFastNode = pFastNode->m_pNext;
	}

	return pSlowNode;
}

void test(char* vTestName, SListNode* vHead, unsigned int k, SListNode* vExpected)
{
	SListNode* pResult = getLastKthNode_02(vHead, k);
	if (pResult == vExpected)
	{
		std::cout << vTestName << " pass.\n";
	}
	else
	{
		std::cout << vTestName << " failed.\n";
	}
}

int main()
{
	SListNode* pNode1 = createListNode(1);
	SListNode* pNode2 = createListNode(2);
	SListNode* pNode3 = createListNode(3);
	SListNode* pNode4 = createListNode(4);

	connectListNode(pNode1, pNode2);
	connectListNode(pNode2, pNode3);
	connectListNode(pNode3, pNode4);

	test("test1", pNode1, 3, pNode2);

	test("test2", pNode1, 4, pNode1);

	test("test3", pNode1, 5, NULL);

	test("test4", NULL, 2, NULL);

	destroyList(pNode1);

	return 0;
}