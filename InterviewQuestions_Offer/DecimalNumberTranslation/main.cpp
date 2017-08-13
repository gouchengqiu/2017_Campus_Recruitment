#include<iostream>
#include <string>
using namespace std;
const int StackSize=1024;

class Seqstack
{
public:
	Seqstack(){top=-1;}//构造函数，初始化空栈

	void Push(int x);//入栈
	int  Pop();//出栈
	bool Empty();//判别栈是否为空
	void Trans(int Num,int N);//函数功能：将十进制的数Num转换为N进制

private:
	int data[StackSize];//定义数组
	int top;//栈顶指针
};

void Seqstack::Push(int x)
{
	if(top>=StackSize-1)throw"上溢";
	top++;
	data[top]=x;
}

int Seqstack::Pop()
{
	if(Empty())throw"下溢";
	top--;
	return data[top+1];
}

bool Seqstack::Empty()
{
	return top == -1;
}

void Seqstack::Trans(int Num, int N)
{
	int k;
	while(Num)
	{
		k=Num%N;
		Push(k);
		Num=Num/N;
	}
	while(!Empty())
	{
		k=Pop();
		if(k<10)cout<<k;
		else cout<<char(k+55);
	}
}

int main()
{
 	int Num,N;
 	Seqstack s;
 	cout<<"将十进制数Num转换成N进制输出，请输入Num,N"<<endl;
 	cin>>Num>>N;
 	// while(Num)
 	{ s.Trans(Num,N);}
}