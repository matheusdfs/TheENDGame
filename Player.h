#pragma once
#include "Character.h"

class Player :
	public Character
{
protected:

	
	sf::Vector2f oldPosition;
	sf::IntRect rectAtackSprite;

	sf::Image image_atack;
	sf::Texture texture_atack;
	sf::Sprite sprite_atack;

	std::fstream tabela;
	std::string name;

	bool canJump;
	int score;

public:

	Player();
	~Player();

	virtual void Move() = 0;
	virtual void Execute() = 0;
	virtual void SolveCollision(float x, float y) = 0;

	sf::Vector2f* getOldPosition() { return &oldPosition; }

	void RespawnPosition();
	void VerifyHealth();
	void PutScore();
	void ResetScore() { score = 0; }
	void ChangeScore(int quant) { score += quant; }
	void TakeDamage(int dmg);
	void AddLife(int recovery);
	void resetJump() { canJump = true; }
};