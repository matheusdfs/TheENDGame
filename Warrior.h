#pragma once
#include "Player.h"
class Warrior :
	public Player
{
public:

	Warrior();
	~Warrior();

	void Move();
	void Execute();
	void Animate();
	
	void SolveCollision(float x, float y);

};