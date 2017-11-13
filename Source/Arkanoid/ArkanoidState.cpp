#include "Arkanoid.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>
#include <Engine/Entity/World.h>
#include <Arkanoid/ArkanoidState.h>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;
using namespace entity;

ArkanoidState::ArkanoidState(Arkanoid * pArkanoid)
	: m_pArkanoid(pArkanoid)
{
}

ArkanoidState::~ArkanoidState() 
{
}

void ArkanoidState::update(float fDT) 
{ 
	m_spWorld->update(fDT);
	onUpdate(fDT); 
}

void ArkanoidState::setWorld(World * pWorld) 
{ 
	m_spWorld.reset(pWorld); 
	onSetWorld(pWorld);
}

World * ArkanoidState::getWorld() 
{ 
	return m_spWorld.get(); 
}
