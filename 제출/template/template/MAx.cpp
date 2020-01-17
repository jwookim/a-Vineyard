#include "Max.h"


template <typename Type>
Max<Type>::Max(Type t1, Type t2, Type t3)
{
	m_tType1 = t1;
	m_tType2 = t2;
	m_tType3 = t3;
}


template <typename Type>
void Max<Type>::Calc()
{
	Type tmp = m_tType1;

	if (tmp < m_tType2)
		tmp = m_tType2;
	if (tmp < m_tType3)
		tmp = m_tType3;

	cout << "�ִ밪 : " << tmp << endl;
}

template <typename Type>
Max<Type>::~Max()
{
}
