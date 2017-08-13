#pragma once

struct SListNode
{
	int m_Value;
	SListNode* m_pNext;
};

__declspec(dllexport) SListNode* createListNode(int vValue);
__declspec(dllexport) void connectListNode(SListNode* pNodeA, SListNode* pNodeB);
__declspec(dllexport) void destroyList(SListNode* pHead);