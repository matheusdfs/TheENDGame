#pragma once
#include "Obstacle.h"

class Thorn: public Obstacle
{
public:
	Thorn();
	Thorn(float x, float y);
	~Thorn();

	void Execute();
};

