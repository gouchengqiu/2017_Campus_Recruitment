#include <iostream>

//我的方法  错误： 即使动态更新了有效查询的范围，但是array中仍然存的旧的数组，导致无法取到有效查询范围中的col row值
//解决： 每次动态维护有效查询范围row col时，同时重新分配数组内存。  但这会频繁分配  释放内存
bool isDataExist(int* vArray, int& vRows, int& vCols, int vData)
{
	if (vArray == NULL || vRows <= 0 || vCols <= 0)
	{
		return false;
	}

 	int RightUpData = vArray[vCols - 1];
	/*int RightUpData = vArray[vCols - 1];*/
	if (RightUpData == vData)
	{
		return true;
	}
	else if (RightUpData > vData)
	{
		//删除一列
		vCols -= 1;
		if (isDataExist(vArray, vRows, vCols, vData))
		{
			return true;
		}
	}
	else if (RightUpData < vData)
	{
		vRows -= 1;
		if (isDataExist(vArray + vCols, vRows, vCols, vData))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int Array[][3] = {{1, 2,  8}, 
	                  {2, 4,  9},
	                  {4, 7,  10},
                     };

// 	int Array[][4] = {{1, 2,  8,  9}, 
// 	{2, 4,  9,  12},
// 	{4, 7,  10, 13},
// 	{6, 8,  11, 15},
// 	{8, 10, 13, 20}
// 	};

	int RowNum = 3, ColNum = 3;
	bool Res = isDataExist((int*)Array, RowNum, ColNum, 7);

	return 0;
}