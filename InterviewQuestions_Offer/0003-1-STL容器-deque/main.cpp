#include <deque> //ͷβ���ɲ��룬ȡ��
#include <iostream>

int main()
{
	std::deque<int> DequeTest;
	DequeTest.push_front(1);//��ͷ������Ԫ��
	DequeTest.push_front(2);
	DequeTest.push_front(3);

	std::cout << DequeTest.back() << std::endl;
	std::cout << DequeTest.back() << std::endl;
	DequeTest.pop_back();
	std::cout << DequeTest.back() << std::endl;
	DequeTest.pop_front();

	DequeTest.emplace(DequeTest.begin() + 1, 20);//��ָ��λ�ò���Ԫ��

	system("pause");

	return 0;
}