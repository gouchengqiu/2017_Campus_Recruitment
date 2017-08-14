#include <iostream>
using namespace std;

//http://www.cnblogs.com/Romi/archive/2012/08/09/2630014.html
//值传递 传递的是实参的一个拷贝 
void swap1(int p,int q)
{   
	int temp;
	temp=p;
	p=q;
	q=temp;
}

//指针传递，函数体内只有指针值的变化
void swap2(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

//指针传递，函数体内只有指针的变化
void swap3(int *p,int *q)
{
	int *temp;
	temp=p;
	p=q;
	q=temp;
}

//引用传递  传入的就是实参 不是副本
void swap4(int &p,int &q)
{
	int temp;
	temp=p;
	p=q;
	q=temp;
}

int main()
{ 
	int a=1,b=2;
	swap1(a,b);
	swap2(&a,&b);
	swap3(&a,&b);
	swap4(a,b);
	cout<<a<<"  "<<b<<endl;
	return 0;
}