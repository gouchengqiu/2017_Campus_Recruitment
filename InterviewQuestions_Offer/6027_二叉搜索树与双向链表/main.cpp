#include "../Utility/BinaryTree.h"
#include <iostream>

void convertNode(SBinaryTreeNode* vNode, SBinaryTreeNode** vLastNodeInList)
{
	if (vNode == NULL)
		return;

	SBinaryTreeNode* pCurrent = vNode;

	if (pCurrent->m_pLeft != NULL)
		convertNode(pCurrent->m_pLeft, vLastNodeInList);

	pCurrent->m_pLeft = *vLastNodeInList;

	if (*vLastNodeInList != NULL)
		(*vLastNodeInList)->m_pRight = pCurrent;

	*vLastNodeInList = pCurrent;

	if (pCurrent->m_pRight != NULL)
		convertNode(pCurrent->m_pRight, vLastNodeInList);
}

SBinaryTreeNode* convert(SBinaryTreeNode* vRootNode)
{
	SBinaryTreeNode* pLastNodeInList = NULL;
	convertNode(vRootNode, &pLastNodeInList);
}