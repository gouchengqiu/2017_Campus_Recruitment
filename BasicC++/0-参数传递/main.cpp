#include <iostream>
using namespace std;

//http://www.cnblogs.com/Romi/archive/2012/08/09/2630014.html
//ֵ���� ���ݵ���ʵ�ε�һ������ 
void swap1(int p,int q)
{   
	int temp;
	temp=p;
	p=q;
	q=temp;
}

//ָ�봫�ݣ���������ֻ��ָ��ֵ�ı仯
void swap2(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

//ָ�봫�ݣ���������ֻ��ָ��ı仯
void swap3(int *p,int *q)
{
	int *temp;
	temp=p;
	p=q;
	q=temp;
}

//���ô���  ����ľ���ʵ�� ���Ǹ���
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