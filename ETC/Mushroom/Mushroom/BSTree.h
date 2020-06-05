#pragma once
#include"Object.h"

typedef Object* Data;

struct BSTNode
{
	Data data;
	BSTNode* LNode;
	BSTNode* RNode;
};

class BSTree
{
private:
	BSTNode* m_RootNode;
	//Node* m_CureNode;
public:
	BSTree();
	bool Insert(Data data);
	bool Insert(BSTNode* node, Data data);
	Data Search(Position target);
	Data Search(BSTNode* snode ,Position target);
	Data Remove();
	//Data Remove(Position target);
	BSTNode* RemoveCheck(BSTNode** target);
	void Init();
	~BSTree();
};

