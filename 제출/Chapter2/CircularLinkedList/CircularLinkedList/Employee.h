#pragma once
#include<iostream>
#include<string.h>
using namespace std;

#define NAMELEN 10
#define TRUE 1
#define FALSE 0

typedef struct _employee
{
	int OfficeNum;
	char Name[NAMELEN];
} Employee;

Employee* CreateEmp(int num, char name[NAMELEN]); // 직원정보 생성

void ShowEmp(Employee* emp); // 정보 열람

