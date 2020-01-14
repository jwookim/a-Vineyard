#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Character.h"
#include"Shop.h"
#include"Dungeon.h"

class GameManage
{
private:
	Character* m_Player;
	Character* m_Monster;
	int m_iMonsterNum;
	MapDraw DrawManager;
	Shop m_Shop;
	Dungeon m_Dungeon;
public:
	GameManage();
	void Start();
	void NewGame();
	bool LoadGame();
	void ReadDefaultPlayer();
	void ReadDefaultMonster();
	void ReadPlayer(int num);
	void ReadMonster(int num);
	void Menu();
	void PlayerInfo();
	void MonsterInfo();
	void Save();
	void SaveData(int num);
	void DeleteInfo();
	~GameManage();
};

