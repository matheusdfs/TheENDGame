#pragma once
#include "Entity.h"
class Projectile :
	public Entity
{
protected:

	sf::IntRect rectBaseSprite;
	int count;

	int lifetime;
	bool destroy;

	float directionX;
	float directionY;

	int id;

public:

	Projectile();
	~Projectile();

	virtual void Execute() = 0;
	bool getDestroy() { return destroy; }
	void setDestroy(bool b) { destroy = b; }
};

