#pragma once
#include "Obstacle.h"

class Hamburguer: public Obstacle 
{
public:
	Hamburguer();
	Hamburguer(float x, float y);
	~Hamburguer();

	void Execute();
	void Animation();
};

