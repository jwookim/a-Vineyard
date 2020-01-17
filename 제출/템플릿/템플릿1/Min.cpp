#include "Min.h"


template <typename Type>
Min<Type>::Min()
{
}

template <typename Type>
void Min<Type>::Input()
{
	cout << "(최소값) 비교할 두 수를 입력하세요 : ";
	cin >> m_tType1 >> m_tType2;
}

template <typename Type>
void Min<Type>::Calc()
{
	cout << "최소값 : ";
	if (m_tType1 <= m_tType2)
		cout << m_tType1 << endl;
	else
		cout << m_tType2 << endl;
}

template <typename Type>
Min<Type>::~Min()
{
}
