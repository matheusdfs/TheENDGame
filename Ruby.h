#pragma once
#include "Obstacle.h"
class Ruby :
	public Obstacle
{
public:
	Ruby();
	Ruby(float x, float y);
	~Ruby();

	void Execute();
};

