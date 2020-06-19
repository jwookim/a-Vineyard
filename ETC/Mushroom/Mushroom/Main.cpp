#pragma once
#include"GameManage.h"
#include"StageManage.h"

void main()
{
	StageManage::GetInstance()->TimeProgress();

	StageManage::DeleteInstance();
}