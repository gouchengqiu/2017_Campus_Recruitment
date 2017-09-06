#include "../Utility/BinaryTree.h"
#include <iostream>

SBinaryTreeNode* findNode(SBinaryTreeNode* vRoot, SBinaryTreeNode* vNode)
{
	if (vRoot == NULL || vNode == NULL)
		return NULL;
	
	while (vRoot->m_Value != vNode->m_Value)
	{
		SBinaryTreeNode* pLeft = findNode(vRoot->m_pLeft, vNode);
		SBinaryTreeNode* pRight = findNode(vRoot->m_pRight, vNode);
	}
}

bool isSubTree(SBinaryTreeNode* vRootA, SBinaryTreeNode* vRootB)
{
	if (vRootA == NULL)
		return false;
	else if (vRootB == NULL)
		return true;

	while (vRootA->m_Value != vRootB->m_Value)
	{

	}

}

int main()
{
	return 0;
}