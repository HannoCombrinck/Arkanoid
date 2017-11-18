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
		auto pWorld = new World;
		return new World;
	}
	
	void World::addEntity(Entity* pEntity)
	{
		m_aspEntities.push_back(boost::shared_ptr<Entity>(pEntity));
	}

	void World::update(float fDT)
	{
	}

}