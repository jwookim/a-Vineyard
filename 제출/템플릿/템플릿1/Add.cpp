#include "Add.h"


template <typename Type>
Add<Type>::Add()
{
}

template <typename Type>
void Add<Type>::Input()
{
	cout << "더할 값을 입력하세요 : ";
	cin >> m_tType;
}

template <typename Type>
void Add<Type>::add()
{
	cout << "값 1 증가" << endl;
	m_tType++;
}

template <typename Type>
void Add<Type>::Print()
{
	cout << "더해진 값 : " << m_tType << endl;
}

template <typename Type>
Add<Type>::~Add()
{
}
