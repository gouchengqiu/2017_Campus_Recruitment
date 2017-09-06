#include "../Utility/BinaryTree.h"
#include <vector>
#include <iostream>

void core(SBinaryTreeNode* vRootNode, int vSum, std::vector<SBinaryTreeNode*>& voCurrentStack, int& voCurrentSum)
{
	if (vRootNode == NULL)
	{
		return;
	}

	voCurrentStack.push_back(vRootNode);
	voCurrentSum += vRootNode->m_Value;

	bool isLeafNode = !vRootNode->m_pLeft && !vRootNode->m_pRight;
	if (isLeafNode && voCurrentSum == vSum)
	{
		for (unsigned int i=0; i<voCurrentStack.size(); ++i)
		{
			std::cout << voCurrentStack[i]->m_Value << " ";
		}
		std::cout << std::endl;
	}

	if (vRootNode->m_pLeft)
		core(vRootNode->m_pLeft, vSum, voCurrentStack, voCurrentSum);
	
	if (vRootNode->m_pRight)
		core(vRootNode->m_pRight, vSum, voCurrentStack, voCurrentSum);

	voCurrentStack.pop_back();
	voCurrentSum -= vRootNode->m_Value;
}

void printSumRoute(SBinaryTreeNode* vRootNode, int vSum)
{
	if (vRootNode == NULL)
	{
		return;
	}

	std::vector<SBinaryTreeNode*> NodeStack;
	int Currentum = 0;

    core(vRootNode, vSum, NodeStack, Currentum);
}

void test()
{
	SBinaryTreeNode* pNode10 = createBinaryTreeNode(10);
	SBinaryTreeNode* pNode5  = createBinaryTreeNode(5);
	SBinaryTreeNode* pNode12 = createBinaryTreeNode(12);
	SBinaryTreeNode* pNode4  = createBinaryTreeNode(4);
	SBinaryTreeNode* pNode7  = createBinaryTreeNode(7);

	connectBinaryTreeNode(pNode10, pNode5, pNode12);
	connectBinaryTreeNode(pNode5, pNode4, pNode7);

	printSumRoute(pNode10, 22);

	destroyBinaryTree(pNode10);
}

int main()
{
	test();

	return 0;
}