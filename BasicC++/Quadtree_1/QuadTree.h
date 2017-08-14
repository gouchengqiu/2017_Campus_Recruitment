#ifndef __QUADTREE_H_59CAE94A_E937_42AD_AA27_794E467715BB__  
#define __QUADTREE_H_59CAE94A_E937_42AD_AA27_794E467715BB__  
 
#include <glm/glm.hpp>

/* һ��������������޻��֣�: 
 
UL(1)   |    UR(0) 
----------|----------- 
LL(2)   |    LR(3) 
���¶Ը��������͵�ö�� 
*/  
typedef enum  
{  
    UR = 0,  
    UL = 1,  
    LL = 2,  
    LR = 3  
}QuadrantEnum;  
  
/*�ռ����MBR��Ϣ*/  
typedef struct SHPMBRInfo  
{  
    int nID;        //�ռ����ID��  
    MapRect Box;    //�ռ����MBR��Χ����  
}SHPMBRInfo;  
  
/* �Ĳ����ڵ����ͽṹ */  
typedef struct QuadNode  
{  
    MapRect     Box;            //�ڵ�������ľ�������  
    int         nShpCount;      //�ڵ������������пռ�������  
    SHPMBRInfo* pShapeObj;      //�ռ����ָ������  
    int     nChildCount;        //�ӽڵ����  
    QuadNode  *children[4];     //ָ��ڵ���ĸ�����   
}QuadNode;  
  
/* �Ĳ������ͽṹ */  
typedef struct quadtree_t  
{  
    QuadNode  *root;  
    int        depth;           // �Ĳ��������                      
}QuadTree;  
  
  
    //��ʼ���Ĳ����ڵ�  
    QuadNode *InitQuadNode();  
  
    //��δ����Ĳ������������Ĳ�����  
    void CreateQuadTree(int depth, GeoLayer *poLayer,QuadTree* pQuadTree);  
  
    //����������֧  
    void CreateQuadBranch(int depth,MapRect &rect,QuadNode** node);  
  
    //�����Ĳ����ռ�����  
    void BuildQuadTree(GeoLayer*poLayer,QuadTree* pQuadTree);  
  
    //�Ĳ���������ѯ(���β�ѯ)  
    void SearchQuadTree(QuadNode* node,MapRect &queryRect,vector<int>& ItemSearched);  
  
    //�Ĳ���������ѯ(���β�ѯ)���в�ѯ  
    void SearchQuadTreePara(vector<QuadNode*> resNodes,MapRect &queryRect,vector<int>& ItemSearched);  
  
    //�Ĳ����Ĳ�ѯ�����ѯ��  
    void PtSearchQTree(QuadNode* node,double cx,double cy,vector<int>& ItemSearched);  
  
    //��ָ���Ŀռ������뵽�Ĳ�����  
    void Insert(long key,MapRect &itemRect,QuadNode* pNode);  
  
    //��ָ���Ŀռ������뵽�Ĳ�����  
    void InsertQuad(long key,MapRect &itemRect,QuadNode* pNode);  
  
    //��ָ���Ŀռ������뵽�Ĳ�����  
    void InsertQuad2(long key,MapRect &itemRect,QuadNode* pNode);  
  
    //�ж�һ���ڵ��Ƿ���Ҷ�ӽڵ�  
    bool IsQuadLeaf(QuadNode* node);  
  
    //ɾ������Ľڵ�  
    bool DelFalseNode(QuadNode* node);  
  
    //�Ĳ�������(����Ҫ��)  
    void TraversalQuadTree(QuadNode* quadTree,vector<int>& resVec);  
  
    //�Ĳ������������нڵ㣩  
    void TraversalQuadTree(QuadNode* quadTree,vector<QuadNode*>& arrNode);  
  
    //�ͷ������ڴ�ռ�  
    void ReleaseQuadTree(QuadNode** quadTree);  
  
    //�����Ĳ�����ռ���ֽڵĴ�С  
    long CalByteQuadTree(QuadNode* quadTree,long& nSize);  
  
  
#endif  