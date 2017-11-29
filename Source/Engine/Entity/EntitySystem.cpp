#include "EntitySystem.h"

#include <Engine/Entity/World.h>

#include <iostream>
#include <vector>

using namespace std;

namespace entity {

	EntitySystem::EntitySystem()
	{
	}

	EntitySystem::~EntitySystem()
	{
	}

	void EntitySystem::setActiveWorld(const boost::shared_ptr<World>& spWorld)
	{
		m_spActiveWorld = spWorld;
	}

	void EntitySystem::update(float fDT)
	{
		if (!m_spActiveWorld)
			return;

		m_spActiveWorld->update(fDT);
	}

}