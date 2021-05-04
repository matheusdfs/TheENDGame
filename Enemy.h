#pragma once
#include "Character.h"
#include "Warrior.h"

class Enemy : public Character
{
protected:

	Player* pl1;

	bool attackdamage;
	bool death;

	int cd;
	int id;

public:

	Enemy();
	~Enemy();

	virtual void Execute() = 0;

	const int getId() { return id; }
	const bool getAttackdamage() { return attackdamage; }

	void VerifyHealth();
	void TakeDamage(int dmg);

	const bool getDeath() { return death; }
};

