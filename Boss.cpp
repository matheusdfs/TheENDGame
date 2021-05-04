#include "Boss.h"

Boss::Boss()
{
	pl1 = NULL;
	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 2;
	health = 10;
}
Boss::Boss(int posX, int posY, Player* pl)
{
	pl1 = pl;
	
	image.loadFromFile("Textures/Boss.png");
	image.createMaskFromColor(sf::Color::White);

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::IntRect r(0, 0, 240, 240);
	rectBaseSprite = r;
	body = r;

	attacking = false;
	attackdamage = false;
	death = false;

	cd = 0;
	count = 0;
	id = 3;
	health = 1000;

	sprite.setPosition(posX, posY);
	body.left = posX;
	body.top = posY;
}
Boss::~Boss()
{
}
void Boss::Execute()
{
	
	acceleration.x = pl1->getBody()->left - 120 - sprite.getPosition().x;
	acceleration.y = pl1->getBody()->top - 120 - sprite.getPosition().y;

	float tam = acceleration.x * acceleration.x + acceleration.y * acceleration.y;
	tam = sqrt(tam);

	if (tam == 0)
	{
		tam = 1;
	}
	acceleration.x = acceleration.x * 2.5f / tam;
	acceleration.y = acceleration.y * 2.5f / tam;

	body.left = body.left + static_cast<int>(acceleration.x);
	body.top = body.top + static_cast<int>(acceleration.y);
	sprite.setPosition(static_cast<float>(body.left), static_cast<float>(body.top));

	if (attacking == false && tam < 100.0f && cd > 240)
	{
		cd = 0;
		attacking = true;
	}
	cd++;
	Animate();
}
void Boss::Animate()
{
	if (count == 5)
	{
		count = 0;
		if (attacking == false)
		{
			rectBaseSprite.top = 0;
			rectBaseSprite.left = 0;	
			if (acceleration.x > 0)
			{
				if (rectBaseSprite.width < 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				sprite.setTextureRect(rectBaseSprite);
			}
			else if (acceleration.x < 0)
			{
				if (rectBaseSprite.width > 0)
				{
					rectBaseSprite.width = -rectBaseSprite.width;
				}
				rectBaseSprite.left = 240;
				sprite.setTextureRect(rectBaseSprite);
				rectBaseSprite.left = 0;
			}
		}
		else
		{
			rectBaseSprite.left += 240;
			sprite.setTextureRect(rectBaseSprite);
			if (rectBaseSprite.left == 1440 && rectBaseSprite.top == 240)
			{
				attackdamage = true;
			}
			else
			{
				attackdamage = false;
			}
			if (rectBaseSprite.left == 2160)
			{
				rectBaseSprite.left = 0;
				rectBaseSprite.top += 240;
				if (rectBaseSprite.top == 480)
				{
					attacking = false;
					rectBaseSprite.top = 0;
					sprite.setTextureRect(rectBaseSprite);
				}
			}
		}
	}
	count++;
}