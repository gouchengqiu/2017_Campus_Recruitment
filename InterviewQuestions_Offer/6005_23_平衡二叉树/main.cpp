#include "../Utility/BinaryTree.h"
#include <iostream>

int computeBinaryDepth(const SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL) return 0;

	int LeftDepth = 1 + computeBinaryDepth(vRoot->m_pLeft);
	int RightDepth = 1 + computeBinaryDepth(vRoot->m_pRight);
	return LeftDepth < RightDepth ? RightDepth : LeftDepth;
}

bool isBinaryTreeBalanced_01(const SBinaryTreeNode* vRoot)
{
	if (vRoot == NULL)
	{
		return true;
	}

	int LeftDepth = computeBinaryDepth(vRoot->m_pLeft);
	int RightDepth = computeBinaryDepth(vRoot->m_pRight);
	if (abs(LeftDepth - RightDepth) > 1)
	{
		return false;
	}

	return isBinaryTreeBalanced_01(vRoot->m_pLeft) && isBinaryTreeBalanced_01(vRoot->m_pRight);
}

bool isBinaryTreeBalanced(const SBinaryTreeNode* vRoot, int& voDepth)
{
	if (vRoot == NULL)
	{
		voDepth = 0;
		return true;
	}

	int LeftDepth, RightDepth;
	isBinaryTreeBalanced(vRoot->m_pLeft, LeftDepth);
	isBinaryTreeBalanced(vRoot->m_pRight, RightDepth);

	voDepth = LeftDepth < RightDepth ? RightDepth + 1: LeftDepth + 1;
	return abs(LeftDepth - RightDepth) <= 1; 
}

bool isBinaryTreeBalanced_02(const SBinaryTreeNode* vRoot)
{
	int Depth;
	return isBinaryTreeBalanced(vRoot, Depth);
}

void test(char* vTestName, const SBinaryTreeNode* vRoot, bool vExceptedResult)
{
	bool isTreeBalanced1 = isBinaryTreeBalanced_01(vRoot);
	bool isTreeBalanced2 = isBinaryTreeBalanced_02(vRoot);
	if (isTreeBalanced1 == vExceptedResult && isTreeBalanced1 == isTreeBalanced2)
	{
		std::cout << vTestName << " pass.\n";
	}
	else
	{
		std::cout << vTestName << " fail.\n";
	}
}

void test1()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);
	SBinaryTreeNode* pNode5 = createBinaryTreeNode(5);
	SBinaryTreeNode* pNode6 = createBinaryTreeNode(6);

	connectBinaryTreeNode(pNode1, pNode2, pNode3);
	connectBinaryTreeNode(pNode2, pNode4, pNode5);
	connectBinaryTreeNode(pNode3, pNode6, NULL);

	test("test1", pNode1, true);
	destroyBinaryTree(pNode1);
}

void test2()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);
	SBinaryTreeNode* pNode5 = createBinaryTreeNode(5);
	SBinaryTreeNode* pNode6 = createBinaryTreeNode(6);

	connectBinaryTreeNode(pNode1, pNode2, NULL);
	connectBinaryTreeNode(pNode2, pNode3, pNode4);

	test("test2", pNode1, false);
	destroyBinaryTree(pNode1);
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

	test("test3", pNode1, true);
	destroyBinaryTree(pNode1);
}

void test4()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, pNode2, NULL);
	connectBinaryTreeNode(pNode2, pNode3, NULL);
	connectBinaryTreeNode(pNode3, pNode4, NULL);

	test("test4", pNode1, false);
	destroyBinaryTree(pNode1);
}

void test5()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, NULL, pNode2);
	connectBinaryTreeNode(pNode2, NULL, pNode3);
	connectBinaryTreeNode(pNode3, NULL, pNode4);

	test("test5", pNode1, false);
	destroyBinaryTree(pNode1);
}

void test6()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);

	test("test6", pNode1, true);
	destroyBinaryTree(pNode1);
}

void test7()
{
	test("test7", NULL, true);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	return 0;
}