#include <math.h>
#include "List.h"
#include <iostream>

//********************************************************************
//FUNCTION:求单链表环中第一个入口点
//http://blog.csdn.net/shanshanpt/article/details/12883585
SListNode* getFirstNodeInCircle(SListNode* vHeadNode)
{
	if (vHeadNode == NULL || vHeadNode->m_pNext == NULL)
	{
		return NULL;
	}

	SListNode* pFastNode = vHeadNode;
	SListNode* pSlowNode = vHeadNode;
	while (pFastNode != NULL && pFastNode->m_pNext != NULL)
	{
		pFastNode = pFastNode->m_pNext->m_pNext;
		pSlowNode = pSlowNode->m_pNext;

		if (pFastNode == pSlowNode)
		{
			break;
		}
	}

	if (pFastNode == NULL || pFastNode->m_pNext == NULL)
	{
		return NULL;
	}

	SListNode* pCutNode = pSlowNode;
	SListNode* pHead1 = vHeadNode;
	SListNode* pHead2 = pCutNode->m_pNext;

	unsigned int Length1 = 1;
	SListNode* pTempNode1 = pHead1;
	while (pTempNode1 != pCutNode)
	{
		pTempNode1 = pTempNode1->m_pNext;
		++Length1;
	}

	unsigned int Length2 = 1;
	SListNode* pTempNode2 = pCutNode->m_pNext;
	while (pTempNode2 != pCutNode)
	{
		pTempNode2 = pTempNode2->m_pNext;
		++Length2;
	}

	//下面求两个单链表的第一个相交点
	if (Length1 > Length2)
	{
		unsigned int Count = Length1 - Length2;
		while (Count--)
		{
			pHead1 = pHead1->m_pNext;
		}
	}else
	{
		unsigned int Count = Length2 - Length1;
		while (Count--)
		{
			pHead2 = pHead2->m_pNext;
		}
	}

	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->m_pNext;
		pHead2 = pHead2->m_pNext;
	}

	return pHead1;
}

void testForGetFirstNodeInCircle()
{
	SListNode* pNode1 = createListNode(1);
	SListNode* pNode2 = createListNode(2);
	SListNode* pNode3 = createListNode(3);
	SListNode* pNode4 = createListNode(4);
	SListNode* pNode5 = createListNode(5);
	
	connectListNode(pNode1, pNode2);
	connectListNode(pNode2, pNode3);
	connectListNode(pNode3, pNode4);
	connectListNode(pNode4, pNode5);
	connectListNode(pNode5, pNode3);

	//SListNode* pFirstCommonNode = getFirstNodeInCircle(pNode1);
}

int main()
{
	testForGetFirstNodeInCircle();

	return 0;
}