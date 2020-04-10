#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

typedef string LData;
typedef struct _node
{
	LData data;
	struct _node * next;
} Node;
typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	//int(*comp)(LData d1, LData d2);
} LinkedList;
typedef LinkedList List;
void ListInit(List* plist); // 초기화
template <typename Type>
void LInsert(List* plist, Type data); // 데이터 저장
template <typename Type>
int LFirst(List* plist, Type* pdata); // 첫 데이터 참조
template <typename Type>
int LNext(List* plist, Type* pdata); // 두 번째 이후 데이터 참조
LData LRemove(List* plist); // 참조한 데이터 삭제
int LCount(List* plist); // 저장된 데이터의 수 반환