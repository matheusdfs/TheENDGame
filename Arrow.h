#pragma once
#include "Projectile.h"
class Arrow :
	public Projectile
{

public:

	Arrow();
	Arrow(float posX, float posY, float dirX);
	~Arrow();

	void Execute();
};

