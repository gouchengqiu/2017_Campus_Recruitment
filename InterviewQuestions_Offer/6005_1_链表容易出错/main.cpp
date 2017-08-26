#include "../Utility/List.h"
#include <iostream>

//剑指offer P50

void addToTail(SListNode* pHead, int vValue) //注意形参指针若要为其分配内存，应该用**
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

void deleteNode(SListNode* vHead, int vValue)
{
	if (vHead == NULL)
	{
		return;
	}

	if (vHead->m_Value == vValue)
	{
		SListNode* pDeletedNode = vHead;

		vHead = vHead->m_pNext;
		delete pDeletedNode;
		return;
	}

	SListNode* pTempNode = vHead;
	SListNode* pBeforeNode = NULL;
	while (pTempNode != NULL && pTempNode->m_Value != vValue)
	{
		pBeforeNode = pTempNode;
		pTempNode = pTempNode->m_pNext;
	}

	if (pTempNode != NULL)
	{
		pBeforeNode->m_pNext = pTempNode->m_pNext;
		delete pTempNode;
	}
}

void errorTest4AddToTail()
{
	SListNode* pNode1 = createListNode(1);
	addToTail(pNode1, 2); //正确

	SListNode* pTest = NULL;
	addToTail(pTest, 5); //错误
}

void errorTest4Delete()
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

	deleteNode(pNode1, 1);//此时出错
	deleteNode(pNode1, 2);//正确
}

int main()
{
	errorTest4AddToTail();
	errorTest4Delete();

	return 0;
}