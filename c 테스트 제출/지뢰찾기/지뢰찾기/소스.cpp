#include"GameManage.h"
#include<ctime>

void main()
{
	srand((unsigned)time(NULL));
	GameManage::GetInstance()->Play();

	GameManage::DestroyInstance();
}