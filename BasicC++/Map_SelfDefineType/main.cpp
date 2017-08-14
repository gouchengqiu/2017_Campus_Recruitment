#include <iostream>
#include <map>
#include <glm/glm.hpp>
#include <vector>
#include <algorithm>

bool cmpMapByValue(const std::pair<glm::vec2, float>& PairA, const std::pair<glm::vec2, float>& vPairB)
{
	return PairA.second < vPairB.second;
}

struct SCMP
{
	bool operator () (const glm::vec2& vFirst, const glm::vec2& vSecond) const
	{
		//return vFirst.x < vSecond.x && vFirst.y < vSecond.y; 这样定义比较函数对于glm::vec2不恰当 因为要进行两次比较，即每个vec2要作为vFirst和vSecond都比较一次 这样定义对于glm::vec2(0, 1)和glm::vec2(2, 0)这种
		//第一次glm::vec2(0, 1)小于glm::vec2(2, 0)吗，返回false，说明（2， 0）大于（0， 1）；第二次比较glm::vec2(2, 0)小于glm::vec2(0, 1)吗，返回false，说明（0， 1）大于（2， 0）。矛盾 所以分不出大小
		return vFirst.x != vSecond.x ? vFirst.x < vSecond.x : vFirst.y < vSecond.y;
	}
};

int main()
{
//  	std::map<unsigned int, glm::vec2> BasicTest;
//  	for (unsigned int i=0; i<5; i++)
//  	{
//  		BasicTest.insert(std::map<unsigned int, glm::vec2>::value_type(i, glm::vec2(i, i)));
//  	}


 	std::map<glm::vec2, float, SCMP> PosDistance_Map; 

	PosDistance_Map.insert(std::make_pair<glm::vec2, float>(glm::vec2(1, 1), 7));
 	PosDistance_Map.insert(std::make_pair<glm::vec2, float>(glm::vec2(0, 1), 7));
 	PosDistance_Map.insert(std::make_pair<glm::vec2, float>(glm::vec2(1, 0), 9));

	for (auto& Element : PosDistance_Map)
	{
		std::cout << Element.first.x << ", " << Element.first.y << " : " << Element.second << std::endl;
	}

	//实现map根据value排序
	std::vector<std::pair<glm::vec2, float>> PosDisyanceVector(PosDistance_Map.begin(), PosDistance_Map.end());
	sort(PosDisyanceVector.begin(), PosDisyanceVector.end(), cmpMapByValue);

	for (auto& Element : PosDisyanceVector)
	{
		std::cout << Element.first.x << " " << Element.first.y << " " << Element.second << std::endl;
	}

	return 0;
}