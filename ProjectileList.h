#pragma once
#include "Projectile.h"
class ProjectileList
{

private:

	std::vector<Projectile*> enemyProjectileList;
	std::vector<Projectile*> playerProjectileList;

public:

	std::vector<Projectile*>* getEnemyList()
	{
		return &enemyProjectileList;
	}
	std::vector<Projectile*>* getPlayerList()
	{
		return &playerProjectileList;
	}
};

