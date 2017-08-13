#include <deque> //头尾都可插入，取出
#include <iostream>

int main()
{
	std::deque<int> DequeTest;
	DequeTest.push_front(1);//从头部插入元素
	DequeTest.push_front(2);
	DequeTest.push_front(3);

	std::cout << DequeTest.back() << std::endl;
	std::cout << DequeTest.back() << std::endl;
	DequeTest.pop_back();
	std::cout << DequeTest.back() << std::endl;
	DequeTest.pop_front();

	DequeTest.emplace(DequeTest.begin() + 1, 20);//在指定位置插入元素

	system("pause");

	return 0;
}