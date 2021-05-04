#pragma once
#include "Enemy.h"
#include "EntityList.h"
#include "Fireball.h"
#include "CollisionManager.h"

class Mage: public Enemy
{
private:

	EntityList* entList;
	CollisionManager* collision;

public:

	Mage();
	Mage(float x, float y, EntityList* el, CollisionManager* cl);
	~Mage();

	void Execute();
	void Animate();
	void setPlayer1(Player* pl) { pl1 = pl; }
};

