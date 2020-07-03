#pragma once
#include<iostream>


template <typename T>
class Singletone
{
private:
	static T* m_hThis;
protected:
	Singletone()
	{
		m_hThis = NULL;
	}
	~Singletone()
	{

	}
public:
	static T* GetInstance()
	{
		if (m_hThis == NULL)
			m_hThis = new T;

		return m_hThis;
	}

	static void DestroyInstance()
	{
		if (m_hThis != NULL)
		{
			delete m_hThis;
			m_hThis = NULL;
		}
	}
};

template<typename T>
T* Singletone<T>::m_hThis = 0;