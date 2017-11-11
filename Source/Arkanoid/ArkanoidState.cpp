#include "Arkanoid.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>
#include <Arkanoid/ArkanoidState.h>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;

ArkanoidState::ArkanoidState(Arkanoid * pArkanoid)
	: m_pArkanoid(pArkanoid)
{
}

ArkanoidState::~ArkanoidState() 
{
}
