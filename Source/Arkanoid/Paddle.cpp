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
	m_bLeft = engine().inputs().isKeyPressed(KEY_Left);
	m_bRight = engine().inputs().isKeyPressed(KEY_Right);
	m_bAction = engine().inputs().isKeyPressed(KEY_Space) || engine().inputs().isMBPressed(MB_Left);

	auto vMouseMove = engine().inputs().getMousePosRel();
	if (vMouseMove.x != 0 || vMouseMove.y != 0)
		cout << "Mouse move: " << vMouseMove.x << ", " << vMouseMove.y << endl;

	if (m_bLeft)
		cout << "Left\n";
	if (m_bRight)
		cout << "Right\n";
	if (m_bAction)
		cout << "Action\n";
		
	// Update visual according to current state
	// engine().visuals().
}
