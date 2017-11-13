#include "Entity.h"

#include <iostream>

using namespace std;
using namespace core;

namespace entity {

	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::update(float fDT)
	{
		onUpdate(fDT);
	}

}