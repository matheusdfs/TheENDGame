#pragma once
#include "Obstacle.h"
#include <xatomic.h>

class Plataform :public Obstacle
{
public:
	Plataform();
	Plataform(float x, float y);
	~Plataform();

	void Execute();
};

