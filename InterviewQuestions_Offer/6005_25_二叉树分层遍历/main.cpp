#include "../Utility/BinaryTree.h"
#include <queue>
#include <iostream>

void layerTraverse(const SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL)
	{
		return;
	}

	std::queue<const SBinaryTreeNode*> VisitQueue;
	VisitQueue.push(vRoot);

	while (!VisitQueue.empty())
	{
		const SBinaryTreeNode* pNode = VisitQueue.front();
		VisitQueue.pop();

		std::cout << pNode->m_Value << " ";
		if (pNode->m_pLeft != NULL)
		{
			VisitQueue.push(pNode->m_pLeft);
		}

		if (pNode->m_pRight != NULL)
		{
			VisitQueue.push(pNode->m_pRight);
		}
	}
}

void test(char* vTestName, const SBinaryTreeNode* vRoot)
{
	std::cout << vTestName << " start: \n";

	std::cout << "Hierarchical traverse: \n";
	layerTraverse(vRoot);

	std::cout << std::endl << vTestName << " end.\n";
}

void test1()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, pNode2, NULL);
	connectBinaryTreeNode(pNode2, pNode3, NULL);
	connectBinaryTreeNode(pNode3, pNode4, NULL);
	test("test1", pNode1);
}

void test2()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, NULL, pNode2);
	connectBinaryTreeNode(pNode2, NULL, pNode3);
	connectBinaryTreeNode(pNode3, NULL, pNode4);
	test("test2", pNode1);
}

void test3()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);
	SBinaryTreeNode* pNode5 = createBinaryTreeNode(5);
	SBinaryTreeNode* pNode6 = createBinaryTreeNode(6);
	SBinaryTreeNode* pNode7 = createBinaryTreeNode(7);

	connectBinaryTreeNode(pNode1, pNode2, pNode3);
	connectBinaryTreeNode(pNode2, pNode4, pNode5);
	connectBinaryTreeNode(pNode3, pNode6, pNode7);
	test("test3", pNode1);
}

void test4()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	test("test4", pNode1);
}

void test5()
{
	test("test5", NULL);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}