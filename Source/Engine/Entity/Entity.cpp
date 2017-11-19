#include "Entity.h"

#include <iostream>
#include <assert.h>

#include <Engine/EngineSystems.h>

using namespace std;

namespace entity {

	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::init(EngineSystems& rEngine)
	{
		m_pEngine = &rEngine;
		onInit();
	}

	void Entity::update(float fDT)
	{
		onUpdate(fDT);
	}

	EngineSystems& Entity::engine()
	{
		assert(m_pEngine);
		return *m_pEngine;
	}

}