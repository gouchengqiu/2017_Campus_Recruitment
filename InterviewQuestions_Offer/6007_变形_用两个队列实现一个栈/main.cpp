#include <queue>
#include <exception>
#include <iostream>

template<typename T>
class CStack
{
public:
	void push(const T& vData);
	T    pop();


private:
	std::queue<T> m_Queue1;
	std::queue<T> m_Queue2;
};

template<typename T>
T CStack<T>::pop()
{
	int Head = -1;
	if (m_Queue2.empty())
	{
		if (m_Queue1.empty())
		{
			throw std::exception("The stack is empty.");
		}
		while (m_Queue1.size() > 1)
		{
			m_Queue2.push(m_Queue1.front());
			m_Queue1.pop();
		}

		Head = m_Queue1.front();
		m_Queue1.pop();
		return Head;
	}
	else
	{
		if (m_Queue2.empty())
		{
			throw std::exception("The stack is empty.");
		}

		while (m_Queue2.size() > 1)
		{
			m_Queue1.push(m_Queue2.front());
			m_Queue2.pop();
		}

		Head = m_Queue2.front();
		m_Queue2.pop();
		return Head;
	}
}

template<typename T>
void CStack<T>::push(const T& vData)
{
	if (!m_Queue2.empty())
	{
		m_Queue2.push(vData);
	}
	else
	{
		m_Queue1.push(vData);
	}
}

void test(int vResult, int vExcepted)
{
	if (vResult == vExcepted)
	{
		std::cout << "Test pass.\n";
	}
	else
	{
		std::cout << "Test failed.\n";
	}
}

int main()
{
	CStack<int> Stack;
	Stack.push(1);
	Stack.push(2);
	Stack.push(3);

	int Head = Stack.pop();
	test(Head, 3);

	Head = Stack.pop();
	test(Head, 2);

	Stack.push(4);
	Stack.push(5);

	Head = Stack.pop();
	test(Head, 5);

	Head = Stack.pop();
	test(Head, 4);

	Head = Stack.pop();
	test(Head, 1);

	return 0;
}