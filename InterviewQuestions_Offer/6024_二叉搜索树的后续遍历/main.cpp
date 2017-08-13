#include "../Utility/BinaryTree.h"
#include <stdio.h>
#include <iostream>

void installMemoryLeakDetector()
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 100;
#endif
}

bool splitArrayByData(int* vInputArray, int vLength, int vData, int& voSplitIndex)
{
	voSplitIndex = -1;
	for (int i=0; i<vLength; ++i)
	{
		if (voSplitIndex == -1 && vInputArray[i] > vData)
		{
			voSplitIndex = i;
			continue;;
		}

		if (voSplitIndex != -1 && vInputArray[i] < vData)
		{
			return false;
		}
	}

	return true;
}

bool isRootLastTranverseBST(int* vArray, int vLength)
{
	if (vArray == NULL || vLength <= 0)
	{
		return false;
	}
	if (vLength <= 1)
	{
		return true;
	}

	int Root = vArray[vLength - 1];
	int SplitIndex = -1;
	bool IsSplited = splitArrayByData(vArray, vLength - 1, Root, SplitIndex);

	if (!IsSplited)
	{
		return false;
	}

	bool Left = true;
	if (SplitIndex > 0)
	{
		Left = isRootLastTranverseBST(vArray, SplitIndex);
	}

	bool Right = true;
	if (vLength - 1 - SplitIndex > 0)
	{
		Right = isRootLastTranverseBST(vArray + SplitIndex, vLength - 1 - SplitIndex);
	}
	
	return Left && Right;
	//if (SplitIndex == -1)
	//{
	//	if (!isRootLastTranverseBST(vArray, vLength - 1))
	//	{
	//		return false;
	//	}
	//}
	//else
	//{
	//	//int LeftLength = SplitIndex;
	//	/*if (SplitIndex > 0)
	//	{
	//		int* pLeft = new int[SplitIndex];
	//		for (int i=0; i<SplitIndex; ++i)
	//		{
	//			pLeft[i] = vArray[i];
	//		}
	//		if (!isRootLastTranverseBST(pLeft, SplitIndex))
	//		{
	//			delete[] pLeft;
	//			return false;
	//		}
	//		delete[] pLeft;
	//	}

	//	int RightLength = vLength - 1 - SplitIndex;
	//	if (RightLength > 0)
	//	{
	//		int* pRight = new int[RightLength];
	//		for (int i=0; i<RightLength; ++i)
	//		{
	//			pRight[i] = vArray[SplitIndex + i];
	//		}

	//		if (!isRootLastTranverseBST(pRight, RightLength))
	//		{
	//			delete[] pRight;
	//			return false;
	//		}
	//		delete[] pRight;
	//	}*/
	//}

	//return true;
}

void test(const char* vStr, int* vArray, int vLength, bool vExpected)
{
	if (vStr != NULL)
	{
		std::cout << vStr << " begins: ";
	}

	if (isRootLastTranverseBST(vArray, vLength) == vExpected)
	{
		std::cout << "passed.\n";
	}
	else
	{
		std::cout << "failed.\n";
	}
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void test1()
{
	int Array[] = {4, 8, 6, 12, 16, 14, 10};
	int ArrayLength = sizeof(Array) / sizeof(Array[0]);
	test("test1", Array, ArrayLength, true);
}

//           5
//          / \
//         4   7
//            /
//           6
void test2()
{
	int Array[] = {4, 6, 7, 5};
	test("test2", Array, sizeof(Array)/sizeof(Array[0]), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void test3()
{
	int Array[] = {1, 2, 3, 4, 5};
	test("test3", Array, sizeof(Array)/sizeof(Array[0]), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void test4()
{
	int Array[] = {5, 4, 3, 2, 1};
	test("test4", Array, sizeof(Array)/sizeof(Array[0]), true);
}

// 树中只有1个结点
void test5()
{
	int Array[] = {5};
	test("test5", Array, sizeof(Array)/sizeof(Array[0]), true);
}

void test6()
{
	int Array[] = {7, 4, 6, 5};
	test("Test6", Array, sizeof(Array)/sizeof(Array[0]), false);
}

void test7()
{
	int Array[] = {4, 6, 12, 8, 16, 14, 10};
	test("Test7", Array, sizeof(Array)/sizeof(Array[0]), false);
}

void test8()
{
	test("Test8", NULL, 0, false);
}

int main()
{
	installMemoryLeakDetector();

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();

	return 0;
}