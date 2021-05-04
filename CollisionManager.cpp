#include "CollisionManager.h"
#include "Level.h"

CollisionManager::CollisionManager()
{
	lvl = NULL;
}
CollisionManager::~CollisionManager()
{

}
void CollisionManager::ColliderPxO(Player* pPlayer)
{
	auto it = obstacleList.getList()->begin();
	bool removed = false;
	while (it != obstacleList.getList()->end())
	{
		if (DetectCollision(pPlayer, (*it)))
		{
			if ((*it)->getID() != 3) //player pode atravessar os espinhos
			{
				if (pPlayer->getOldPosition()->y + pPlayer->getBody()->height < (*it)->getBody()->top)
				{
					pPlayer->resetJump();
					pPlayer->SolveCollision(static_cast<float>(pPlayer->getBody()->left), static_cast<float>((*it)->getBody()->top - pPlayer->getBody()->height - 1));
				}
				else if (pPlayer->getOldPosition()->y > (*it)->getBody()->top + ((*it)->getBody()->height))
				{
					pPlayer->SolveCollision(static_cast<float>(pPlayer->getBody()->left), static_cast<float>((*it)->getBody()->top + (*it)->getBody()->height + 1));
				}
				else if (pPlayer->getOldPosition()->x + pPlayer->getBody()->width < (*it)->getBody()->left)
				{
					pPlayer->SolveCollision(static_cast<float>((*it)->getBody()->left - pPlayer->getBody()->width - 1), static_cast<float>(pPlayer->getBody()->top));
				}
				else if (pPlayer->getOldPosition()->x > ((*it)->getBody()->left + (*it)->getBody()->width))
				{
					pPlayer->SolveCollision(static_cast<float>((*it)->getBody()->left + (*it)->getBody()->width + 1), static_cast<float>(pPlayer->getBody()->top));
				}
			}
			if ((*it)->getID() == 2) //quer dizer que eh um hambuguer
			{
				lvl->RemoveEntity(static_cast<Entity*>(*it));
				it = obstacleList.getList()->erase(it);
				removed = true;
				pPlayer->AddLife(50);
			}
			else if ((*it)->getID() == 3) //quer dizer que eh um espinho
			{
				pPlayer->TakeDamage(5);
			}
			else if ((*it)->getID() == 6)
			{
				lvl->setFinishLevel(true);
			}
			else if ((*it)->getID() == 7)
			{
				pPlayer->ChangeScore(10);
				lvl->RemoveEntity(static_cast<Entity*>(*it));
				it = obstacleList.getList()->erase(it);
				removed = true;
			}
		}
		if (removed == false)
		{
			++it;
		}
		removed = false;
	}
}
bool CollisionManager::DetectCollision(Entity* ent1, Entity* ent2)
{
	if (ent1->getBody()->left <= ent2->getBody()->left + ent2->getBody()->width && ent1->getBody()->left + ent1->getBody()->width >= ent2->getBody()->left)
	{
		if (ent1->getBody()->top <= ent2->getBody()->top + ent2->getBody()->height && ent1->getBody()->top + ent1->getBody()->height >= ent2->getBody()->top)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;

}
void CollisionManager::ColliderPxE(Player* pPlayer)
{
	auto it = enemyList.getList()->begin();
	bool removed = false;
	while (it != enemyList.getList()->end())
	{
		if (DetectCollision(pPlayer, (*it)))
		{
			if ((*it)->getId() == 1 || (*it)->getId() == 2)
			{
				if (pPlayer->getAttack())
				{
					(*it)->TakeDamage(1);
					if ((*it)->getDeath())
					{
						pPlayer->ChangeScore(1);
						lvl->RemoveEntity(static_cast<Entity*>(*it));
						it = enemyList.getList()->erase(it);
						removed = true;
					}
				}
				else 
				{
					pPlayer->TakeDamage(1);
				}
			}
			else if ((*it)->getId() == 3)
			{
				if ((*it)->getAttackdamage())
				{
					pPlayer->TakeDamage(50);
				}
				if (pPlayer->getAttack())
				{
					(*it)->TakeDamage(1);
					if ((*it)->getDeath())
					{
						pPlayer->ChangeScore(30);
						lvl->setBossDeafeat(true);
						lvl->RemoveEntity(static_cast<Entity*>(*it));
						it = enemyList.getList()->erase(it);
						removed = true;
					}
				}
			}
		}
		if (removed == false)
		{
			++it;
		}
		removed = false;
	}
}
void CollisionManager::ColliderPxProjectile(Player* pPlayer)
{
	auto it = projectileList.getEnemyList()->begin();
	bool removed = false;
	while (it != projectileList.getEnemyList()->end())
	{
		if ((*it)->getDestroy())
		{
			lvl->RemoveEntity(static_cast<Entity*>(*it));
			it = projectileList.getEnemyList()->erase(it);
			removed = true;
		}
		else if (DetectCollision(pPlayer, (*it)))
		{
			lvl->RemoveEntity(static_cast<Entity*>(*it));
			it = projectileList.getEnemyList()->erase(it);
			pPlayer->TakeDamage(30);
			removed = true;
		}
		if (removed == false)
		{
			++it;
		}
		removed = false;
	}
}
void CollisionManager::ColliderExProjectile(Player* pPlayer)
{

	bool removeProjectile = false;
	bool removeEnemy = false;
	auto it = enemyList.getList()->begin();
	auto itProjectile = projectileList.getPlayerList()->begin();

	while (itProjectile != projectileList.getPlayerList()->end())
	{
		it = enemyList.getList()->begin();
		while (it != enemyList.getList()->end())
		{
			if (DetectCollision((*itProjectile), (*it)))
			{
				(*it)->TakeDamage(30);
				if ((*it)->getDeath())
				{
					pPlayer->ChangeScore(1);
					if ((*it)->getId() == 3)
					{
						pPlayer->ChangeScore(30);
						lvl->setBossDeafeat(true);
					}
					lvl->RemoveEntity(static_cast<Entity*>(*it));
					it = enemyList.getList()->erase(it);
					removeEnemy = true;
				}
				(*itProjectile)->setDestroy(true);
			}
			if (removeEnemy == false)
			{
				++it;
			}
			removeEnemy = false;
		}
		if ((*itProjectile)->getDestroy())
		{
			lvl->RemoveEntity(static_cast<Entity*>(*itProjectile));
			itProjectile = projectileList.getPlayerList()->erase(itProjectile);
			removeProjectile = true;
		}
		if (removeProjectile == false)
		{
			++itProjectile;
		}
		removeProjectile = false;
	}
}