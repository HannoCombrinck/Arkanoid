#include "World.h"

#include <iostream>

#include <Engine/Entity/Entity.h>

using namespace std;
using namespace core;

namespace entity {

	World::World()
	{
		// TEMP
		auto spEntity = boost::shared_ptr<Entity>();
		m_aspEntities.push_back(spEntity);
		//
	}

	World::~World()
	{
	}

	World* World::load(const string & sFilename)
	{
		auto pWorld = new World;
		return new World;
	}
	
	void World::update(float fDT)
	{
	}

}