#pragma once
#include "ObstacleList.h"
#include "EnemyList.h"
#include "ProjectileList.h"
#include "Player.h"
#include "stdafx.h"

class Level;

class CollisionManager
{
private:

	EnemyList enemyList;
	ObstacleList obstacleList;
	ProjectileList projectileList;
	Level* lvl;

public:

	CollisionManager();
	~CollisionManager();


	EnemyList* getEnemyList() { return &enemyList; }
	ObstacleList* getObstacleList() { return &obstacleList; }
	ProjectileList* getProjectileList() { return &projectileList; }

	void setLevel1(Level* lvl) { this->lvl = lvl; }

	void ColliderPxO(Player* pPlayer);
	void ColliderPxE(Player* pPlayer);
	void ColliderPxProjectile(Player* pPlayer);
	void ColliderExProjectile(Player* pPlayer);

	bool DetectCollision(Entity* ent1, Entity* ent2);
};