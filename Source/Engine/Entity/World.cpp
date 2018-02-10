#include "World.h"

#include <iostream>

#include <Engine/Entity/Entity.h>
#include <Engine/EngineSystems.h>

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
	
	void World::init(EngineSystems& rEngine)
	{
		for (auto& sp : m_aspEntities)
			sp->init(rEngine);
	}

	void World::addEntity(const boost::shared_ptr<Entity> spEntity)
	{
		m_aspEntities.push_back(spEntity);
	}

	void World::update(float fDT)
	{
		for (auto& sp : m_aspEntities)
			sp->update(fDT);
	}

}