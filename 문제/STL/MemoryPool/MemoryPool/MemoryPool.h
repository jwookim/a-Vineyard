#pragma once
#include<vector>
using namespace std;

template<typename T, int BlokNum = 100>
class MemoryPool
{
private:
	vector<char*> m_Point;
	int m_iNextP;
	int m_iUseableNum;
public:
	MemoryPool()
	{
		m_Point.assign(sizeof(T) * BlokNum, 0);
		m_iNextP = 0;
		m_iUseableNum = 0;

		for (int i = 0; i < sizeof(T) * BlokNum; i += sizeof(T))
		{
			if (i % sizeof(T) == 0)
				m_Point[i] = ++m_iUseableNum;
		}
	}
	~MemoryPool()
	{
		

	}

	void* /*operator new*/Alloc()
	{
		if (!m_iUseableNum)
			return NULL;

		char* ReturnPoint = &m_Point[m_iNextP * sizeof(T)];
		m_iNextP = *ReturnPoint;
		m_iUseableNum--;

		return ReturnPoint;
	}
	void /*operator delete*/DeAlloc(void* target)
	{
		target = m_iNextP;
		m_iNextP = (target - &m_Point[0]) / sizeof(T);
		m_iUseableNum++;
	}
};

