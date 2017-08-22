#include <iostream>

struct SListNode
{
	int m_Value;
	SListNode* m_pNext;
};

void addToTail(SListNode* pHead, int vValue)
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

int main()
{
	SListNode* pNode1 = new SListNode();
	pNode1->m_Value = 1;
	pNode1->m_pNext = NULL;

	addToTail(pNode1, 2);

	SListNode* pTest = NULL;
	addToTail(pTest, 5);

	int i=5, j=6;
	int *ip1 = &i, *ip2 = &j;
	int **ipp = &ip1;

	*ipp = ip2;
}