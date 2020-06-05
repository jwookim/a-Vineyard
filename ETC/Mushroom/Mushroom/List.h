#pragma once
#include<iostream>
#include"Position.h"
using namespace std;

#define TRUE 1
#define FALSE 0

template<typename T>
struct LNode
{
	T data;
	LNode* preNode;
	LNode* nextNode;
};

template<typename T>
class List
{
private:
	LNode<T>* m_Head;
	LNode<T>* m_Tail;
	LNode<T>* m_CurNode;
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
	LNode<T>* newHead = new LNode<T>;
	newHead->preNode = NULL;
	m_Head = newHead;

	LNode<T>* newTail = new LNode<T>;
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
	LNode<T>* newNode = new LNode<T>;
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
	LNode<T>* rnode = m_CurNode;
	T rdata = m_CurNode->data;

	m_CurNode->preNode->nextNode = m_CurNode->nextNode;
	m_CurNode->nextNode->preNode = m_CurNode->preNode;
	m_CurNode = m_CurNode->preNode;

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

	delete m_Head, m_Tail;
}