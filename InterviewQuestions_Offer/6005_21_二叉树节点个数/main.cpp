#include "../Utility/BinaryTree.h"
#include <iostream>

int computeTreeNodeNum(const SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL)
	{
		return 0;
	}

	//Ð´µÄ†ªàÂÁË
	//if (vRoot->m_pLeft == NULL && vRoot->m_pRight == NULL)
	//{
	//	return 1;
	//}
	//else
	//{
	//	return 1 + computeTreeNodeNum(vRoot->m_pLeft) + computeTreeNodeNum(vRoot->m_pRight);
	//}

	return 1 + computeTreeNodeNum(vRoot->m_pLeft) + computeTreeNodeNum(vRoot->m_pRight);
}

void test(char* vTestName, const SBinaryTreeNode* vRoot, int vExpectedNum)
{
	std::cout << vTestName << " starts: \n";
	
	int NodeNum = computeTreeNodeNum(vRoot);
	if (NodeNum == vExpectedNum)
	{
		std::cout << "Test pass.\n";
	}
	else
	{
		std::cout << "Test fail.\n";
	}
}

void test1()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, pNode2, pNode3);
	connectBinaryTreeNode(pNode2, pNode4, NULL);
	test("test1", pNode1, 4);
}

void test2()
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
	test("test2", pNode1, 7);
}

void test3()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	test("test3", pNode1, 1);
}

void test4()
{
	test("test4", NULL, 0);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}