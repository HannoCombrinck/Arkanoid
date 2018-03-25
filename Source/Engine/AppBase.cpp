#include "AppBase.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <Engine/EngineSystems.h>
#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>

using namespace sf;
using namespace std;
using namespace core;
using namespace input;
using namespace graphics;

AppBase::AppBase()
	: m_fDeltaTime(0.0f)
	, m_bMouseLock(false)
{
	m_upWindow = unique_ptr<RenderWindow>(new RenderWindow);
	m_upClock = unique_ptr<Clock>(new Clock);
	m_upEngineSystems = unique_ptr<EngineSystems>(new EngineSystems(m_upWindow.get()));
}

AppBase::~AppBase()
{
}

void AppBase::start()
{
	onInit();
	while (m_upWindow->isOpen())
	{
		handleEvents();
		checkTime();
		update();
		render();
	}
}

void AppBase::closeApplication()
{
	m_upWindow->close();
}

void AppBase::toggleFullscreen()
{
	engine().visuals().toggleFullscreen();
}

void AppBase::toggleMouseLock()
{
	m_bMouseLock = !m_bMouseLock;
	//m_upWindow->setMouseCursorGrabbed(m_bMouseLock);
	m_upWindow->setMouseCursorVisible(!m_bMouseLock);
}

void AppBase::toggleVSync()
{
	engine().visuals().toggleVSync();
}

EngineSystems& AppBase::engine()
{
	return *m_upEngineSystems;
}

void AppBase::update()
{
	engine().update(m_fDeltaTime);
	onUpdate(m_fDeltaTime);
}

void AppBase::render()
{
	// TODO: Do preRenderUpdate so visuals have latest information
	engine().visuals().render();
}

void AppBase::handleEvents()
{
	Event e;
	while (m_upWindow->pollEvent(e))
	{
		switch (e.type)
		{
		case Event::Closed:
			m_upWindow->close();
			break;
		case Event::Resized:
			engine().visuals().resize(e.size.width, e.size.height);
			break;
		case Event::KeyPressed:
		{
			auto key = KeyboardKey(e.key.code);
			onKeyPressed(key);
			engine().inputs().keyPressed(key);
		}
		break;
		case Event::KeyReleased:
		{
			auto key = KeyboardKey(e.key.code);
			onKeyReleased(key);
			engine().inputs().keyReleased(key);
		}
		break;
		case Event::TextEntered:
			if (e.text.unicode < 128)
			{
				onCharEntered(static_cast<char>(e.text.unicode));
				engine().inputs().charEntered(static_cast<char>(e.text.unicode));
			}
			break;
		case Event::MouseButtonPressed:
		{
			auto btn = MouseButton(e.mouseButton.button);
			onMBPressed(btn);
			engine().inputs().mbPressed(btn);
		}
		break;
		case Event::MouseButtonReleased:
		{
			auto btn = MouseButton(e.mouseButton.button);
			onMBReleased(btn);
			engine().inputs().mbReleased(btn);
		}
		break;
		}
	}

	handleMouseInput();
}

void AppBase::handleMouseInput()
{
	auto vMousePosScreen = Mouse::getPosition();
	if (m_bMouseLock)
	{
		auto vWindowSize = m_upWindow->getSize();
		auto vWindowPos = m_upWindow->getPosition();
		auto vCenter = Vector2i(vWindowPos.x + int(vWindowSize.x) / 2, vWindowPos.y + int(vWindowSize.y) / 2);
		auto vDiff = vMousePosScreen - vCenter;
		if (vDiff.x != 0 || vDiff.y != 0)
		{
			Mouse::setPosition(vCenter);
			onMouseMovedRel(vDiff.x, vDiff.y);
		}

		engine().inputs().mouseMovedRel(vDiff.x, vDiff.y);
		return;
	}

	auto vMousePosWindow = Mouse::getPosition(*m_upWindow);
	if (vMousePosWindow.x != m_vMousePos.x || vMousePosWindow.y != m_vMousePos.y)
	{
		auto iX = vMousePosWindow.x;
		auto iY = vMousePosWindow.y;
		engine().inputs().mouseMoved(iX, iY);
		engine().inputs().mouseMovedRel(iX - m_vMousePos.x, iY - m_vMousePos.y);
		onMouseMovedRel(iX - m_vMousePos.x, iY - m_vMousePos.y);
		onMouseMoved(iX, iY);
		m_vMousePos = Vec2(iX, iY);
		return;
	}

	engine().inputs().mouseMovedRel(0, 0);
}

void AppBase::checkTime()
{
	m_fDeltaTime = m_upClock->restart().asSeconds();
}
