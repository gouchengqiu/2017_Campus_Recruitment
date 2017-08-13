#include <iostream>

bool isDataExist(int* vArray, int vRows, int vCols, int vData)
{
	if (vArray == NULL || (vRows == 0 && vCols == 0) || vRows < 0 || vCols < 0)
	{
		return false;
	}

	//int RightUpData = vArray[vCols - 1];
	///*int RightUpData = vArray[vCols - 1];*/
	//if (RightUpData == vData)
	//{
	//	return true;
	//}
	//else if (RightUpData > vData)
	//{
	//	//É¾³ýÒ»ÁÐ
	//	if (isDataExist(vArray, vRows, vCols - 1, vData))
	//	{
	//		return true;
	//	}
	//}
	//else if (RightUpData < vData)
	//{
	//	if (isDataExist(vArray + vCols, vRows - 1, vCols, vData))
	//	{
	//		return true;
	//	}
	//}

	//return false;
}

int main()
{
	int Array[][4] = {{1, 2,  8,  9}, 
	                  {2, 4,  9,  12},
	                  {4, 7,  10, 13},
	                  {6, 8,  11, 15},
	                  {8, 10, 13, 20}
                     };

	bool Res = isDataExist((int*)Array, 5, 4, 7);
}