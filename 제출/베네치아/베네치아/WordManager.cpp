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

	if (m_Word != NULL)
		AddWord(m_strList[choice], m_Word);
	else
	{
		m_Word = new Word;
		m_Word->SetName(m_strList[choice]);
	}
}

void WordManager::AddWord(string name, Word* nextWord)
{
	if (nextWord->GetNextWord() != NULL)
		AddWord(name, nextWord->GetNextWord());
	else
	{
		Word* tmp = new Word;
		tmp->SetName(name);
		nextWord->SetNextWord(tmp);
	}
}

int WordManager::DropWord()
{
	int num = 0;

	if (m_Word != NULL)
	{
		m_Word++;

		if (m_Word->Gety() >= ENDY)
		{
			Word* tmp = m_Word->GetNextWord();
			delete m_Word;
			m_Word = tmp;
			num++;
			num += DropWord(m_Word);
		}
		else
			num += DropWord(m_Word->GetNextWord());
	}

	return num;
}

int WordManager::DropWord(Word* nextWord)
{
	int num = 0;

	if (nextWord != NULL)
	{
		nextWord++;

		if (nextWord->Gety() >= ENDY)
		{
			Word* tmp = nextWord->GetNextWord();
			delete nextWord;
			nextWord = tmp;
			num++;
			num += DropWord(nextWord);
		}
		else
			num += DropWord(nextWord->GetNextWord());
	}

	return num;
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

bool WordManager::CheckWord(string name)
{
	if (m_Word != NULL)
	{
		if (m_Word->GetName() == name)
		{
			Word* tmp = m_Word->GetNextWord();
			delete m_Word;
			m_Word = tmp;
			return true;
		}
		else
			return CheckWord(name, m_Word->GetNextWord());
	}
	else
		return false;
}

bool WordManager::CheckWord(string name, Word* nextWord)
{
	if (nextWord != NULL)
	{
		if (nextWord->GetName() == name)
		{
			Word* tmp = nextWord->GetNextWord();
			delete nextWord;
			nextWord = tmp;
			return true;
		}
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
