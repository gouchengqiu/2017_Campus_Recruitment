#include <stack>
#include <iostream>

template<typename T>
class CSpecialStack
{
public:
	void push(const T& vData);
	void pop();
	const T& min() const;

private:
	std::stack<T>  m_Data;
	std::stack<T> m_MinRecord;
};

template<typename T>
const T& CSpecialStack<T>::min() const
{
	_ASSERT(m_Data.size() > 0 && m_MinRecord.size() > 0);

	return m_MinRecord.top();
}

template<typename T>
void CSpecialStack<T>::pop()
{
	if (m_Data.size() <= 0)
	{
		return;
	}

	if (m_MinRecord.size() > 0)
	{
		m_MinRecord.pop();
	}
	
	m_Data.pop();
}

template<typename T>
void CSpecialStack<T>::push(const T& vData)
{
	m_Data.push(vData);
	if (m_MinRecord.size() > 0)
	{
	   T CurrentMinData = vData < m_MinRecord.top() ? vData : m_MinRecord.top();
	   m_MinRecord.push(CurrentMinData);
	}
	else
	{
		m_MinRecord.push(vData);
	}
}

void test(char* vStr, const CSpecialStack<int>& vStack, int vExceptedData)
{
	std::cout << vStr << " begins: \n";
	if (vStack.min() == vExceptedData)
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
	CSpecialStack<int> Stack;

	Stack.push(3);
	test("test1", Stack, 3);

	Stack.push(4);
	test("test2", Stack, 3);

	Stack.push(2);
	test("test3", Stack, 2);

	Stack.push(1);
	test("test4", Stack, 1);

	Stack.pop();
	test("test5", Stack, 2);

	Stack.pop();
	test("test6", Stack, 3);

	Stack.pop();
	test("test7", Stack, 3);

	return 0;
}