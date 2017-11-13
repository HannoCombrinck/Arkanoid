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

EngineSystems* AppBase::engine() 
{ 
	return m_upEngineSystems.get(); 
}

void AppBase::update()
{
	engine()->update(m_fDeltaTime);

	onUpdate(m_fDeltaTime);
}

void AppBase::render()
{
	engine()->visuals()->render();
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
			engine()->visuals()->resize(e.size.width, e.size.height);
			break;
		case Event::KeyPressed:
			engine()->inputs()->keyPressed(KeyboardKey(e.key.code));
				
			{
				switch (e.key.code)
				{
				case Keyboard::Escape:
					m_upWindow->close();
					break;
				case Keyboard::F2:
				{
					m_bFullscreen = !m_bFullscreen;
					if (m_bFullscreen)
						m_upWindow->create(VideoMode::getDesktopMode(), "Test", Style::Fullscreen);
					else
						m_upWindow->create(VideoMode(800U, 600U, 32U), "Test");

					m_upWindow->setVerticalSyncEnabled(true);
				}
				break;
				}
			}
			break;
		case Event::KeyReleased:
			engine()->inputs()->keyReleased(KeyboardKey(e.key.code));
			break;
		case Event::TextEntered:
			if (e.text.unicode < 128)
				engine()->inputs()->charEntered(static_cast<char>(e.text.unicode));
			break;
		case Event::MouseButtonPressed:
			engine()->inputs()->mbPressed(MouseButton(e.mouseButton.button));
			break;
		case Event::MouseButtonReleased:
			engine()->inputs()->mbReleased(MouseButton(e.mouseButton.button));
			break;
		case Event::MouseMoved:
			engine()->inputs()->mouseMoved(e.mouseMove.x, e.mouseMove.y);
			break;
		}
	}
}

void AppBase::checkTime()
{
	m_fDeltaTime = m_upClock->restart().asSeconds();
}
