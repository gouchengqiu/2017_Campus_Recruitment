//#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "BinaryTree.h"

SBinaryTreeNode* createBinaryTreeNode(int vData)
{
	SBinaryTreeNode* pOneNode = new SBinaryTreeNode();
	pOneNode->m_Value  = vData;
	pOneNode->m_pLeft  = NULL;
	pOneNode->m_pRight = NULL;

	return pOneNode;
}

void connectBinaryTreeNode(SBinaryTreeNode* pParent, SBinaryTreeNode* pLeft, SBinaryTreeNode* pRight)
{
	if (pParent != NULL)
	{
		pParent->m_pLeft  = pLeft;
		pParent->m_pRight = pRight;
	}
}

//********************************************************************
//FUNCTION:
void destroyBinaryTree(SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL)
	{
		return;
	}

	SBinaryTreeNode* pLeft  = vRoot->m_pLeft;
	SBinaryTreeNode* pRight = vRoot->m_pRight;
	delete vRoot;

	destroyBinaryTree(pLeft);
	destroyBinaryTree(pRight);
}

//********************************************************************
//FUNCTION:
void printBinaryTree(SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL)
	{
		std::cout << "The node is null.\n";
		return;
	}

	std::cout << "Value of this node : " << vRoot->m_Value << std::endl;

	if (vRoot->m_pLeft)
	{
		std::cout << "The left child of this node is: " << vRoot->m_pLeft->m_Value << std::endl;
	}
	else
	{
		std::cout << "The left child of this node is null.\n";
	}

	if (vRoot->m_pRight)
	{
		std::cout << "The right child of this node is: " << vRoot->m_pRight->m_Value << std::endl;
	}
	else
	{
		std::cout << "The right child of this node is null.\n";
	}

	if (vRoot->m_pLeft)
	{
		printBinaryTree(vRoot->m_pLeft);
	}

	if (vRoot->m_pRight)
	{
		printBinaryTree(vRoot->m_pRight);
	}
}