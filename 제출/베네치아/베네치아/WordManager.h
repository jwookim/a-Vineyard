#pragma once
#include"Word.h"
#include<fstream>

class WordManager
{
private:
	Word* m_Word;
	string* m_strList;
	int m_iListSize;
	string m_strInput;
public:
	void AddWord();
	bool SearchWord(string name);
	bool SearchWord(string name, Word* nextWord);
	void WordLoad();
	WordManager();
	~WordManager();
};

