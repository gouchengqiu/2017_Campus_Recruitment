#include <iostream>

//�ҵķ���  ���� ��ʹ��̬��������Ч��ѯ�ķ�Χ������array����Ȼ��ľɵ����飬�����޷�ȡ����Ч��ѯ��Χ�е�col rowֵ
//����� ÿ�ζ�̬ά����Ч��ѯ��Χrow colʱ��ͬʱ���·��������ڴ档  �����Ƶ������  �ͷ��ڴ�
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
		//ɾ��һ��
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