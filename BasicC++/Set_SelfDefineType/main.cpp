#include <set>
#include <iostream>
#include <glm\glm.hpp>

int main()
{
	struct SMyCompare
	{
		bool operator () (const glm::vec2& vNumA, const glm::vec2& vNumB) const
		{
			return vNumA.x < vNumB.x && vNumA.y < vNumB.y;
		}
	};
	std::set<glm::vec2, SMyCompare> GTest;  //�����Զ���Ƚ���

	for (unsigned int i=0; i<5; i++)
	{
		GTest.insert(glm::vec2(i, i));
	}

	GTest.insert(glm::vec2(0, 0));  //set��������ظ�Ԫ��

	for (auto& Element : GTest)
	{
		std::cout << Element.x << ", " << Element.y << std::endl;
	}

	system("pause");

	return 0;
}