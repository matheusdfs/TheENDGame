#pragma once
#include "Enemy.h"
#include "GraphicManager.h"
class Boss :
	public Enemy
{
public:

	Boss();
	Boss(int posX, int posY, Player* pl);
	~Boss();

	void Execute();
	void Animate();
};