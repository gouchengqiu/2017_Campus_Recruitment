#include <iostream>
#include <vector>
#include <string>

class CRoadMap
{
public:
	CRoadMap();
	~CRoadMap();

	void setString(const std::string& vStr) {m_MyString = vStr;}

	std::string m_MyString;
};

CRoadMap::CRoadMap()
{
	m_MyString = "Initial";
}

CRoadMap::~CRoadMap()
{
}

void fun(std::vector<CRoadMap*>& vVec)
{
	CRoadMap* pRoadMap = new CRoadMap();
	pRoadMap->setString("Hello");
	vVec.push_back(pRoadMap);
}

int main()
{
	std::vector<CRoadMap*> Test;
	fun(Test);

	system("pause");
	return(0);
}