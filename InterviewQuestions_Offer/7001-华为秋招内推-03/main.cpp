#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

struct SListedNode
{
	unsigned int m_Val;
	SListedNode* m_pNext;

	SListedNode() : m_Val(0), m_pNext(nullptr) {}
	SListedNode(unsigned int vVal) : m_Val(vVal), m_pNext(nullptr) {}
};


SListedNode* g_pListHeadNode = nullptr;
std::vector<SListedNode*> g_HeadNodeSet;

//***********************************************************
//FUNCTION::
SListedNode* findNodePos(unsigned int vNumber)
{
	for (int i=0;i<g_HeadNodeSet.size(); i++)
	{
		SListedNode* pHeadNode = g_HeadNodeSet[i];

		SListedNode* pTempNode = pHeadNode;
		while (pTempNode)
		{
			if (pTempNode->m_Val == vNumber)
			{
				return pTempNode;
			}
			else
			{
				pTempNode = pTempNode->m_pNext;
			}
		}
	}

	return nullptr;
}

//***********************************************************
//FUNCTION::
void addDependency(unsigned int Moduled, unsigned int DependModuleld)
{
	if (g_pListHeadNode == nullptr)
	{
		SListedNode* pTempNode = new SListedNode(Moduled);
		g_pListHeadNode = pTempNode;

		SListedNode* pTempNode2 = new SListedNode(DependModuleld);
		pTempNode->m_pNext = pTempNode2;

		g_HeadNodeSet.push_back(pTempNode);
		return;
	}

	SListedNode* pModuleNode = findNodePos(Moduled);
	SListedNode* pDependNode = findNodePos(DependModuleld);

	if (pModuleNode == nullptr)
	{
		pModuleNode = new SListedNode(Moduled);
		g_HeadNodeSet.push_back(pModuleNode);
	}
	if (pDependNode == nullptr)
	{
		pDependNode = new SListedNode(DependModuleld);
	}

	pModuleNode->m_pNext = pDependNode;
}

//***********************************************************
//FUNCTION::
bool isCircle(SListedNode* vListNode)
{
	SListedNode* pFastNode = vListNode;
	SListedNode* pSlowNode = vListNode;

	while (pFastNode != nullptr && pFastNode->m_pNext != nullptr)
	{
		pFastNode = pFastNode->m_pNext->m_pNext;
		pSlowNode = pSlowNode->m_pNext;

		if (pFastNode == pSlowNode)
			return true;
	}

	return false;

}

//***********************************************************
//FUNCTION::
bool MouldelsCycularDependency(unsigned int Moduleld)
{
	for (int i=0; i<g_HeadNodeSet.size(); i++)
	{
		SListedNode* pHeadNode = g_HeadNodeSet[i];
		SListedNode* pTempNode = pHeadNode;

		while (pTempNode)
		{
			if (pTempNode->m_Val == Moduleld)
			{
				bool bResult = isCircle(pTempNode);

				return bResult;
			}
			else
				pTempNode = pTempNode->m_pNext;
		}
	}
}

long hex2int(const std::string& hexStr)
{
	char *offset;
	if (hexStr.length() > 2)
	{
		if (hexStr[0] == '0' && hexStr[1] == 'x')
		{
			return strtol(hexStr.c_str(), &offset, 0);
		}
	}
	return strtol(hexStr.c_str(), &offset, 16);
}

//***********************************************************
//FUNCTION::
bool spilt(const std::string& vInputString, unsigned int& vNumber1, unsigned int& vNumber2)
{
	int iCommaNum = std::count(vInputString.begin(), vInputString.end(), ',');
	bool bResult = true;
	if (iCommaNum == 1) bResult = false;

	std::string Temp;
	std::vector<unsigned int> NumberVec;
	for (int i=0; i<vInputString.size(); i++)
	{
		if (isdigit(vInputString[i]) || vInputString[i] == 'x')
		{
			Temp.append(1, vInputString[i]);
		}
		else
		{
			if (!Temp.empty())
			{
				//std::stringstream SS(Temp);
	
				unsigned int Number = 0; //atoi(Temp.c_str());
				Number = hex2int(Temp);
				//SS >> Number;
				NumberVec.push_back(Number);
			}
			Temp.clear();
		}
	}

	vNumber1 = NumberVec[0];
	vNumber2 = NumberVec[1];

	return bResult;
}

int main()
{
	std::string InputString;

	std::set<unsigned int> InputNumber;
	while (getline(std::cin, InputString))
	{
		unsigned int Number1 = 0, Number2 = 0;
		bool bResult = spilt(InputString, Number1, Number2);
		InputNumber.insert(Number1);
		InputNumber.insert(Number2);

		addDependency(Number1, Number2);
		if (!bResult)
		{
			break;
		}
	}

	unsigned int uiIndex = 1;
	for (auto Itr= InputNumber.begin(); Itr!= InputNumber.end(); Itr++)
	{
		
		unsigned int uiNumber = *Itr;

		bool bResult = MouldelsCycularDependency(uiNumber);

		if (uiIndex == InputNumber.size())
		{
			if (bResult)
				printf("{0x%02x, true}\n", uiNumber);
			else
				printf("{0x%02x, false}\n", uiNumber);
		}
		else
		{
			if (bResult)
				printf("{0x%02x, true},\n", uiNumber);
			else
				printf("{0x%02x, false},\n", uiNumber);
		}
	
		uiIndex++;
	}

	return 0;
}