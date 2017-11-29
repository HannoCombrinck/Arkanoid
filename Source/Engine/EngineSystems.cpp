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
	m_upInputSystem = make_unique<InputSystem>();
	m_upVisualSystem = make_unique<VisualSystem>(pWindow);
	m_upSoundSystem = make_unique<SoundSystem>();
	m_upEntitySystem = make_unique<EntitySystem>();
}

EngineSystems::~EngineSystems()
{
}

void EngineSystems::update(float fDT)
{
	m_upInputSystem->update(fDT);
	m_upEntitySystem->update(fDT);
	m_upVisualSystem->update(fDT);
	m_upSoundSystem->update(fDT);
}

InputSystem& EngineSystems::inputs() 
{ 
	return *m_upInputSystem; 
}

VisualSystem& EngineSystems::visuals() 
{ 
	return *m_upVisualSystem; 
}

SoundSystem& EngineSystems::sounds() 
{ 
	return *m_upSoundSystem;
}

entity::EntitySystem& EngineSystems::entities()
{
	return *m_upEntitySystem;
}
