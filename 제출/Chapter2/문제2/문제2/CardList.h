#pragma once
#include"NameCard.h"
#define LIST_LEN 100

typedef NameCard* LData;

typedef struct __cardlist
{
	NameCard* arr[LIST_LEN];
	int numOfData;
	int curPosition;
} CardList;

typedef CardList List;
void ListInit(List* plist); // 초기화
void LInsert(List* plist, LData data); // 데이터 저장
int LFirst(List* plist, LData* pdata); // 첫 데이터 참조
int LNext(List* plist, LData* pdata); // 두 번째 이후 데이터 참조
void LRemove(List* plist); // 참조한 데이터 삭제
int LCount(List* plist); // 저장된 데이터의 수 반환