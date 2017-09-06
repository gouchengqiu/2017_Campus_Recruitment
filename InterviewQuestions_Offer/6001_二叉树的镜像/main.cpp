#include <iostream>
#include <stack>
#include "../Utility/BinaryTree.h"

void instalMemoryLeakDetector()
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		//_crtBreakAlloc = 10000;
#endif
}

void mirrorRecursively(SBinaryTreeNode* vTreeRoot)
{
	if (vTreeRoot == NULL)
	{
		return;
	}
 	if (vTreeRoot->m_pLeft == NULL && vTreeRoot->m_pRight == NULL)
 	{
 		return;
 	}

	SBinaryTreeNode* pTemp = vTreeRoot->m_pLeft;
	vTreeRoot->m_pLeft  = vTreeRoot->m_pRight;
	vTreeRoot->m_pRight = pTemp;

	mirrorRecursively(vTreeRoot->m_pLeft);
	mirrorRecursively(vTreeRoot->m_pRight);
}

void mirrorIteratively(SBinaryTreeNode* vTreeRoot)
{
	std::stack<SBinaryTreeNode*> NodeStack;
	if (vTreeRoot != NULL)
	{
		NodeStack.push(vTreeRoot);
	}

	while (!NodeStack.empty())
	{
		SBinaryTreeNode* pCurrentNode = NodeStack.top();
		NodeStack.pop();
		if (pCurrentNode->m_pLeft)
		{
			NodeStack.push(pCurrentNode->m_pLeft);
		}

		if (pCurrentNode->m_pRight)
		{
			NodeStack.push(pCurrentNode->m_pRight);
		}

		SBinaryTreeNode* pTempNode = pCurrentNode->m_pLeft;
		pCurrentNode->m_pLeft = pCurrentNode->m_pRight;
		pCurrentNode->m_pRight = pTempNode;
	}
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void test1()
{
	printf("\n=====Test1 starts:=====\n");
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

	//printBinaryTree(pNode8);

	printf("=====Test1: MirrorRecursively=====\n");
	mirrorRecursively(pNode8);
	printBinaryTree(pNode8);

	printf("=====Test1: MirrorIteratively=====\n");
	mirrorIteratively(pNode8);
	printBinaryTree(pNode8);

	destroyBinaryTree(pNode8);
}

void test2()
{
	std::cout << "\n=====Test2 starts:=====" << std::endl;

	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, pNode2, NULL);
	connectBinaryTreeNode(pNode2, pNode3, NULL);
	connectBinaryTreeNode(pNode3, pNode4, NULL);

	std::cout << "=====Test2: MirrorRecursively=====" << std::endl;
	mirrorIteratively(pNode1);
	printBinaryTree(pNode1);

	std::cout << "=====Test2: MirrorIteratively=====" << std::endl;
	mirrorRecursively(pNode1);
	printBinaryTree(pNode1);

	destroyBinaryTree(pNode1);
}

void test3()
{
	std::cout << "\n=====Test3 starts:=====" << std::endl;

	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);

	connectBinaryTreeNode(pNode1, NULL, pNode2);
	connectBinaryTreeNode(pNode2, NULL, pNode3);
	connectBinaryTreeNode(pNode3, NULL, pNode4);

	std::cout << "=====Test3: MirrorRecursively=====" << std::endl;
	mirrorIteratively(pNode1);
	printBinaryTree(pNode1);

	std::cout << "=====Test3: MirrorIteratively=====" << std::endl;
	mirrorRecursively(pNode1);
	printBinaryTree(pNode1);

	destroyBinaryTree(pNode1);
}

void test4()
{
	std::cout << "\n=====Test4 starts:=====" << std::endl;

	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);

	std::cout << "=====Test4: MirrorRecursively=====" << std::endl;
	mirrorIteratively(pNode1);
	printBinaryTree(pNode1);

	std::cout << "=====Test4: MirrorIteratively=====" << std::endl;
	mirrorRecursively(pNode1);
	printBinaryTree(pNode1);

	destroyBinaryTree(pNode1);
}

void test5()
{
	std::cout << "\n=====Test5 starts:=====" << std::endl;

	SBinaryTreeNode* pNode1 = NULL;

	std::cout << "=====Test5: MirrorRecursively=====" << std::endl;
	mirrorIteratively(pNode1);
	printBinaryTree(pNode1);

	std::cout << "=====Test5: MirrorIteratively=====" << std::endl;
	mirrorRecursively(pNode1);
	printBinaryTree(pNode1);
}

int main()
{
	instalMemoryLeakDetector();

	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}