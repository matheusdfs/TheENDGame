#pragma once
#include "Obstacle.h"
class Key :
	public Obstacle
{
public:
	Key();
	Key(float x, float y);
	~Key();

	void Execute();
};

