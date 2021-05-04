#pragma once
#include "Projectile.h"
class Fireball :
	public Projectile
{
public:

	Fireball();
	Fireball(float posX, float posY, float dirX, float dirY);
	~Fireball();

	void Execute();
};

