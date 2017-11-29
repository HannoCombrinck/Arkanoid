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

	void EntitySystem::update(float fDT)
	{
		for (auto& sp : m_aspWorlds)
			sp->update(fDT);
	}

}