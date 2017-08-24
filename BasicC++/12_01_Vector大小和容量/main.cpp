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
	vect.push_back(8);                               // 此时vect的size大小为8  

	cout << vect.size() << endl;  
	cout << vect.capacity() << endl;  

	vect.resize(6);                                   // 此处设置vect的大小比当前vect中元素数量小，且没有指定初始化值  

	cout << "size1 = " << vect.size() << endl;  
	cout << "capacity1 = " << vect.capacity() << endl;  

	for (i = 0 ; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(4, 10);                              // 此处设置vect的大小为4，比前面的6小，且指定了初始化值，看是否会改变前四个元素的值  

	cout << "size1_1 = " << vect.size() << endl;  
	cout << "capacity1_1 = " << vect.capacity() << endl;  

	for (i = 0 ; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(12, 7);                         // 此处设置vect的大小为8，大于当前vect的大小4，但是小于vect的当前容量10，指定初始化值为7  

	cout << "size2= " << vect.size() << endl;  

	cout << "capacity2 = " << vect.capacity() << endl;  

	for (int i = 0 ; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(10);                           // 此处设置vect的大小为10，大于当前vect的大小8，但是等于vect的当前容量10，没有指定初始化值，采用默认值  

	cout << "size3 = " << vect.size() << endl;  
	cout << "capacity3 = " << vect.capacity() << endl;  

	for (int i = 0; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	vect.resize(12, 77);                 // 此处设置vect的大小为10，不仅大于当前vect的大小10，还大于vect的当前容量10，会为vect重新分配存储空间  

	cout << "size4 = " << vect.size() << endl;  
	cout << "capacity4 = " << vect.capacity() << endl;  

	for (int i = 0; i < vect.size(); i++)  
	{  
		cout << vect[i] << endl;  
	}  

	return 0;
}