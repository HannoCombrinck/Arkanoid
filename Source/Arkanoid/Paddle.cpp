#include "Paddle.h"

#include <iostream>
#include <functional>

#include <Engine/Engine.h>
#include <Engine/Input/InputCodes.h>
#include <Engine/Input/TextBuffer.h>
#include <Engine/Graphics/Visual.h>

using namespace std;
using namespace std::placeholders;
using namespace input;
using namespace graphics;

Paddle::Paddle()
	: m_vPos(Vec2(0.0f, 0.0f))
	, m_bLeft(false)
	, m_bRight(false)
	, m_bUp(false)
	, m_bDown(false)
	, m_bAction(false)
	, m_uVisual(~0)
	, m_bInputMode(false)
	, m_sCommand("")
{
}

Paddle::~Paddle()
{
	engine().visuals().removeVisual(m_uVisual2);
	engine().visuals().removeVisual(m_uVisual);
	engine().sounds().removeSound(m_uSound);
	engine().visuals().removeVisualText(m_uText);
	engine().inputs().removeTextBuffer(m_uTextBuffer);
}

void Paddle::onInit()
{
	// TODO: Create visuals, collision objects, sounds i.e. all the components that make up the Paddle object
	m_uVisual = engine().visuals().createVisual("../Data/Textures/test.tga");
	m_uVisual2 = engine().visuals().createVisual("../Data/Textures/test2.tga");
	engine().visuals().modifyVisual(m_uVisual2).setSize(Vec2(0.25f, 0.25f));
	m_uSound = engine().sounds().createSound("../Data/Sounds/beep.wav");
	m_uText = engine().visuals().createVisualText("../Data/Fonts/impact.ttf");
	m_uTextBuffer = engine().inputs().createTextBuffer();
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

	handleTextInput();

	auto vMouseMove = is.getMousePosRel();
	if (vMouseMove.x != 0 || vMouseMove.y != 0)
	{
		m_vPos += vMouseMove;
		//cout << "Mouse move: " << vMouseMove.x << ", " << vMouseMove.y << endl;
	}
}

void Paddle::handleTextInput()
{
	auto& textBuffer = engine().inputs().modifyTextBuffer(m_uTextBuffer);

	if (textBuffer.getBuffer().empty())
		return;

	for (const auto& ch : textBuffer.getBuffer())
	{
		if (m_bInputMode)
		{
			if (ch != 13)
				m_sCommand += ch;
			else
				processCommand();
		}
		else if (ch == 'i')
		{
			m_bInputMode = true;
			m_sCommand.clear();
		}
	}

	textBuffer.clean();
}

void Paddle::processCommand()
{
	cout << "Command: " << m_sCommand << std::endl;
	m_sCommand.clear();
	m_bInputMode = false;
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
	auto& rVisual2 = engine().visuals().modifyVisual(m_uVisual2);
	rVisual2.setPosition(m_vPos);
}
