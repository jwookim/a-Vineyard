#pragma once
#include"Character.h"

class Garen : public Character
{
};

//시야에 들어오면 추격
//시야 밖으로 나가면 나간 직후의 위치까지 인식
//5초간 못찾으면 어그로 해제