#pragma once
#include "Obstacle.h"
#include "stdafx.h"
class ObstacleList
{
private:

	std::list<Obstacle*> obstacleList;

public:

	std::list<Obstacle*>* getList()
	{
		return &obstacleList;
	}
};

