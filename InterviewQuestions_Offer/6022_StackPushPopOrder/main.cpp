#include <stack>
#include <iostream>
#include <assert.h>

int findIndexInPushOrder(const int* vPush, int vLength, int vData)
{
	for (unsigned int i=0; i<vLength; ++i)
	{
		if (vPush[i] == vData)
		{
			return i;
		}
	}
	return -1;
}

bool popOrderEqualsPushOrder(const int* vPop, const int* vPush, int vLength)
{
	if (vPop == NULL || vPush == NULL || vLength < 1)
	{
		return false;
	}

	std::stack<int> TempSatck;
	int NowPushIndex = -1;

	for (unsigned int i=0; i<vLength; ++i)
	{
		if (TempSatck.empty() || TempSatck.top() != vPop[i])
		{
			int PushIndex = findIndexInPushOrder(vPush, vLength, vPop[i]);
			if (PushIndex == -1)
			{
				return false;
			}

			if (PushIndex > NowPushIndex)
			{
				for (unsigned int k=NowPushIndex+1; k<=PushIndex; ++k)
				{
					TempSatck.push(vPush[k]);
				}
			}
			NowPushIndex = PushIndex;
		}

		if (TempSatck.top() != vPop[i])
		{
			return false;
		}

		TempSatck.pop();
	}

	return true;
}

int main()
{
	const int Length = 5;
// 	int* pPushData = new int[Length];
// 	int* pPopData  = new int[Length];
	int PushData1[Length] = {1, 2, 3, 4, 5};
	int PopData1[Length]  = {4, 5, 3, 2, 1};
	bool Result1 = popOrderEqualsPushOrder(PopData1, PushData1, Length);

	int PushData2[Length] = {1, 2, 3, 4, 5};
	int PopData2[Length]  = {4, 3, 5, 1, 2};
	bool Result2 = popOrderEqualsPushOrder(PopData2, PushData2, Length);
}