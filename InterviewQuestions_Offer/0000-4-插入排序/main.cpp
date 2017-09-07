//http://www.cnblogs.com/chengxiao/p/6104371.html
#include <iostream>

void shellSort(int vDataArray[], int vLength)
{
	int Increse = 0;
	//while (Increse <= vLength)
	//{
	//	Increse = 3 * Increse + 1;  //生成初始增量
	//}

	int IncrementArray[] = {3, 2, 1};
	int Times = 0;
	Increse = IncrementArray[0];
	while (Increse >= 1)
	{
		for (int i=Increse; i<vLength; ++i)
		{
			int j = i -Increse;
			int Temp = vDataArray[i];
			while (j >= 0 && vDataArray[j] > Temp)
			{
				vDataArray[j + Increse] = vDataArray[j];
				j = j - Increse;
			}
			vDataArray[j + Increse] = Temp;
		}
		//Increse = (Increse - 1) / 3;
		Increse = IncrementArray[++Times];
	}
}



int main()
{
	int Data[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
	shellSort(Data, 10);
}