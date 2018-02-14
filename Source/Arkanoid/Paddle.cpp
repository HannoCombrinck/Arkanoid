#include "Paddle.h"

#include <iostream>

#include <Engine/Engine.h>
#include <Engine/Input/InputCodes.h>
#include <Engine/Graphics/Visual.h>

using namespace std;
using namespace input;
using namespace graphics;

std::unique_ptr<Paddle> Paddle::create()
{
	return std::make_unique<Paddle>();
}

Paddle::Paddle()
	: m_vPos(Vec2(0.0f, 0.0f))
	, m_bLeft(false)
	, m_bRight(false)
	, m_bUp(false)
	, m_bDown(false)
	, m_bAction(false)
	, m_uVisual(~0)
{
}

Paddle::~Paddle()
{
	engine().visuals().removeVisual(m_uVisual);
}

void Paddle::onInit()
{
	// TODO: Create visuals, collision objects, sounds i.e. all the components that make up the Paddle object
	m_uVisual = engine().visuals().createVisual("../Data/Textures/test.tga");
	m_uSound = engine().sounds().createSound("../Data/Sounds/beep.wav");
}

void Paddle::onUpdate(float fDT)
{
	getInputs();
	updateState();
	applyState();
}

void Paddle::getInputs()
{
	auto& is = engine().inputs();

	m_bLeft = is.isKeyPressed(KEY_A);
	m_bRight = is.isKeyPressed(KEY_D);
	m_bUp = is.isKeyPressed(KEY_W);
	m_bDown = is.isKeyPressed(KEY_S);
	m_bAction = is.isKeyPressed(KEY_Space) || is.isMBPressed(MB_Left);

	auto vMouseMove = is.getMousePosRel();
	if (vMouseMove.x != 0 || vMouseMove.y != 0)
	{
		m_vPos += vMouseMove;
		//cout << "Mouse move: " << vMouseMove.x << ", " << vMouseMove.y << endl;
	}
}

void Paddle::updateState()
{
	if (m_bLeft)
		m_vPos.x -= 5.5f;
	if (m_bRight)
		m_vPos.x += 5.5f;
	if (m_bUp)
		m_vPos.y -= 5.5f;
	if (m_bDown)
		m_vPos.y += 5.5f;
	if (m_bAction)
		cout << "Action\n";
}

void Paddle::applyState()
{
	auto& rVisual = engine().visuals().modifyVisual(m_uVisual);
	rVisual.setPosition(m_vPos);
}
