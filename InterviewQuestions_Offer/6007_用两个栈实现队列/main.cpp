#include <iostream>
#include <stack>
#include <exception>

template<typename T>
class CQueue
{
public:
	void appendTail(const T& vData);
	T deleteHead();

private:
	std::stack<T> m_Stack1;
	std::stack<T> m_Stack2;
};

template<typename T>
T CQueue<T>::deleteHead()
{
	if (m_Stack2.empty())
	{
		throw std::exception("The queue is empty.");
	}

	int TopData = m_Stack2.top();
	m_Stack2.pop();
	return TopData;
}

template<typename T>
void CQueue<T>::appendTail(const T& vData)
{
	while (!m_Stack2.empty())
	{
		m_Stack1.push(m_Stack2.top());
		m_Stack2.pop();
	}

	m_Stack1.push(vData);

	while (!m_Stack1.empty())
	{
		m_Stack2.push(m_Stack1.top());
		m_Stack1.pop();
	}
}

void test(int vResult, int vExcepted)
{
	if (vResult == vExcepted)
	{
		std::cout << "Test passed.\n";
	}
	else
	{
		std::cout << "Test failed.\n";
	}
}

int main()
{
	CQueue<int> Queue;

	Queue.appendTail(1);
	Queue.appendTail(2);
	Queue.appendTail(3);

	int Head = Queue.deleteHead();
	test(Head, 1);

	Queue.appendTail(4);
	Head = Queue.deleteHead();
	test(Head, 2);

	Head = Queue.deleteHead();
	test(Head, 3);

	Queue.appendTail(5);
	Head = Queue.deleteHead();
	test(Head, 4);

	Head = Queue.deleteHead();
	test(Head, 5);

	return 0;
}