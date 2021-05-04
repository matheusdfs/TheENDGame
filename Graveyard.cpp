#include "Graveyard.h"
#include "Mage.h"
#define NUMEROCOLUNAS 50

Graveyard::Graveyard()
{
}
Graveyard::Graveyard(GraphicManager* g, Warrior* wa)
{
	graphic = g;
	warrior = wa;
	archer = NULL;
	collider.setLevel1(this);
	Setup();
}
Graveyard::Graveyard(GraphicManager* g, Warrior* wa, Archer* ar)
{
	graphic = g;
	warrior = wa;
	archer = ar;
	collider.setLevel1(this);
	Setup();
}

Graveyard::~Graveyard()
{
}

void Graveyard::Setup()
{
	Plataform* new_plataform;
	Hamburguer* new_hamburguer;
	Thorn* new_thorn;
	GhostFactory* new_ghost_fac;
	Mage* new_mage;
	Key* new_key;
	Boss* new_boss = NULL;

	std::vector<int> yHamburguer;
	std::vector<int> xHamburguer;
	srand(time(NULL));

	texture.loadFromFile("Textures/Graveyard.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(-600, -600);
	mapa.open("Resources/Graveyard.txt");
	int i = 0;
	float x = 0, y = 0;
	int aux;
	int aux2;
	while (!mapa.eof())
	{
		mapa >> i;
		switch (i)
		{
		case 1:
			new_plataform = new Plataform(x, y);
			new_plataform->setGraphic(graphic);
			entityList.Add(static_cast<Entity*> (new_plataform));
			collider.getObstacleList()->getList()->push_back(new_plataform);
			break;

		case 2:
			xHamburguer.push_back(x);
			yHamburguer.push_back(y);
			break;

		case 3:
			new_thorn = new Thorn(x, y);
			new_thorn->setGraphic(graphic);
			entityList.Add(static_cast<Entity*> (new_thorn));
			collider.getObstacleList()->getList()->push_back(new_thorn);
			break;

		case 4:
			new_ghost_fac = new GhostFactory(x, y, &entityList, &collider);
			new_ghost_fac->setGraphic(graphic);
			new_ghost_fac->setPlayer1(warrior);
			entityList.Add(static_cast<Entity*> (new_ghost_fac));
			break;

		case 5:
			new_mage = new Mage(x, y, &entityList, &collider);
			new_mage->setGraphic(graphic);
			new_mage->setPlayer1(static_cast<Player*>(warrior));
			entityList.Add(static_cast<Entity*>(new_mage));
			collider.getEnemyList()->getList()->push_back(new_mage);
			break;

		case 6:
			new_key = new Key(x, y);
			new_key->setGraphic(graphic);
			entityList.Add(static_cast<Entity*> (new_key));
			collider.getObstacleList()->getList()->push_back(new_key);
			break;
		case 7:
			new_boss = new Boss(x, y, warrior);
			new_boss->setGraphic(graphic);
			entityList.Add(static_cast<Entity*>(new_boss));
			collider.getEnemyList()->getList()->push_back(new_boss);
			break;
		case 8:
			if (rand() % 5 == 0)
			{

				new_mage = new Mage(x, y, &entityList, &collider);
				new_mage->setGraphic(graphic);
				new_mage->setPlayer1(static_cast<Player*>(warrior));
				entityList.Add(static_cast<Entity*>(new_mage));
				collider.getEnemyList()->getList()->push_back(new_mage);
			}
			break;
		case 9:
			if (rand() % 5 == 0)
			{
				new_thorn = new Thorn(x, y);
				new_thorn->setGraphic(graphic);
				entityList.Add(static_cast<Entity*> (new_thorn));
				collider.getObstacleList()->getList()->push_back(new_thorn);
				break;
			}
		default:
			break;
		}
		x += 32;

		if (x >= 32 * NUMEROCOLUNAS)
		{
			x = 0;
			y += 32;
		}
	}

	aux2 = (rand() % 12) + 5;
	for (i = 0; i < aux2; i++)
	{
		aux = rand() % (xHamburguer.size());
		new_hamburguer = new Hamburguer(xHamburguer[aux], yHamburguer[aux]);
		new_hamburguer->setGraphic(graphic);
		entityList.Add(static_cast<Entity*> (new_hamburguer));
		collider.getObstacleList()->getList()->push_back(new_hamburguer);
		xHamburguer.erase(xHamburguer.begin() + aux);
		yHamburguer.erase(yHamburguer.begin() + aux);
	}

	warrior->setGraphic(graphic);
	warrior->RespawnPosition();
	entityList.Add(static_cast<Entity*>(warrior));

	if (archer != NULL)
	{
		archer->setGraphic(graphic);
		archer->RespawnPosition();
		archer->setCollision(&collider);
		archer->setEntityList(&entityList);
		entityList.Add(static_cast<Entity*>(archer));
	}

	bossdefeat = false;
	finishlevel = false;
	cont = 0;
}
void Graveyard::Execute()
{
	entityList.Update();
	collider.ColliderPxO(warrior);
	collider.ColliderPxE(warrior);
	collider.ColliderPxProjectile(warrior);
	if (archer != NULL)
	{
		collider.ColliderPxO(archer);
		collider.ColliderPxE(archer);
		collider.ColliderPxProjectile(archer);
		collider.ColliderExProjectile(archer);
	}
}
void Graveyard::Update()
{
	Execute();
}
void Graveyard::Draw()
{
	Print();
	entityList.Draw();
}
void Graveyard::Change()
{
	if (finishlevel == true && bossdefeat == true)
	{
		warrior->PutScore();
		if (archer != NULL)
		{
			archer->PutScore();
		}
		quit = true;
	}
	else
		finishlevel = false;
}
