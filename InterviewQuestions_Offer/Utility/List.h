#pragma once

struct SListNode
{
	int m_Value;
	SListNode* m_pNext;
};

__declspec(dllexport) SListNode* createListNode(int vValue);
__declspec(dllexport) void connectListNode(SListNode* vNodeA, SListNode* vNodeB);
__declspec(dllexport) void destroyList(SListNode* vHead);
__declspec(dllexport) void printList(SListNode* vHead);