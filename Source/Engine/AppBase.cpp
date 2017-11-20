#include "AppBase.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <Engine/EngineSystems.h>
#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>

using namespace sf;
using namespace std;
using namespace input;
using namespace graphics;

AppBase::AppBase()
	: m_bFullscreen(false)
	, m_bVSync(true)
	, m_fDeltaTime(0.0f)
{
	m_upWindow = make_unique<RenderWindow>();
	m_upWindow->create(VideoMode(800U, 600U, 32U), "Test");
	m_upWindow->setVerticalSyncEnabled(m_bVSync);

	m_upClock = make_unique<Clock>();

	m_upEngineSystems = make_unique<EngineSystems>(m_upWindow.get());
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
	m_bFullscreen = !m_bFullscreen;
	if (m_bFullscreen)
		m_upWindow->create(VideoMode::getDesktopMode(), "Test", Style::Fullscreen);
	else
		m_upWindow->create(VideoMode(800U, 600U, 32U), "Test");

	m_upWindow->setVerticalSyncEnabled(true);
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
		case Event::MouseMoved:
			onMouseMoved(e.mouseMove.x, e.mouseMove.y);
			engine().inputs().mouseMoved(e.mouseMove.x, e.mouseMove.y);
			break;
		}
	}
}

void AppBase::checkTime()
{
	m_fDeltaTime = m_upClock->restart().asSeconds();
}
