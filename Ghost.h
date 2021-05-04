#pragma once
#include "Enemy.h"
#include "GraphicManager.h"

class Ghost :public Enemy
{
public:
	Ghost();
	Ghost(int posX, int posY, Player* pl);
	~Ghost();

	void Execute();
};

