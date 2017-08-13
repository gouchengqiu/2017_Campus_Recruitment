#include <iostream>
//#include <deque>
#include <queue>
#include <stack>

struct Graph 
{
	int m_NumVertex;
	int m_NumEdges;
	char* m_pVertex;
	int** m_ppEdgeInfo;

	Graph(int vNumVertex, int vNumEdges)
	{
		m_NumVertex = vNumVertex;
		m_NumEdges  = vNumEdges;

		m_pVertex = new char[m_NumVertex]();
		m_ppEdgeInfo = new int*[m_NumVertex]();
		for (int i=0; i<m_NumVertex; ++i)
		{
			m_ppEdgeInfo[i] = new int[m_NumVertex]();
		}
	}

	Graph()
	{
		m_NumEdges  = 0;
		m_NumVertex = 0;
		m_pVertex = NULL;
		m_ppEdgeInfo = NULL;
	}
};

int getIndexByVertexValue(const Graph* vGraph, char vVertex)
{
	_ASSERT(vGraph);
	for (int i=0; i<vGraph->m_NumVertex; ++i)
	{
		if (vVertex == vGraph->m_pVertex[i])
		{
			return i;
		}
	}
	return -1;
}

void createNonDirectioalGraph(Graph* vGraph, int* vEdgeInfo, int vRow, int vCol) //3:二维数组当一维数组用
{
	_ASSERT(vGraph);

	char Vertex[4] = {'A', 'B', 'C', 'D'};

	for (int i=0; i<vGraph->m_NumVertex; ++i)
	{
		vGraph->m_pVertex[i] = Vertex[i];
		for (int k=0; k<vGraph->m_NumVertex; ++k)
		{
			vGraph->m_ppEdgeInfo[i][k] = vEdgeInfo[vCol * i + k];
		}
	}
}

bool* g_Visised;

void destroyGraph(Graph* vGraph)
{
	_ASSERT(vGraph);

	if (vGraph->m_pVertex)
	{
		delete vGraph->m_pVertex;
		vGraph->m_pVertex = NULL;
	}

	if (vGraph->m_ppEdgeInfo)
	{
		for (int i=0; i<vGraph->m_NumVertex; ++i)
		{
			delete[] vGraph->m_ppEdgeInfo[i];
		}
		delete[] vGraph->m_ppEdgeInfo;
		vGraph->m_ppEdgeInfo = NULL;
	}
	delete vGraph;
}

//基于邻接矩阵的广度优先遍历 （类似二叉树的层次遍历）（不用递归）
void BFSTranverse(const Graph* vGraph)
{
	_ASSERT(vGraph);
	if (vGraph->m_NumVertex <= 0)
	{
		return;
	}

	g_Visised = new bool[vGraph->m_NumVertex]();
	for (int i=0; i<vGraph->m_NumVertex; ++i)
	{
		g_Visised[i] = false;
	}

	std::deque<char> VertexDeque;
	VertexDeque.push_front(vGraph->m_pVertex[0]);

	while (VertexDeque.size() > 0)
	{
		char CurrentVertex = VertexDeque.back();
		VertexDeque.pop_back();

		if (!g_Visised[getIndexByVertexValue(vGraph, CurrentVertex)])
		{
			std::cout << CurrentVertex << " ";//输出访问到的顶点

			int CurrentVertexIndex = getIndexByVertexValue(vGraph, CurrentVertex);
			for (int k=0; k<vGraph->m_NumVertex; ++k)
			{
				if (vGraph->m_ppEdgeInfo[CurrentVertexIndex][k] > 0 && !g_Visised[k])
				{
					VertexDeque.push_front(vGraph->m_pVertex[k]);
				}
			}
			g_Visised[getIndexByVertexValue(vGraph, CurrentVertex)] = true;
		}
		
	}

	delete[] g_Visised;
}

void DFSTranverse(const Graph* vGraph)//非递归实现
{
	_ASSERT(vGraph);
	if (vGraph->m_NumVertex <=0)
	{
		return;
	}

	std::stack<char> WaitVisitedVertexStack;
	WaitVisitedVertexStack.push(vGraph->m_pVertex[0]);

	while (!WaitVisitedVertexStack.empty())
	{
		char Vertex = WaitVisitedVertexStack.top();
		WaitVisitedVertexStack.pop();

		if (!g_Visised[getIndexByVertexValue(vGraph, Vertex)])
		{
			std::cout << Vertex << " ";
			g_Visised[getIndexByVertexValue(vGraph, Vertex)] = true;

			for (int i=0; i<vGraph->m_NumVertex; ++i)
			{
				if (vGraph->m_ppEdgeInfo[getIndexByVertexValue(vGraph, Vertex)][i] > 0 && !g_Visised[i])
				{
					WaitVisitedVertexStack.push(vGraph->m_pVertex[i]);
				}
			}
		}
	}
}

//FUNCTION: detect the memory leak in DEBUG mode
void installMemoryLeakDetector()
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	//_CRTDBG_LEAK_CHECK_DF: Perform automatic leak checking at program exit through a call to _CrtDumpMemoryLeaks and generate an error 
	//report if the application failed to free all the memory it allocated. OFF: Do not automatically perform leak checking at program exit.
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//the following statement is used to trigger a breakpoint when memory leak happens
	//comment it out if there is no memory leak report;
	//_crtBreakAlloc = 19143;
#endif
}

int main()
{
	installMemoryLeakDetector();

	int NumVertex = 4;
	int NumEdges  = 4;

	int EdgeInfo[4][4] = {{0, 4, 2, 3}, 
	{4, 0, 0, 0},
	{2, 0, 0, 5},
	{3, 0, 5, 0}
	};

	Graph* pGraph = new Graph(NumVertex, NumEdges);
	createNonDirectioalGraph(pGraph, &EdgeInfo[0][0], 4, 4);//将数组的第一个元素地址传参，百度二维数组传递参数的三种方法。1， Data[][vCol]  2. Data[vRow][vCol] 3. int*
	
	BFSTranverse(pGraph);
	DFSTranverse(pGraph);
	
	destroyGraph(pGraph);

	system("pause");

	return 0;
}