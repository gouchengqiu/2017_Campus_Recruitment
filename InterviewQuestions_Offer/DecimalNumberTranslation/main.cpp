#include<iostream>
#include <string>
using namespace std;
const int StackSize=1024;

class Seqstack
{
public:
	Seqstack(){top=-1;}//���캯������ʼ����ջ

	void Push(int x);//��ջ
	int  Pop();//��ջ
	bool Empty();//�б�ջ�Ƿ�Ϊ��
	void Trans(int Num,int N);//�������ܣ���ʮ���Ƶ���Numת��ΪN����

private:
	int data[StackSize];//��������
	int top;//ջ��ָ��
};

void Seqstack::Push(int x)
{
	if(top>=StackSize-1)throw"����";
	top++;
	data[top]=x;
}

int Seqstack::Pop()
{
	if(Empty())throw"����";
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
 	cout<<"��ʮ������Numת����N���������������Num,N"<<endl;
 	cin>>Num>>N;
 	// while(Num)
 	{ s.Trans(Num,N);}
}