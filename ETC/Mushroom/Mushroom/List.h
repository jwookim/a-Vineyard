#pragma once
#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

template<typename T>
struct Node
{
	T data;
	Node* preNode;
	Node* nextNode;
};

template<typename T>
class List
{
private:
	Node<T>* m_Head;
	Node<T>* m_Tail;
	Node<T>* m_CurNode;
	int m_iNumOfData;
public:
	List();
	/*void Init();*/
	void Insert(T data);
	int First();
	int Next();
	int ToTail();
	T ViewNode();
	T Remove();
	int GetNumOfData();
	~List();
};

template<typename T>
List<T>::List()
{
	Node<T>* newHead = new Node<T>;
	newHead->preNode = NULL;
	m_Head = newHead;

	Node<T>* newTail = new Node<T>;
	newTail->nextNode = NULL;
	m_Tail = newTail;

	newHead->nextNode = newTail;
	newTail->preNode = newHead;

	m_iNumOfData = 0;
}

//template<typename T>
//void List<T>::Init()
//{
//
//}

template<typename T>
void List<T>::Insert(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->preNode = m_Head;
	newNode->nextNode = m_Head->nextNode;
	
	m_Head->nextNode->preNode = newNode;
	m_Head->nextNode = newNode;

	m_iNumOfData++;
}

template<typename T>
int List<T>::First()
{
	if (m_Head->nextNode == m_Tail)
		return FALSE;

	m_CurNode = m_Head->nextNode;

	return TRUE;
}

template<typename T>
int List<T>::Next()
{
	if (m_CurNode->nextNode == m_Tail)
		return FALSE;

	m_CurNode = m_CurNode->nextNode;

	return TRUE;
}

template<typename T>
int List<T>::ToTail()
{
	if (m_Head->nextNode == m_Tail)
		return FALSE;

	m_CurNode = m_Tail->preNode;

	return TRUE;
}

template<typename T>
T List<T>::ViewNode()
{
	return m_CurNode->data;
}

template<typename T>
T List<T>::Remove()
{
	Node<T>* rnode = m_CurNode;
	T rdata = m_CurNode->data;

	m_CurNode->preNode->nextNode = m_CurNode->nextNode;
	m_CurNode->nextNode->preNode = m_CurNode->preNode;
	m_CurNode = m_CureNode->preNode;

	delete rnode;
	m_iNumOfData--;

	return rdata;
}

template<typename T>
int List<T>::GetNumOfData()
{
	return m_iNumOfData;
}

template<typename T>
List<T>::~List()
{
	while (First())
	{
		Remove();
	}

	delete m_Head, m_Tail
}