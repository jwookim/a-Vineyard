#pragma once
#include"Word.h"
#include<fstream>

class WordManager
{
protected:
	Word* m_Word;
	string* m_strList;
	int m_iListSize;
	string m_strInput;
public:
	void AddWord();
	void AddWord(string name, Word* nextWord);
	int DropWord();
	int DropWord(Word* nextWord);
	bool SearchWord(string name);
	bool SearchWord(string name, Word* nextWord);
	bool CheckWord(string name);
	bool CheckWord(string name, Word* nextWord);
	void WordLoad();
	WordManager();
	~WordManager();
};

