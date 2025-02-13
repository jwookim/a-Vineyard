#include "BSTree.h"

BSTree::BSTree()
{
	m_RootNode = NULL;
}

bool BSTree::Insert(Data data)
{
	if (m_RootNode != NULL)
		return Insert(m_RootNode, data);

	BSTNode* newNode = new BSTNode;
	newNode->data = data;
	newNode->LNode = NULL;
	newNode->RNode = NULL;
	m_RootNode = newNode;
	return true;
}

bool BSTree::Insert(BSTNode* node, Data data)
{
	if (node->data->GetPosition() > data->GetPosition())
	{
		if (node->LNode != NULL)
			return Insert(node->LNode, data);
		BSTNode* newNode = new BSTNode;
		newNode->data = data;
		newNode->LNode = NULL;
		newNode->RNode = NULL;
		node->LNode = newNode;
		return true;
	}
	else if (node->data->GetPosition() < data->GetPosition())
	{
		if (node->RNode != NULL)
			return Insert(node->RNode, data);
		BSTNode* newNode = new BSTNode;
		newNode->data = data;
		newNode->LNode = NULL;
		newNode->RNode = NULL;
		node->RNode = newNode;
		return true;
	}
	else if (node->data->GetPosition() == data->GetPosition())
		return false;
}


Data BSTree::Search(Position target)
{
	return Search(m_RootNode, target);
}

Data BSTree::Search(BSTNode* snode, Position target)
{
	if (snode != NULL)
	{
		if (snode->data->GetPosition() == target)
			return snode->data;
		else if (snode->data->GetPosition() > target)
			return Search(snode->LNode, target);
		else if (snode->data->GetPosition() < target)
			return Search(snode->RNode, target);
	}
	else
		return NULL;
}

void BSTree::Init()
{
	while (m_RootNode != NULL)
		delete Remove();
}

Data BSTree::Remove()
{
	BSTNode* rnode = m_RootNode;
	Data rdata = m_RootNode->data;

	if (m_RootNode->RNode != NULL)
	{
		m_RootNode = RemoveCheck(&(m_RootNode->RNode));
		m_RootNode->RNode = rnode->RNode;
		m_RootNode->LNode = rnode->LNode;
	}
	else
		m_RootNode = m_RootNode->LNode;

	delete rnode;

	return rdata;
}

BSTNode* BSTree::RemoveCheck(BSTNode** target)
{
	if ((*target)->LNode != NULL)
		return RemoveCheck(&((*target)->LNode));
	else
	{
		BSTNode* tnode = *target;
		*target = (*target)->RNode;
		return tnode;
	}
}

BSTree::~BSTree()
{
	Init();
}