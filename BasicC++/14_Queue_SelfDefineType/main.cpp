#include <queue>
#include <glm/glm.hpp>
#include <iostream>

//使用 (left < right) 的比较方式，排序方式就是升序，即从小到大；反之，如果用 (left > right)，将降序、从大到小排序。
struct SCMP
{
	bool operator () (const glm::vec2& vLeft, const glm::vec2& vRight) const
	{
		//return vFirst.x < vSecond.x && vFirst.y < vSecond.y; 这样定义比较函数对于glm::vec2不恰当 因为要进行两次比较，即每个vec2要作为vFirst和vSecond都比较一次 这样定义对于glm::vec2(0, 1)和glm::vec2(2, 0)这种
		//第一次glm::vec2(0, 1)小于glm::vec2(2, 0)吗，返回false，说明（2， 0）大于（0， 1）；第二次比较glm::vec2(2, 0)小于glm::vec2(0, 1)吗，返回false，说明（0， 1）大于（2， 0）。矛盾 所以分不出大小
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