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
		//return vFirst.x < vSecond.x && vFirst.y < vSecond.y; ��������ȽϺ�������glm::vec2��ǡ�� ��ΪҪ�������αȽϣ���ÿ��vec2Ҫ��ΪvFirst��vSecond���Ƚ�һ�� �����������glm::vec2(0, 1)��glm::vec2(2, 0)����
		//��һ��glm::vec2(0, 1)С��glm::vec2(2, 0)�𣬷���false��˵����2�� 0�����ڣ�0�� 1�����ڶ��αȽ�glm::vec2(2, 0)С��glm::vec2(0, 1)�𣬷���false��˵����0�� 1�����ڣ�2�� 0����ì�� ���Էֲ�����С
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

	//ʵ��map����value����
	std::vector<std::pair<glm::vec2, float>> PosDisyanceVector(PosDistance_Map.begin(), PosDistance_Map.end());
	sort(PosDisyanceVector.begin(), PosDisyanceVector.end(), cmpMapByValue);

	for (auto& Element : PosDisyanceVector)
	{
		std::cout << Element.first.x << " " << Element.first.y << " " << Element.second << std::endl;
	}

	return 0;
}