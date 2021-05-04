#pragma once
#include "Entity.h"

class Obstacle :public Entity
{
protected:
	int identificator;
	sf::IntRect rectBaseSprite;
	int count;

public:
	Obstacle();
	Obstacle(float x, float y);
	~Obstacle();

	const int getID() { return identificator; }
	virtual void Execute();
};

