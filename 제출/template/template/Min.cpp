#include "Min.h"


template <typename Type>
Min<Type>::Min(Type t1, Type t2)
{
	m_tType1 = t1;
	m_tType2 = t2;
}

template <typename Type>
void Min<Type>::Calc()
{
	cout << "ÃÖ¼Ò°ª : ";
	if (m_tType1 <= m_tType2)
		cout << m_tType1 << endl;
	else
		cout << m_tType2 << endl;
}

template <typename Type>
Min<Type>::~Min()
{
}
