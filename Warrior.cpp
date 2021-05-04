#include "Warrior.h"
Warrior::Warrior()
{
	name = "Warrior";

	image.loadFromFile("Textures/Jogador1/spr_Walk_strip.png");
	image.createMaskFromColor(sf::Color::White);

	image_atack.loadFromFile("Textures/Jogador1/spr_Attack_strip.png");
	image_atack.createMaskFromColor(sf::Color::White);

	sf::IntRect r(65, 35, 35, 40);
	body = r;

	sf::IntRect s(0, 0, 170, 96);
	rectBaseSprite = s;
	texture.loadFromImage(image);

	rectAtackSprite = s;
	texture_atack.loadFromImage(image_atack);


	sprite.setPosition(0, 0);
	body.left = -100;
	body.top = 0;

	canJump = true;
	attacking = false;
	health = 300;
	score = 0;
	count = 0;
}
Warrior::~Warrior()
{
}
void Warrior::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		acceleration.x = -5;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		acceleration.x = 5;
	else
		acceleration.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		attacking = true;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump)
	{
		canJump = false;
		acceleration.y = -20.0f;
	}

	acceleration.y += 1;
	
	if(acceleration.y > 10){
		acceleration.y = 10;
	}
	
}
void Warrior::Animate()
{
	if (count == 3)
	{
		count = 0;
		if (attacking == false)
		{
			sprite.setTexture(texture);
			if (acceleration.x == 0)
			{
				if (rectBaseSprite.width > 0)
				{
					rectBaseSprite.left = 340;
					sprite.setTextureRect(rectBaseSprite);
				}
				else
				{
					rectBaseSprite.left = 510;
					sprite.setTextureRect(rectBaseSprite);
					rectBaseSprite.left = 340;
				}
			}
			else if (acceleration.x > 0)
			{
				rectBaseSprite.left += 170;
				if (rectBaseSprite.width < 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				sprite.setTextureRect(rectBaseSprite);
			}
			else if (acceleration.x < 0)
			{
				rectBaseSprite.left += 340;
				if (rectBaseSprite.width > 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				sprite.setTextureRect(rectBaseSprite);
				rectBaseSprite.left -= 170;
			}
			if (rectBaseSprite.left == 1190)
			{
				rectBaseSprite.left = 0;
			}
		}
		else
		{
			sprite.setTexture(texture_atack);
			if (rectBaseSprite.width < 0)
			{
				if (rectAtackSprite.width > 0)
				{
					rectAtackSprite.width = -rectAtackSprite.width;
				}
				rectAtackSprite.left += 340;
				sprite.setTextureRect(rectAtackSprite);
				rectAtackSprite.left -= 170;
			}
			else
			{
				if (rectAtackSprite.width < 0)
				{
					rectAtackSprite.width = -rectAtackSprite.width;
				}
				rectAtackSprite.left += 170;
				sprite.setTextureRect(rectAtackSprite);
			}
			if (rectAtackSprite.left > 4995)
			{
				rectAtackSprite.left = 0;
				attacking = false;
			}
		}
	}
	count++;
}
void Warrior::Execute()
{
	Move();
	Animate();
	VerifyHealth();
	
	oldPosition.x = static_cast<float>(body.left);
	oldPosition.y = static_cast<float>(body.top);
	
	body.left += static_cast<int>(acceleration.x);
	body.top += static_cast<int>(acceleration.y);

	sprite.setPosition(static_cast<float>(body.left - 65), static_cast<float>(body.top - 35));
	
	
	graphic->updateView(static_cast<float>(body.left), static_cast<float>(body.top));
}
void Warrior::SolveCollision(float x, float y)
{
	body.left = static_cast<int>(x);
	body.top = static_cast<int>(y);

	sprite.setPosition(static_cast<float>(body.left - 65), static_cast<float>(body.top - 35));

	graphic->updateView(x, y);
}