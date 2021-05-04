#include "Archer.h"
#include "CollisionManager.h"
#include "Arrow.h"

Archer::Archer()
{
	name = "Archer";

	image.loadFromFile("Textures/Archer.png");
	image.createMaskFromColor(sf::Color::White);

	image_atack.loadFromFile("Textures/Archer_atack.png");
	image_atack.createMaskFromColor(sf::Color::White);

	sf::IntRect r(0, 0, 25, 37);
	body = r;

	sf::IntRect s(0, 0, 50, 37);
	rectBaseSprite = s;
	texture.loadFromImage(image);

	rectAtackSprite = s;
	texture_atack.loadFromImage(image_atack);

	canJump = true;
	attacking = false;
	health = 300;
	score = 0;
	count = 0;
}
Archer::~Archer()
{
}
void Archer::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		acceleration.x = -5;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		acceleration.x = 5;
	else
		acceleration.x = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		attacking = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && canJump)
	{
		canJump = false;
		acceleration.y = -20.0f;
	}

	acceleration.y += 1;

	if (acceleration.y > 10) {
		acceleration.y = 10;
	}
}
void Archer::Execute()
{
	Move();
	Animate();
	VerifyHealth();

	oldPosition.x = static_cast<float>(body.left);
	oldPosition.y = static_cast<float>(body.top);

	body.left += static_cast<int>(acceleration.x);
	body.top += static_cast<int>(acceleration.y);

	sprite.setPosition(static_cast<float>(body.left - 10), static_cast<float>(body.top));
}
void Archer::Animate()
{
	if (count == 5)
	{
		count = 0;
		if (attacking == false)
		{
			sprite.setTexture(texture);
			if (acceleration.x == 0)
			{
				rectBaseSprite.top = 0;
				if (rectBaseSprite.width > 0)
				{
					rectBaseSprite.left = 0;
					sprite.setTextureRect(rectBaseSprite);
				}
				else
				{
					rectBaseSprite.left = 50;
					sprite.setTextureRect(rectBaseSprite);
					rectBaseSprite.left = 0;
				}
			}
			else if (acceleration.x > 0)
			{
				rectBaseSprite.top = 37;
				rectBaseSprite.left += 50;
				if (rectBaseSprite.width < 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				sprite.setTextureRect(rectBaseSprite);
			}
			else if (acceleration.x < 0)
			{
				rectBaseSprite.top = 37;
				rectBaseSprite.left += 100;
				if (rectBaseSprite.width > 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				sprite.setTextureRect(rectBaseSprite);
				rectBaseSprite.left -= 50;
			}
			if (rectBaseSprite.left == 300)
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
				rectAtackSprite.left += 100;
				sprite.setTextureRect(rectAtackSprite);
				rectAtackSprite.left -= 50;
			}
			else
			{
				if (rectAtackSprite.width < 0)
				{
					rectAtackSprite.width = -rectAtackSprite.width;
				}
				rectAtackSprite.left += 50;
				sprite.setTextureRect(rectAtackSprite);
			}
			if (rectAtackSprite.left == 150 && rectAtackSprite.top == 37)
			{
				Arrow* new_projectile = new Arrow(sprite.getPosition().x, sprite.getPosition().y + 18, rectAtackSprite.width);
				new_projectile->setGraphic(graphic);
				entList->Add(static_cast<Entity*> (new_projectile));
				collision->getProjectileList()->getPlayerList()->push_back(static_cast<Projectile*> (new_projectile));
			}
			if (rectAtackSprite.left == 150)
			{
				rectAtackSprite.left = -50;
				rectAtackSprite.top += 37;
				if (rectAtackSprite.top == 74)
				{
					attacking = false;
					rectAtackSprite.top = 0;

					rectBaseSprite.left = 0;
				}
			}
		}
	}
	count++;
}
void Archer::SolveCollision(float x, float y)
{
	body.left = static_cast<int>(x);
	body.top = static_cast<int>(y);

	sprite.setPosition(static_cast<float>(body.left - 10), static_cast<float>(body.top));
}
