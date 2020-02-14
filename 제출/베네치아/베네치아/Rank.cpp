#include "Rank.h"



Rank::Rank()
{
}

void Rank::Show()
{

}

void Rank::Save(string name, int level, int score)
{
	ofstream save;
	save.open("Rank.txt", ios::app);
	if (save.is_open())
	{
		save << name << " " << level << " " << score << endl;
	}
	save.close();
}

Rank::~Rank()
{
}
