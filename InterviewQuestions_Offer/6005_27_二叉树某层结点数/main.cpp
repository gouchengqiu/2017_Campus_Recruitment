#include "../Utility/BinaryTree.h"
#include <iostream>

int nodeNumInKLayer(const SBinaryTreeNode* vRoot, int vK)
{
	if (vK <= 0 || vRoot == NULL)
	{
		return 0;
	}

	if (vK == 1)
	{
// 		int Num = 0;
// 		Num = vRoot == NULL ? Num : Num+1;
		//return Num;
		return 1;
	}

	int Num1 = nodeNumInKLayer(vRoot->m_pLeft, vK-1);
	int Num2 = nodeNumInKLayer(vRoot->m_pRight, vK-1);
	return Num1 + Num2;
}

void test(char* vTestName, const SBinaryTreeNode* vRoot, int vK, int vExpectedNum)
{
	try
	{
		int NodeNum = nodeNumInKLayer(vRoot, vK);
		if (NodeNum == vExpectedNum)
		{
			std::cout << vTestName << " pass.\n";
		}
		else
		{
			std::cout << vTestName << " fail.\n";
		}
	}
	catch(...)
	{
		std::cout << "Input error.\n";
	}
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
	test("test1", pNode1, 2, 1);
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
	test("test2", pNode1, 3, 1);
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
	test("test3", pNode1, 3, 4);
}

void test4()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	//test("test4", pNode1, 1, 1);
	test("test4", pNode1, 2, 0);
}

void test5()
{
	test("test5", NULL, 1, 0);
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