#pragma once

struct SBinaryTreeNode
{
	int m_Value;
	SBinaryTreeNode* m_pLeft;
	SBinaryTreeNode* m_pRight;
};

__declspec( dllexport ) SBinaryTreeNode* createBinaryTreeNode(int vData);
__declspec( dllexport ) void connectBinaryTreeNode(SBinaryTreeNode* pParent, SBinaryTreeNode* pLeft, SBinaryTreeNode* pRight);
__declspec( dllexport ) void destroyBinaryTree(SBinaryTreeNode* vRoot);
__declspec( dllexport ) void printBinaryTree(SBinaryTreeNode* vRoot);