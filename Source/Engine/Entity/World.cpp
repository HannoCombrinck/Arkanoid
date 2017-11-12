#include "World.h"

#include <iostream>

#include <Engine/Entity/Entity.h>

using namespace std;
using namespace core;

namespace entity {

	World::World()
	{
	}

	World::~World()
	{
	}

	World* World::load(const string & sFilename)
	{
		return new World;
	}

	void World::update(float fDT)
	{
	}

}