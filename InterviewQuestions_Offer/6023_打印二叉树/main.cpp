#include <iostream>
#include <memory>
#include <queue>
#include "../Utility/BinaryTree.h"

void installMemoryLeakDetector()
{
#if defined(_DEBUG) | defined(DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 100;
#endif
}

void printBinaryTree(const SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL)
	{
		return;
	}
	std::queue<const SBinaryTreeNode*> VisitNode;
	VisitNode.push(vRoot);

	while (!VisitNode.empty())
	{
		const SBinaryTreeNode* pNowNode = VisitNode.front();
		std::cout << pNowNode->m_Value << " ";
		VisitNode.pop();

		if (pNowNode->m_pLeft)
		{
			VisitNode.push(pNowNode->m_pLeft);
		}
		
		if (pNowNode->m_pRight)
		{
			VisitNode.push(pNowNode->m_pRight);
		}
	}
}

int main()
{
	installMemoryLeakDetector();

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

	printBinaryTree(pNode8);

	destroyBinaryTree(pNode8);
	//delete pNode8;
	//delete pNode6;
	//delete pNode10;
	//delete pNode5;
	//delete pNode7;
	//delete pNode9;
	//delete pNode11;
}