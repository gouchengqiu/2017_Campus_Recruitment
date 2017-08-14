#include <queue>
#include <glm/glm.hpp>
#include <iostream>

//ʹ�� (left < right) �ıȽϷ�ʽ������ʽ�������򣬼���С���󣻷�֮������� (left > right)�������򡢴Ӵ�С����
struct SCMP
{
	bool operator () (const glm::vec2& vLeft, const glm::vec2& vRight) const
	{
		//return vFirst.x < vSecond.x && vFirst.y < vSecond.y; ��������ȽϺ�������glm::vec2��ǡ�� ��ΪҪ�������αȽϣ���ÿ��vec2Ҫ��ΪvFirst��vSecond���Ƚ�һ�� �����������glm::vec2(0, 1)��glm::vec2(2, 0)����
		//��һ��glm::vec2(0, 1)С��glm::vec2(2, 0)�𣬷���false��˵����2�� 0�����ڣ�0�� 1�����ڶ��αȽ�glm::vec2(2, 0)С��glm::vec2(0, 1)�𣬷���false��˵����0�� 1�����ڣ�2�� 0����ì�� ���Էֲ�����С
		return vLeft.x != vRight.x ? vLeft.x < vRight.x : vLeft.y < vRight.y;
	}
};

int main()
{
	std::priority_queue<glm::vec2, std::vector<glm::vec2>, SCMP> PriorityQueueTest;
	PriorityQueueTest.push(glm::vec2(1, 1));
	PriorityQueueTest.push(glm::vec2(2, 2));
	PriorityQueueTest.push(glm::vec2(5, 5));
	PriorityQueueTest.push(glm::vec2(9, 9));
	PriorityQueueTest.push(glm::vec2(3, 3));

	while (!PriorityQueueTest.empty())
	{
		std::cout << PriorityQueueTest.top().x << " " << PriorityQueueTest.top().y << std::endl;
		PriorityQueueTest.pop();
	}
}