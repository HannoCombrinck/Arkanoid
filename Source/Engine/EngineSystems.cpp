#include "EngineSystems.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Engine/SystemsInclude.h>

using namespace std;
using namespace sf;
using namespace input;
using namespace graphics;
using namespace sound;
using namespace entity;

EngineSystems::EngineSystems(RenderWindow* pWindow)
{
	m_upInputSystem = unique_ptr<InputSystem>(new InputSystem);
	m_upVisualSystem = unique_ptr<VisualSystem>(new VisualSystem(pWindow));
	m_upSoundSystem = unique_ptr<SoundSystem>(new SoundSystem);
	m_upEntitySystem = unique_ptr<EntitySystem>(new EntitySystem);
}

EngineSystems::~EngineSystems()
{
}

void EngineSystems::update(float fDT)
{
	// TODO: Add several entitysystem updates (prePhysics, postPhysics, preVisuals, postVisuals etc.)
	m_upInputSystem->update(fDT);
	m_upEntitySystem->update(fDT);
	m_upVisualSystem->update(fDT);
	m_upSoundSystem->update(fDT);
}

InputSystem& EngineSystems::is()
{
	return *m_upInputSystem;
}

VisualSystem& EngineSystems::vs()
{
	return *m_upVisualSystem;
}

SoundSystem& EngineSystems::ss()
{
	return *m_upSoundSystem;
}

entity::EntitySystem& EngineSystems::es()
{
	return *m_upEntitySystem;
}
