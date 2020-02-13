#pragma once
#include"Word.h"
#include<fstream>

class WordManager
{
protected:
	int m_iSize;
	Word* m_Word = NULL;
	string m_strInput;
public:
	/*void AddWord();
	void AddWord(string name, Word* nextWord);
	int DropWord();
	int DropWord(Word* nextWord);
	bool SearchWord(string name);
	bool SearchWord(string name, Word* nextWord);
	EFFECT CheckWord(string name);
	EFFECT CheckWord(string name, Word* nextWord);
	int Clear();
	int Clear(Word* nextWord);
	void WordLoad();
	void WordInit();*/
	void WordLoad();
	void AddWord();
	bool DropWord();
	int Clear();
	EFFECT CheckWord(string name);
	WordManager();
	~WordManager();
};

