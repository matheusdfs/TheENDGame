#include "Enemy.h"
Enemy::Enemy()
{
	pl1 = NULL;
	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 1;
	health = 10;
}
Enemy::~Enemy()
{
}
void Enemy::VerifyHealth()
{
	if (health <= 0)
	{
		death = true;
	}
}
void Enemy::TakeDamage(int dmg)
{
	health -= dmg;
	VerifyHealth();
}
