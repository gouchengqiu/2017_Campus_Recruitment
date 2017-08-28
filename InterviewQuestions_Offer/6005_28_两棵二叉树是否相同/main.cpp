#include "../Utility/BinaryTree.h"
#include <iostream>

#include <queue>

//比较两棵二叉树是否相等： 数据；结构    递归实现；非递归实现
bool isSameTree_recursive(const SBinaryTreeNode* vRootA, const SBinaryTreeNode* vRootB)
{
	if (vRootA == NULL && vRootB == NULL)
	{
		return true;
	}

	//我当时忽略了这种情况：
	if (vRootA == NULL && vRootB != NULL || vRootA != NULL && vRootB == NULL)
	{
		return false;
	}

	if (vRootA->m_Value != vRootB->m_Value)
	{
		return false;
	}

	bool isLeftSame = isSameTree_recursive(vRootA->m_pLeft, vRootB->m_pLeft);
	bool isRightSame = isSameTree_recursive(vRootA->m_pRight, vRootB->m_pRight);
	return isLeftSame && isRightSame;
}

bool isSameTree_NoRecursively(const SBinaryTreeNode* vRootA, const SBinaryTreeNode* vRootB)
{
	if (vRootA == NULL && vRootB == NULL)
		return true;

	if (vRootA == NULL && vRootB != NULL || vRootA != NULL && vRootB == NULL)
	{
		return false;
	}

	std::queue<const SBinaryTreeNode*> QueueA, QueueB;
	QueueA.push(vRootA);
	QueueB.push(vRootB);

	while (!QueueA.empty() && !QueueB.empty())
	{
		const SBinaryTreeNode* pNodeA = QueueA.front();
		const SBinaryTreeNode* pNodeB = QueueB.front();
		QueueA.pop();
		QueueB.pop();

		if (pNodeA == NULL && pNodeB != NULL || pNodeA != NULL && pNodeB == NULL)
		{
			return false;
		}

		if (pNodeA->m_Value != pNodeB->m_Value)
		{
			return false;
		}

		//之前这个写法是不对的： 判断pNode的左右结点的结构是否相同
		/*if (pNodeA->m_pLeft != pNodeB->m_pLeft || pNodeA->m_pRight != pNodeB->m_pRight)
		{
		return false;
		}*/

		if (pNodeA->m_pLeft == NULL && pNodeB->m_pLeft != NULL || 
			pNodeA->m_pLeft != NULL && pNodeB->m_pLeft == NULL || 
			pNodeA->m_pRight == NULL && pNodeB->m_pRight != NULL || 
			pNodeA->m_pRight != NULL && pNodeB->m_pRight == NULL
			)
		{
			return false;
		}

		if (pNodeA->m_pLeft != NULL)
		{
			QueueA.push(pNodeA->m_pLeft);
		}
		
		if (pNodeB->m_pLeft != NULL)
		{
			QueueB.push(pNodeB->m_pLeft);
		}

		if (pNodeA->m_pRight != NULL)
		{
			QueueA.push(pNodeA->m_pRight);
		}
		
		if (pNodeB->m_pRight != NULL)
		{
			QueueB.push(pNodeB->m_pRight);
		}
	}

	return true;
}

void test(char* vTestName, const SBinaryTreeNode* vRootA, const SBinaryTreeNode* vRootB, bool vExpectedRes)
{
	try
	{
		bool Result = isSameTree_recursive(vRootA, vRootB);
		bool Result2 = isSameTree_NoRecursively(vRootA, vRootB);
		if (Result == vExpectedRes && Result2 == vExpectedRes)
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
	connectBinaryTreeNode(pNode1, pNode2, NULL);
	connectBinaryTreeNode(pNode2, pNode3, NULL);

	SBinaryTreeNode* pNode11 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode12 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode13 = createBinaryTreeNode(3);
	connectBinaryTreeNode(pNode11, pNode12, NULL);
	connectBinaryTreeNode(pNode12, pNode13, NULL);

	test("test1", pNode1, pNode11, true);
}

void test2()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	connectBinaryTreeNode(pNode1, NULL, pNode2);
	connectBinaryTreeNode(pNode2, NULL, pNode3);

	SBinaryTreeNode* pNode11 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode12 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode13 = createBinaryTreeNode(3);
	connectBinaryTreeNode(pNode11, NULL, pNode12);
	connectBinaryTreeNode(pNode12, NULL, pNode13);

	test("test2", pNode1, pNode11, true);
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
	test("test3", pNode1, pNode1, true);
}

void test4()
{
	SBinaryTreeNode* pNode1 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode2 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode3 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode4 = createBinaryTreeNode(4);
	SBinaryTreeNode* pNode5 = createBinaryTreeNode(5);
	
	connectBinaryTreeNode(pNode1, pNode2, pNode3);
	connectBinaryTreeNode(pNode2, pNode4, pNode5);

	SBinaryTreeNode* pNode11 = createBinaryTreeNode(1);
	SBinaryTreeNode* pNode12 = createBinaryTreeNode(2);
	SBinaryTreeNode* pNode13 = createBinaryTreeNode(3);
	SBinaryTreeNode* pNode14 = createBinaryTreeNode(4);
	SBinaryTreeNode* pNode15 = createBinaryTreeNode(5);

	connectBinaryTreeNode(pNode11, pNode12, pNode13);
	connectBinaryTreeNode(pNode13, pNode14, pNode15);

	test("test4", pNode1, pNode11, false);
}

int main()
{
	test1();
	//test2();
	//test3();
	test4();

	return 0;
}