#pragma once
#include "Entity.h"
#include "State.h"
#include "CollisionManager.h"
#include "EntityList.h"
#include "Warrior.h"
#include "Enemy.h"
#include "Plataform.h"
#include "Ghost.h"
#include "Hamburguer.h"
#include "Thorn.h"
#include "GhostFactory.h"
#include "Archer.h"
#include "Key.h"

class Play;

class Level :
	public Entity, public State
{
protected:

	Warrior* warrior;
	Archer* archer;
	CollisionManager collider;
	EntityList entityList;

	std::ifstream mapa;

	Play* play;

	bool done;
	bool finishlevel;
	bool bossdefeat;
	int cont;

public:

	Level();
	~Level();

	virtual void Execute() = 0;

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Change() = 0;

	void RemoveEntity(Entity* en) { entityList.deleteEntity(en); }

	void setDone(bool a) { done = a; }
	const bool getDone() { return done; }

	void setFinishLevel(bool a) { finishlevel = a;}
	void setPlay(Play* p) { play = p; }
	const bool getFinishLevel() { return finishlevel; }
	void setBossDeafeat(bool b) { bossdefeat = b; }
};