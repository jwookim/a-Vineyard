#include "WordManager.h"



WordManager::WordManager()
{
	WordLoad();
}

void WordManager::AddWord()
{
	int choice = rand() % m_iListSize;

	while(SearchWord(m_strList[choice]))
		choice = rand() % m_iListSize;
}

bool WordManager::SearchWord(string name)
{
	if (m_Word != NULL)
	{
		if (m_Word->GetName() == name)
			return true;
		else
			return SearchWord(name, m_Word->GetNextWord());
	}
	else
		return false;
}

bool WordManager::SearchWord(string name, Word* nextWord)
{
	if (nextWord != NULL)
	{
		if (nextWord->GetName() == name)
			return true;
		else
			return SearchWord(name, nextWord->GetNextWord());
	}
	else
		return false;
}

void WordManager::WordLoad()
{
	ifstream load;
	string tmp;

	load.open("Word.txt");

	if (load.is_open())
	{
		load >> m_iListSize;

		m_strList = new string[m_iListSize];

		for (int i = 0; i < m_iListSize; i++)
		{
			load >> tmp;
			m_strList[i] = tmp;
		}
	}
}

WordManager::~WordManager()
{
}
