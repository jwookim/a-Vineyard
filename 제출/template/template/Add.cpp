#include "Add.h"


template <typename Type>
Add<Type>::Add(Type t)
{
	m_tType = t;
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
