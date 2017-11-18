#include "Paddle.h"

#include <iostream>

#include <Engine/EngineSystems.h>
#include <Engine/SystemsInclude.h>
#include <Engine/Input/InputCodes.h>

using namespace std;
using namespace input;

Paddle* Paddle::create()
{
	return new Paddle;
}

Paddle::Paddle()
{
}

Paddle::~Paddle()
{
}

void Paddle::onInit()
{
	// TODO: Create visuals, collision objects, sounds i.e. all the components that make up the Paddle object
	m_uVisual = engine().visuals().createVisual();
}

void Paddle::onUpdate(float fDT)
{
	m_bLeft = engine().inputs().getKeyState(KEY_Left);
	m_bRight = engine().inputs().getKeyState(KEY_Right);
	m_bAction = engine().inputs().getKeyState(KEY_Space);
		
	// Update visual according to current state
	// engine().visuals().
}
