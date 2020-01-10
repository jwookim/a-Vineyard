#pragma once
#include"MapDraw.h"
#include"Character.h"

enum PLAY
{
	PLAY_BATTLE,
	PLAY_P1WIN,
	PLAY_P2WIN
};

class Dungeon
{
private:
	MapDraw DrawManager;
public:
	void Menu(Character* player, Character Monster[], int MonsterNum);
	void Stage(Character* player, Character* Monster);
	PLAY Battle(Character* player, Character* Monster, char key);
	Dungeon();
	~Dungeon();
};

