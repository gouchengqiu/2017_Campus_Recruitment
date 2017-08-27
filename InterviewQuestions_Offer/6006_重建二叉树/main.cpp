#include <iostream>
#include <exception>
#include "../Utility/BinaryTree.h"

SBinaryTreeNode* reconstructBinaryTree(int* vPreOrder, int* vInOrder, int vLength)
{
	if (vPreOrder == NULL || vInOrder == NULL || vLength < 1)
	{
		return NULL;
	}

	int RootData = vPreOrder[0];
	int RootPosInOrder = -1;
	for (unsigned int i=0; i<vLength; ++i)
	{
		if (vInOrder[i] == RootData)
		{
			RootPosInOrder = i;
			break;
		}
	}

	if (RootPosInOrder == -1)
	{
		throw std::exception("Invalid input.");
	}

	SBinaryTreeNode* pRootNode = createBinaryTreeNode(RootData);
	SBinaryTreeNode* pLeftNode = reconstructBinaryTree(vPreOrder + 1, vInOrder, RootPosInOrder);
	SBinaryTreeNode* pRightNode = reconstructBinaryTree(vPreOrder + RootPosInOrder + 1, vInOrder + RootPosInOrder + 1, vLength - (RootPosInOrder + 1));
	connectBinaryTreeNode(pRootNode, pLeftNode, pRightNode);

	return pRootNode;
}

void test(char* vStr, int* vPreOrder, int* vInOrder, int vArrayLength)
{
	_ASSERT(vStr);
	std::cout << std::endl << vStr << " begins: \n";

	std::cout << "PreOrder: \n";
	for (unsigned int i=0; i<vArrayLength; ++i)
	{
		std::cout << vPreOrder[i] << " ";
	}

	std::cout << "\nInOrder: \n";
	for (unsigned int i=0; i<vArrayLength; ++i)
	{
		std::cout << vInOrder[i] << " ";
	}
	std::cout << "\nshow reconstruct result: \n";

	try
	{
		SBinaryTreeNode* pRoot = reconstructBinaryTree(vPreOrder, vInOrder, vArrayLength);
		printBinaryTree(pRoot);
		destroyBinaryTree(pRoot);
	}
	catch(std::exception& exception)
	{
		std::cout << "Invalid input.\n";
	}
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void test0()
{
	const int Number = 7;
	int PreOrder[Number] = {1, 2, 4, 5, 3, 6, 7};
	int InOrder[Number]  = {4, 2, 5, 1, 6, 3, 7};
	test("tset0", PreOrder, InOrder, Number);
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void test1()
{
	const int Number = 8;
	int PreOrder[Number] = {1, 2, 4, 7, 3, 5, 6, 8};
	int InOrder[Number]  = {4, 7, 2, 1, 5, 3, 8, 6};
	test("test1", PreOrder, InOrder, Number);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void test2()
{
	const int Number = 5;
	int PreOrder[Number] = {1, 2, 3, 4, 5};
	int InOrder[Number]  = {5, 4, 3, 2, 1};
	test("test2", PreOrder, InOrder, Number);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void test3()
{
	const int Number = 5;
	int PreOrder[Number] = {1, 2, 3, 4, 5};
	int InOrder[Number]  = {1, 2, 3, 4, 5};
	test("test3", PreOrder, InOrder, Number);
}

// 树中只有一个结点
void test4()
{
	const int Number = 1;
	int PreOrder[Number] = {1};
	int InOrder[Number]  = {1};
	test("test4", PreOrder, InOrder, Number);
}

// 输入空指针
void test5()
{
	test("test5", NULL, NULL, 0);
}


// 输入的两个序列不匹配
void test6()
{
	const int Number = 7;
	int PreOrder[Number] = {1, 2, 4, 5, 3, 6, 7};
	int InOrder[Number]  = {4, 2, 8, 1, 6, 3, 7};
	test("test6", PreOrder, InOrder, Number);
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}