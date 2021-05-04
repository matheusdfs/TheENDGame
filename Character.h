#pragma once
#include "Entity.h"
class Character :
	public Entity
{
protected:

	sf::Vector2f acceleration;
	sf::IntRect rectBaseSprite;

	bool attacking;
	int health;
	int count;

public:

	Character();
	~Character();

	virtual void Execute() = 0;

	bool getAttack() { return attacking; }

};

