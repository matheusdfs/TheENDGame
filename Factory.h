#pragma once
#include "Entity.h"

class Factory: public Entity
{
protected:

public:
	Factory();
	~Factory();
	virtual void product() = 0;
	virtual void Execute() = 0;
};

