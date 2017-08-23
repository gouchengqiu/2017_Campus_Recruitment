#include <math.h>
#include "List.h"
#include <iostream>

//struct SListNode
//{
//	int m_Value;
//	SListNode* m_pNext;
//
//	SListNode() {}
//	SListNode(SListNode* vNext, int vValue) : m_pNext(vNext), m_Value(vValue) {}
//};

void addToTail(SListNode* pHead, int vValue) //ע���β�ָ����ҪΪ������ڴ棬Ӧ����**
{
	SListNode* pNewNode = new SListNode();
	pNewNode->m_Value = vValue;
	pNewNode->m_pNext = NULL;

	if (pHead == NULL)
	{
		pHead = pNewNode;
	}
	else
	{
		SListNode* pTempNode = pHead;
		while (pTempNode->m_pNext)
		{
			pTempNode = pTempNode->m_pNext;
		}

		pTempNode->m_pNext = pNewNode;
	}
}

//********************************************************************
//FUNCTION:�������е�һ����ڵ�
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

	//����������������ĵ�һ���ཻ��
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

	SListNode* pFirstCommonNode = getFirstNodeInCircle(pNode1);
}

int main()
{
	//SListNode* pNode1 = new SListNode();
	//pNode1->m_Value = 1;
	//pNode1->m_pNext = NULL;

	//addToTail(pNode1, 2);

	//SListNode* pTest = NULL;
	//addToTail(pTest, 5);

	testForGetFirstNodeInCircle();


	return 0;
}