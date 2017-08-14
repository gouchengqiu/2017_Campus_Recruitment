#include "Test.h"

void fun(CTest vTest)
{
	vTest.getData();
	std::cout << "Exec getData...\n";
}

int main()
{
	CTest A; //默认构造
	CTest B(A);   //这个和下面行一样 都是拷贝构造函数
	CTest C = A; //注意这里的对象初始化要调用拷贝构造函数，而非赋值  就类对象而言，相同类型的类对象是通过拷贝构造函数来完成整个复制过程的。
	CTest D;
	D = A;  //赋值
	fun(A);
}

//就是我们自定义的拷贝构造函数。可见，拷贝构造函数是一种特殊的构造函数，函数的名称必须和类名称一致，它必须的一个参数是本类型的一个引用变量。
//拷贝构造函数 http://blog.csdn.net/lwbeyond/article/details/6202256/