#include "Paddle.h"

#include <iostream>
#include <functional>

#include <Engine/Engine.h>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;

Paddle::Paddle()
	: m_vPos(Vec2(0.0f, 0.0f))
	, m_bLeft(false)
	, m_bRight(false)
	, m_bUp(false)
	, m_bDown(false)
	, m_bAction(false)
	, m_uVisual(~0)
	, m_uVisualBox(~0)
	, m_bInputMode(false)
	, m_sCommand("")
{
}

Paddle::~Paddle()
{
	vs().removeVisual(m_uVisual);
	vs().removeVisualShapeBox(m_uVisualBox);
	ss().removeSound(m_uSound);
	vs().removeVisualText(m_uVisualText);
	is().removeTextBuffer(m_uTextBuffer);
}

void Paddle::onInit()
{
	m_uVisual = vs().createVisual();
	vs().modifyVisual(m_uVisual).loadSprite("../Data/Textures/test.tga");

    m_uVisualBox = vs().createVisualShapeBox();
    vs().modifyVisualShapeBox(m_uVisualBox).setSize(Vec2(100.0f, 20.0f));
    vs().modifyVisualShapeBox(m_uVisualBox).setPosition(Vec2(100.0f, 100.0f));

	m_uSound = ss().createSound("../Data/Sounds/beep.wav");

	m_uVisualText = vs().createVisualText();
	vs().modifyVisualText(m_uVisualText).setText("Temp");
	vs().modifyVisualText(m_uVisualText).loadFont("../Data/Fonts/impact.ttf");

	m_uTextBuffer = is().createTextBuffer();
}

void Paddle::onUpdate(float fDT)
{
	getInputs();
	updateState();
	applyState();
}

void Paddle::getInputs()
{
	m_bLeft = is().isKeyPressed(KEY_A);
	m_bRight = is().isKeyPressed(KEY_D);
	m_bUp = is().isKeyPressed(KEY_W);
	m_bDown = is().isKeyPressed(KEY_S);
	m_bAction = is().isKeyPressed(KEY_Space) || is().isMBPressed(MB_Left);

	handleTextInput();

	auto vMouseMove = is().getMousePosRel();
	if (vMouseMove.x != 0 || vMouseMove.y != 0)
	{
		m_vPos += vMouseMove;
		//cout << "Mouse move: " << vMouseMove.x << ", " << vMouseMove.y << endl;
	}
}

void Paddle::handleTextInput()
{
	auto& textBuffer = is().modifyTextBuffer(m_uTextBuffer);

	if (textBuffer.getBuffer().empty())
		return;

	for (const auto& ch : textBuffer.getBuffer())
	{
		if (m_bInputMode)
		{
			if (ch != 13)
			{
				if (ch != 8)
					m_sCommand += ch;
				else
					m_sCommand = m_sCommand.substr(0U, m_sCommand.length() - 1);

				vs().modifyVisualText(m_uVisualText).setText(m_sCommand);
			}
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
	vs().modifyVisualText(m_uVisualText).setText(m_sCommand);
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
	auto& rVisual = vs().modifyVisual(m_uVisual);
	rVisual.setPosition(m_vPos);
}
