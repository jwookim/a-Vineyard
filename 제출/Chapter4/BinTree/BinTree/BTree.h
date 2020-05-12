#pragma once
#include<iostream>
using namespace std;

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;BTreeNode* MakeBTreeNode();BTreeNode* MakeBTreeNode(BTData data);void ShowTree(BTreeNode* bt);void ShowNode(BTreeNode* bt);void DeleteTree(BTreeNode* bt);void DeleteNode(BTreeNode* bt);typedef void VisitFuncPtr(BTreeNode* bt); //방문 목적을 전달받을 함수 포인터

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);