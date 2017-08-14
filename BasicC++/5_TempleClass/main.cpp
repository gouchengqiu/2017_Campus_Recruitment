#pragma  once
#include <iostream>

class Rect
{
public:
	Rect()
	{
		count++;
	}
	~Rect()
	{
		count--;
	}
	Rect::Rect(const Rect& r)//默认的拷贝构造函数
	{  
		width = r.width;  
		height = r.height;
		//count++;
	}
	int getCount() const { return count;}
private:
	int width;
	int height;
	static int count;
};

int Rect::count = 0;

int main()
{
	Rect Rect1;  
	std::cout << "The count of Rect: " << Rect1.getCount() << std::endl;  
	Rect rect2(Rect1);   // 使用rect1复制rect2，此时应该有两个对象  
	std::cout << "The count of Rect: "<<rect2.getCount() << std::endl;  

	return 0;
}
//#include <iostream>
//// 防止按值传递  
//class CExample   
//{  
//private:  
//	int a;  
//
//public:
//	CExample(int b)  
//	{   
//		a = b;  
//		std::cout<< "creat: " << a << std::endl;  
//	}  
//private:  
//	//拷贝构造，只是声明  
//	CExample(const CExample& C);  
//public:  
//	~CExample()  
//	{  
//		std::cout << "delete: " << a << std::endl;  
//	}  
//
//	void Show ()  
//	{  
//		std::cout << a << std::endl;  
//	}  
//}; 
////全局函数  
//void g_Fun(CExample C)  
//{  
//	std::cout << "test" << std::endl;  
//}  
//int main()  
//{  
//	CExample test(1);  
//	//g_Fun(test); 按值传递将出错
//	return 0;  
//}   