#include "Paddle.h"

#include <iostream>

#include <Engine/EngineSystems.h>
#include <Engine/SystemsInclude.h>
#include <Engine/Input/InputCodes.h>
#include <Engine/Graphics/Visual.h>

using namespace std;
using namespace input;
using namespace graphics;

Paddle* Paddle::create()
{
	return new Paddle;
}

Paddle::Paddle()
	: m_vPos(Vec2(0.0f, 0.0f))
	, m_bLeft(false)
	, m_bRight(false)
	, m_bAction(false)
{
}

Paddle::~Paddle()
{
	engine().visuals().removeVisual(m_spVisual);
}

void Paddle::onInit()
{
	// TODO: Create visuals, collision objects, sounds i.e. all the components that make up the Paddle object
	m_spVisual = engine().visuals().createVisual();
}

void Paddle::onUpdate(float fDT)
{
	m_bLeft = engine().inputs().isKeyPressed(KEY_Left);
	m_bRight = engine().inputs().isKeyPressed(KEY_Right);
	m_bAction = engine().inputs().isKeyPressed(KEY_Space) || engine().inputs().isMBPressed(MB_Left);

	auto vMouseMove = engine().inputs().getMousePosRel();
	if (vMouseMove.x != 0 || vMouseMove.y != 0)
	{
		m_vPos += vMouseMove;
		//cout << "Mouse move: " << vMouseMove.x << ", " << vMouseMove.y << endl;
	}

	if (m_bLeft)
	{
		m_vPos.x -= 1.5f;
	}
	if (m_bRight)
	{
		m_vPos.x += 1.5f;
	}
	if (m_bAction)
		cout << "Action\n";

	m_spVisual->setPosition(m_vPos);
}
