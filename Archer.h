#pragma once
#include "Player.h"
#include "EntityList.h"

class CollisionManager;

class Archer :
	public Player
{
private:

	EntityList* entList;
	CollisionManager* collision;

public:

	Archer();
	~Archer();

	void Move();
	void Execute();
	void Animate();

	void SolveCollision(float x, float y);

	void setEntityList(EntityList* el) { entList = el; }
	void setCollision(CollisionManager* c) { collision = c; }
};
