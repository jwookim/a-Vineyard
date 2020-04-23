#include "Employee.h"

Employee* CreateEmp(int num, char name[NAMELEN])
{
	Employee* emp = new Employee;
	emp->OfficeNum = num;
	strcpy_s(emp->Name, name);

	return emp;
}

void ShowEmp(Employee* emp)
{
	cout << "이름 : " << emp->Name << endl;
	cout << "직원 번호 : " << emp->OfficeNum << endl;
}