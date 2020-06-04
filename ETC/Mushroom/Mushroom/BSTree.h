#pragma once
#include"Object.h"

typedef Object* Data;

typedef struct BSTNode
{
	Data data;
	Node* LNode;
	Node* RNode;
}Node;

class BSTree
{
private:
	Node* m_RootNode;
	//Node* m_CureNode;
public:
	BSTree();
	bool Insert(Data data);
	bool Insert(Node* node, Data data);
	Data GetNodeData();
	Data Search(Position target);
	Data Search(Node* snode ,Position target);
	Data Remove();
	//Data Remove(Position target);
	Node* RemoveCheck(Node** target);
	void Init();
	~BSTree();
};

