#include "WordManager.h"



WordManager::WordManager()
{
	WordLoad();
	//WordInit();
}
//
//void WordManager::AddWord()
//{
//	int choice = rand() % m_iListSize;
//
//	while(SearchWord(m_strList[choice]))
//		choice = rand() % m_iListSize;
//
//	if (m_Word != NULL)
//		AddWord(m_strList[choice], m_Word);
//	else
//	{
//		m_Word = new Word;
//		m_Word->SetName(m_strList[choice]);
//	}
//}
//
//void WordManager::AddWord(string name, Word* nextWord)
//{
//	if (nextWord->GetNextWord() != NULL)
//		AddWord(name, nextWord->GetNextWord());
//	else
//	{
//		Word* tmp = new Word;
//		tmp->SetName(name);
//		nextWord->SetNextWord(tmp);
//	}
//}
//
//int WordManager::DropWord()
//{
//	int num = 0;
//
//	if (m_Word != NULL)
//	{
//		m_Word->Drop();
//
//		if (m_Word->Gety() > HEIGHT)
//		{
//			Word* tmp = m_Word->GetNextWord();
//			delete m_Word;
//			m_Word = tmp;
//			num++;
//			num += DropWord(m_Word);
//		}
//		else
//			num += DropWord(m_Word->GetNextWord());
//	}
//
//	return num;
//}
//
//int WordManager::DropWord(Word* nextWord)
//{
//	int num = 0;
//
//	if (nextWord != NULL)
//	{
//		nextWord->Drop();
//
//		if (nextWord->Gety() > HEIGHT)
//		{
//			Word* tmp = nextWord->GetNextWord();
//			delete nextWord;
//			nextWord = tmp;
//			num++;
//			num += DropWord(nextWord);
//		}
//		else
//			num += DropWord(nextWord->GetNextWord());
//	}
//
//	return num;
//}
//
//bool WordManager::SearchWord(string name)
//{
//	if (m_Word != NULL)
//	{
//		if (m_Word->GetName() == name)
//			return true;
//		else
//			return SearchWord(name, m_Word->GetNextWord());
//	}
//	else
//		return false;
//}
//
//bool WordManager::SearchWord(string name, Word* nextWord)
//{
//	if (nextWord != NULL)
//	{
//		if (nextWord->GetName() == name)
//			return true;
//		else
//			return SearchWord(name, nextWord->GetNextWord());
//	}
//	else
//		return false;
//}
//
//EFFECT WordManager::CheckWord(string name)
//{
//	/*if (m_Word != NULL)
//	{
//		if (m_Word->GetName() == name)
//		{
//			Word* tmp = m_Word->GetNextWord();
//			EFFECT Effect = m_Word->GetEffect();
//			delete m_Word;
//			m_Word = tmp;
//			return Effect;
//		}
//		else
//			return CheckWord(name, m_Word->GetNextWord());
//	}
//	else
//		return EFFECT_NULL;*/
//
//	if (m_Word != NULL)
//	{
//		if (m_Word->GetName() == name)
//		{
//			Word* tmp = m_Word->GetNextWord();
//			EFFECT Effect = m_Word->GetEffect();
//			delete m_Word;
//			m_Word = tmp;
//			return Effect;
//		}
//		else
//		{
//			if (m_Word->GetNextWord() != NULL)
//			{
//				if (m_Word->GetNextWord()->GetName() == name)
//				{
//					Word* tmp = m_Word->GetNextWord()->GetNextWord();
//					EFFECT Effect = m_Word->GetNextWord()->GetEffect();
//					delete m_Word->GetNextWord();
//					m_Word->SetNextWord(tmp);
//					return Effect;
//				}
//			}
//			else
//				return CheckWord(name, m_Word->GetNextWord());
//		}
//	}
//	else
//		return EFFECT_NULL;
//}
//
//EFFECT WordManager::CheckWord(string name, Word* nextWord)
//{
//	if (nextWord->GetNextWord() != NULL)
//	{
//		if (nextWord->GetNextWord()->GetName() == name)
//		{
//			Word* tmp = nextWord->GetNextWord()->GetNextWord();
//			EFFECT Effect = nextWord->GetNextWord()->GetEffect();
//			delete nextWord->GetNextWord();
//			nextWord->SetNextWord(tmp);
//			return Effect;
//		}
//		else
//			return CheckWord(name, nextWord->GetNextWord());
//	}
//	else
//		return EFFECT_NULL;
//}
//
//int WordManager::Clear()
//{
//	int len = 0;
//	if (m_Word != NULL)
//	{
//		len += m_Word->GetName().length();
//		len += Clear(m_Word->GetNextWord());
//		delete m_Word;
//		m_Word = NULL;
//		return len;
//	}
//	else
//		return NULL;
//}
//
//int WordManager::Clear(Word* nextWord)
//{
//	int len = 0;
//	if (nextWord != NULL)
//	{
//		len += nextWord->GetName().length();
//		len += Clear(nextWord->GetNextWord());
//		delete nextWord;
//		nextWord = NULL;
//		return len;
//	}
//	else
//		return NULL;
//}
//
//void WordManager::WordLoad()
//{
//	ifstream load;
//	string tmp;
//
//	load.open("Word.txt");
//
//	if (load.is_open())
//	{
//		load >> m_iListSize;
//
//		m_strList = new string[m_iListSize];
//
//		for (int i = 0; i < m_iListSize; i++)
//		{
//			load >> tmp;
//			m_strList[i] = tmp;
//		}
//	}
//}
//
//void WordManager::WordInit()
//{
//	Clear();
//	m_strInput = "";
//}

void WordManager::WordLoad()
{
	ifstream load;
	string tmp;

	load.open("Word.txt");

	if (load.is_open())
	{
		load >> m_iSize;

		m_Word = new Word[m_iSize];

		for (int i = 0; i < m_iSize; i++)
		{
			load >> tmp;
			m_Word[i].SetName(tmp);
		}
	}
}

void WordManager::AddWord()
{
	int num = rand() % m_iSize;

	while (m_Word[num].GetState())
		num = rand() % m_iSize;

	m_Word[num].Live();
}

bool WordManager::DropWord()
{
	bool check = false;
	for (int i = 0; i < m_iSize; i++)
	{
		if (m_Word[i].GetState())
		{
			m_Word[i].Erase();
			m_Word[i].Drop();
			if (m_Word[i].Gety() >= HEIGHT - 1)
			{
				m_Word[i].Init();
				check = true;
			}
		}
	}
	for (int i = 0; i < m_iSize; i++)
	{
		if (m_Word[i].GetState())
		{
			m_Word[i].Draw();
		}
	}
	return check;
}

int WordManager::Clear()
{
	int score = 0;

	for (int i = 0; i < m_iSize; i++)
	{
		if (m_Word[i].GetState())
		{
			score += m_Word[i].GetName().length();
			m_Word[i].Dead();
		}
	}
	return score;
}

EFFECT WordManager::CheckWord(string name)
{
	for (int i = 0; i < m_iSize; i++)
	{
		if (m_Word[i].GetState())
		{
			if (m_Word[i].GetName() == name)
			{
				EFFECT tmp = m_Word[i].GetEffect();
				m_Word[i].Dead();
				return tmp;
			}
		}
	}
	return EFFECT_NULL;
}

WordManager::~WordManager()
{
	/*Clear();
	if(m_strList != NULL)
		delete m_strList;*/
}
