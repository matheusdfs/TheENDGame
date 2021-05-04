#pragma once
#include "Factory.h"
#include "Ghost.h"
#include "Player.h"
#include "EntityList.h"

class CollisionManager;

class GhostFactory:public Factory
{
private:
	int count2;
	Player* pl1;
	CollisionManager* colision;
	EntityList* EnList;

	sf::IntRect rectBaseSprite;
	int count;

public:
	GhostFactory();
	GhostFactory(float x, float y, EntityList* el, CollisionManager* cl);
	~GhostFactory();

	void setPlayer1(Player* pl) { pl1 = pl; }
	void Execute();
	void product();
	void animate();
};

