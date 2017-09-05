#include "List.h"
#include <stdio.h>
#include <crtdbg.h>
#include <iostream>

SListNode* createListNode(int vValue)
{
	SListNode* pOneNode = new SListNode();
	pOneNode->m_Value = vValue;
	pOneNode->m_pNext = NULL;
	return pOneNode;
}

void connectListNode(SListNode* vNodeA, SListNode* vNodeB)
{
	_ASSERT(vNodeA);
	vNodeA->m_pNext = vNodeB;
}

void destroyList(SListNode* vHead)
{
	while (vHead != NULL)
	{
		SListNode* pNode = vHead->m_pNext;
		delete vHead;
		vHead = pNode;
	}
}

void printList(SListNode* vHead)
{
	//SListNode* 
	while (vHead != NULL)
	{
		std::cout << vHead->m_Value << " ";
		vHead = vHead->m_pNext;
	}
}