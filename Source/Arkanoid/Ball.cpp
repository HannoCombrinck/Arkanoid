/*#include "Ball.h"

#include <iostream>
#include <functional>

#include <Engine/Engine.h>
#include <Engine/Graphics/Visual.h>

using namespace std;
using namespace std::placeholders;
using namespace graphics;
using namespace sound;

Ball::Ball()
	: m_vPos(Vec2(0.0f, 0.0f))
	, m_uVisual(~0)
{
}

Ball::~Ball()
{
	engine().visuals().removeVisual(m_uVisual);
	//engine().sounds().removeSound(m_uSound);	
}

void Ball::onInit()
{
	auto& vs = engine().visuals();
	m_uVisual = vs.createVisual();
	vs.modifyVisual(m_uVisual).loadSprite("../Data/Textures/test.tga");

	engine().visuals().modifyVisual(m_uVisual).setSize(Vec2(0.25f, 0.25f));
	//m_uSound = engine().sounds().createSound("../Data/Sounds/beep.wav");
}

void Ball::onUpdate(float fDT)
{
	updateState();
	applyState();
}

void Ball::updateState()
{
	m_vPos.x = 10.0f;
	m_vPos.y = 10.0f;
}

void Ball::applyState()
{
	auto& rVisual = engine().visuals().modifyVisual(m_uVisual);
	rVisual.setPosition(m_vPos);
}
*/