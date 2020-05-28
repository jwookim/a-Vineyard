#include "BSTree.h"

BSTree::BSTree()
{
	m_RootNode = NULL;
}

bool BSTree::Insert(Data data)
{
	if (m_RootNode != NULL)
		return Insert(m_RootNode, data);

	Node* newNode = new Node;
	newNode->data = data;
	newNode->LNode = NULL;
	newNode->RNode = NULL;
	m_RootNode = newNode;
	return true;
}

bool BSTree::Insert(Node* node, Data data)
{
	if (node->data->GetPosition() > data->GetPosition())
	{
		if (node->LNode != NULL)
			return Insert(node->LNode, data);
		Node* newNode = new Node;
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
		Node* newNode = new Node;
		newNode->data = data;
		newNode->LNode = NULL;
		newNode->RNode = NULL;
		node->RNode = newNode;
		return true;
	}
	else if (node->data->GetPosition() == data->GetPosition())
		return false;
}

Data BSTree::GetNodeData()
{

}

bool BSTree::Search(Position target)
{
	return Search(m_RootNode, target);
}

bool BSTree::Search(Node* snode, Position target)
{
	if (snode->data->GetPosition() == target)
		return true;
	else if (snode->data->GetPosition() > target)
		return Search(snode->LNode, target);
	else if (snode->data->GetPosition() < target)
		return Search(snode->RNode, target);
}

void BSTree::Init()
{
	while (m_RootNode != NULL)
		Remove();
}

void BSTree::Remove()
{
	Node* rnode = m_RootNode;
	Data rdata = m_RootNode->data;

	if (m_RootNode->RNode != NULL)
	{
		m_RootNode = RemoveCheck(&(m_RootNode->RNode));
		m_RootNode->RNode = rnode->RNode;
		m_RootNode->LNode = rnode->LNode;
	}
	else
		m_RootNode = m_RootNode->LNode;

	delete rnode, rdata;
}

Node* BSTree::RemoveCheck(Node** target)
{
	if ((*target)->LNode != NULL)
		return RemoveCheck(&((*target)->LNode));
	else
	{
		Node* tnode = *target;
		*target = (*target)->RNode;
		return tnode;
	}
}

BSTree::~BSTree()
{
	Init();
}