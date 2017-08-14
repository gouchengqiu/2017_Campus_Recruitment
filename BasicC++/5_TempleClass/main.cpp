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
	Rect::Rect(const Rect& r)//Ĭ�ϵĿ������캯��
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
	Rect rect2(Rect1);   // ʹ��rect1����rect2����ʱӦ������������  
	std::cout << "The count of Rect: "<<rect2.getCount() << std::endl;  

	return 0;
}
//#include <iostream>
//// ��ֹ��ֵ����  
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
//	//�������죬ֻ������  
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
////ȫ�ֺ���  
//void g_Fun(CExample C)  
//{  
//	std::cout << "test" << std::endl;  
//}  
//int main()  
//{  
//	CExample test(1);  
//	//g_Fun(test); ��ֵ���ݽ�����
//	return 0;  
//}   