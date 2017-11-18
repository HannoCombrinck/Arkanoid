#include "Entity.h"

#include <iostream>

#include <Engine/EngineSystems.h>
#include <Engine/Input/InputSystem.h>
#include <Engine/Input/InputCodes.h>

using namespace std;
using namespace core;
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

		engine().inputs().getKeyState(KEY_Num0);
		onInit();
	}

	void Entity::update(float fDT)
	{
		onUpdate(fDT);
	}

	EngineSystems & Entity::engine()
	{
		assert(m_pEngine);
		return *m_pEngine;
	}

}