#include "EngineSystems.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>

using namespace std;
using namespace sf;
using namespace input;
using namespace graphics;
using namespace sound;

EngineSystems::EngineSystems(RenderWindow* pWindow)
{
	m_upInputSystem = make_unique<InputSystem>();
	m_upVisualSystem = make_unique<VisualSystem>(pWindow);
	m_upSoundSystem = make_unique<SoundSystem>();
}

EngineSystems::~EngineSystems()
{
}

void EngineSystems::update(float fDT)
{
	m_upInputSystem->update(fDT);
	m_upVisualSystem->update(fDT);
	m_upSoundSystem->update(fDT);
}

InputSystem* EngineSystems::inputs() 
{ 
	return m_upInputSystem.get(); 
}

VisualSystem* EngineSystems::visuals() 
{ 
	return m_upVisualSystem.get(); 
}

SoundSystem* EngineSystems::sounds() 
{ 
	return m_upSoundSystem.get(); 
}
