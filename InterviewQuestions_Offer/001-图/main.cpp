#include <iostream>
#include <string>

#define MAX 20

typedef std::string VertexType;
typedef int EdgeWeight;

struct EdgeNode
{
	int m_AdjVex;
	EdgeWeight m_EdgeWeight;
	EdgeNode* m_pNext;

	EdgeNode()
	{
		m_AdjVex = -1;
		m_EdgeWeight = -1;
		m_pNext = NULL;
	}
};

struct AdjList
{
	VertexType m_Data;//顶点的值
	EdgeNode* pFirstEdge;//指示第一条边

	AdjList()
	{
		pFirstEdge = NULL;
		m_Data = " ";
	}
};

struct AdjListGraph
{
	int m_NumVertex;
	int m_NumEdge;
	AdjList m_AdjList[MAX];//邻接表

	AdjListGraph()
	{
		m_NumVertex = 0;
		m_NumEdge = 0;
		for (int i=0; i<MAX; i++)
		{
			m_AdjList[i].m_Data = " ";
			m_AdjList[i].pFirstEdge = NULL;
		}
	}
};

int getIndexByVertexVal(const AdjListGraph& vGraph, const VertexType& vVertexValue)
{
	for (int i=0; i<vGraph.m_NumVertex; ++i)
	{
		if (vGraph.m_AdjList[i].m_Data == vVertexValue)
		return i;
	}

	return -1;
}

bool createDirectionalGraph(AdjListGraph& voGraph)
{
	//AdjListGraph Graph;

	int NumVertex = 3;
	int NumEdge   = 3;

	voGraph.m_NumEdge = NumEdge;
	voGraph.m_NumVertex = NumVertex;

	std::cout << "请输入顶点信息：\n";
	for (int i=0; i<NumVertex; ++i)
	{
		std::cin >> voGraph.m_AdjList[i].m_Data;
		voGraph.m_AdjList[i].pFirstEdge = NULL;
	}

	std::cout << "请输入由两点构成的边:\n";
	for (int i=0; i<NumEdge; ++i)
	{
		VertexType First, Second;
		int Weight = 0.0;
		std::cin >> First >> Second >> Weight;
		int FirstIndex = getIndexByVertexVal(voGraph, First);
		int SecondIndex = getIndexByVertexVal(voGraph, Second);

		if (FirstIndex == -1 || SecondIndex == -1)
		{
			std::cout << "Error Input.\n";
			return false;
		}

		EdgeNode* pNewEdge = new EdgeNode();
		pNewEdge->m_AdjVex = SecondIndex;
		pNewEdge->m_EdgeWeight = Weight;
		pNewEdge->m_pNext = voGraph.m_AdjList[FirstIndex].pFirstEdge;
		
		voGraph.m_AdjList[FirstIndex].pFirstEdge = pNewEdge;//表头插入法
	}

	return true;
}

void destroyGraph(AdjListGraph vGraph)
{
	for (int i=0; i<vGraph.m_NumVertex; ++i)
	{
		EdgeNode* pEdge = vGraph.m_AdjList[i].pFirstEdge;
		while (pEdge)
		{
			EdgeNode* pTemp = pEdge;
			pEdge = pEdge->m_pNext;
			delete pTemp;
		}
		vGraph.m_AdjList[i].pFirstEdge = NULL;
	}

	vGraph.m_NumEdge   = 0;
	vGraph.m_NumVertex = 0;
}

int main()
{
	AdjListGraph Graph;
	createDirectionalGraph(Graph);
	destroyGraph(Graph);
}