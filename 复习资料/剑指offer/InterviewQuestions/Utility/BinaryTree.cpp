//#include <windows.h>
//#include <stdio.h>
#include "StdAfx.h"
#include "BinaryTree.h"

BinaryTreeNode* CreateBinaryTreeNode(int vData)
{
	BinaryTreeNode* pOneNode = new BinaryTreeNode();
	pOneNode->m_nValue  = vData;
	pOneNode->m_pLeft  = NULL;
	pOneNode->m_pRight = NULL;

	return pOneNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != NULL)
	{
		pParent->m_pLeft  = pLeft;
		pParent->m_pRight = pRight;
	}
}