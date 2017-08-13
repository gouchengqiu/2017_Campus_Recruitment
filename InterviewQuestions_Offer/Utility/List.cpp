#include "List.h"
#include <stdio.h>
#include <crtdbg.h>

SListNode* createListNode(int vValue)
{
	SListNode* pOneNode = new SListNode();
	pOneNode->m_Value = vValue;
	pOneNode->m_pNext = NULL;
	return pOneNode;
}

void connectListNode(SListNode* pNodeA, SListNode* pNodeB)
{
	_ASSERT(pNodeA);
	pNodeA->m_pNext = pNodeB;
}

void destroyList(SListNode* pHead)
{
	while (pHead != NULL)
	{
		SListNode* pNode = pHead->m_pNext;
		delete pHead;
		pHead = pNode;
	}
}