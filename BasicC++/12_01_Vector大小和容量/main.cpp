#include <iostream>
#include <map>
#include <vector>

using namespace std; 
int main()
{   
	//std::map<int, float> Index2DistanceMap;
	//for (unsigned int i=0; i<10; ++i)
	//{
	//	Index2DistanceMap.insert(std::pair<int, float>(i, (float)i));
	//}

	//std::map<int, float>::iterator Iter = Index2DistanceMap.begin();
	//for ( ; Iter!=Index2DistanceMap.end();++Iter)
	//{
	//	if (Iter->first == 5)
	//	{
	//		Iter = Index2DistanceMap.erase(Iter);
	//	}
	//}

	//for (Iter = Index2DistanceMap.begin(); Iter != Index2DistanceMap.end(); ++Iter)
	//{
	//	std::cout << Iter->first << " " << Iter->second << std::endl;
	//}

	vector<int> vect;  
	int i = 0;  

	vect.reserve(10);  

	vect.push_back(1);  
	vect.push_back(2);  
	vect.push_back(3);  
	vect.push_back(4);  
	vect.push_back(5);  
	vect.push_back(6);  
	vect.push_back(7);  
	vect.push_back(8);                               // ��ʱvect��size��СΪ8  

	cout << vect.size() << endl;  
	cout << vect.capacity() << endl;  

	vect.resize(6);                                   // �˴�����vect�Ĵ�С�ȵ�ǰvect��Ԫ������С����û��ָ����ʼ��ֵ  

	cout << "size1 = " << vect.size() << endl;  
	cout << "capacity1 = " << vect.capacity() << endl;  

	for (i = 0 ; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(4, 10);                              // �˴�����vect�Ĵ�СΪ4����ǰ���6С����ָ���˳�ʼ��ֵ�����Ƿ��ı�ǰ�ĸ�Ԫ�ص�ֵ  

	cout << "size1_1 = " << vect.size() << endl;  
	cout << "capacity1_1 = " << vect.capacity() << endl;  

	for (i = 0 ; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(12, 7);                         // �˴�����vect�Ĵ�СΪ8�����ڵ�ǰvect�Ĵ�С4������С��vect�ĵ�ǰ����10��ָ����ʼ��ֵΪ7  

	cout << "size2= " << vect.size() << endl;  

	cout << "capacity2 = " << vect.capacity() << endl;  

	for (int i = 0 ; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(10);                           // �˴�����vect�Ĵ�СΪ10�����ڵ�ǰvect�Ĵ�С8�����ǵ���vect�ĵ�ǰ����10��û��ָ����ʼ��ֵ������Ĭ��ֵ  

	cout << "size3 = " << vect.size() << endl;  
	cout << "capacity3 = " << vect.capacity() << endl;  

	for (int i = 0; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(12, 77);                 // �˴�����vect�Ĵ�СΪ10���������ڵ�ǰvect�Ĵ�С10��������vect�ĵ�ǰ����10����Ϊvect���·���洢�ռ�  

	cout << "size4 = " << vect.size() << endl;  
	cout << "capacity4 = " << vect.capacity() << endl;  

	for (int i = 0; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	return 0;
}