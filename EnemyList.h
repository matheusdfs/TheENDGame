#pragma once
#include "Enemy.h"
#include "stdafx.h"
class EnemyList
{
private:

	std::vector<Enemy*> enemyList;

public:

	std::vector<Enemy*>* getList()
	{
		return &enemyList;
	}
};

