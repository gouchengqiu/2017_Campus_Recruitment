#include <iostream>
#include "../Utility/BinaryTree.h"

void instalMemoryLeakDetector()
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		//_crtBreakAlloc = 10000;
#endif
}

void computeImage(SBinaryTreeNode* voTreeRoot)
{
	if (voTreeRoot == NULL)
	{
		return;
	}
 	if (voTreeRoot->m_pLeft == NULL && voTreeRoot->m_pRight == NULL)
 	{
 		return;
 	}

	SBinaryTreeNode* pLeft  = voTreeRoot->m_pLeft;
	SBinaryTreeNode* pRight = voTreeRoot->m_pRight;
	SBinaryTreeNode* pTemp = pLeft;
	pLeft  = pRight;
	pRight = pTemp;

	computeImage(pLeft);
	computeImage(pRight);
}

int main()
{
	instalMemoryLeakDetector();

	SBinaryTreeNode* pNode8 = createBinaryTreeNode(8);
	SBinaryTreeNode* pNode6 = createBinaryTreeNode(6);
	SBinaryTreeNode* pNode10 = createBinaryTreeNode(10);
	SBinaryTreeNode* pNode5 = createBinaryTreeNode(5);
	SBinaryTreeNode* pNode7 = createBinaryTreeNode(7);
	SBinaryTreeNode* pNode9 = createBinaryTreeNode(9);
	SBinaryTreeNode* pNode11 = createBinaryTreeNode(11);

	connectBinaryTreeNode(pNode8, pNode6, pNode10);
	connectBinaryTreeNode(pNode6, pNode5, pNode7);
	connectBinaryTreeNode(pNode10, pNode9, pNode11);

	computeImage(pNode8);

	destroyBinaryTree(pNode8);
}