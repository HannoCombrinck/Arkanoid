#include "Entity.h"

#include <iostream>
#include <assert.h>

#include <Engine/EngineSystems.h>
#include <Engine/SystemsInclude.h>

using namespace std;
using namespace graphics;
using namespace sound;
using namespace input;

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

	EntitySystem& Entity::es()
	{
		return m_pEngine->es();
	}

	VisualSystem& Entity::vs()
	{
		return m_pEngine->vs();
	}

	InputSystem& Entity::is()
	{
		return m_pEngine->is();
	}

	SoundSystem& Entity::ss()
	{
		return m_pEngine->ss();
	}

}
