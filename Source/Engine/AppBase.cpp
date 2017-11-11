#include "AppBase.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>

using namespace sf;
using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;

AppBase::AppBase()
	: m_bFullscreen(false)
	, m_bVSync(true)
	, m_fDeltaTime(0.0f)
{
	m_upWindow = make_unique<RenderWindow>();
	m_upWindow->create(VideoMode(800U, 600U, 32U), "Test");
	m_upWindow->setVerticalSyncEnabled(m_bVSync);

	m_upClock = make_unique<Clock>();

	m_upInputSystem = make_unique<InputSystem>();
	m_upVisualSystem = make_unique<VisualSystem>(m_upWindow.get());
	m_upSoundSystem = make_unique<SoundSystem>();
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

void AppBase::update()
{
	m_upInputSystem->update(m_fDeltaTime);
	m_upVisualSystem->update(m_fDeltaTime);
	m_upSoundSystem->update(m_fDeltaTime);

	onUpdate(m_fDeltaTime);
}

void AppBase::render()
{
	m_upVisualSystem->render();
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
			m_upVisualSystem->resize(e.size.width, e.size.height);
			break;
		case Event::KeyPressed:
			m_upInputSystem->keyPressed(KeyboardKey(e.key.code));
				
			{
				switch (e.key.code)
				{
				case Keyboard::Escape:
					m_upWindow->close();
					break;
				case Keyboard::F:
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
			m_upInputSystem->keyReleased(KeyboardKey(e.key.code));
			break;
		case Event::TextEntered:
			if (e.text.unicode < 128)
				m_upInputSystem->charEntered(static_cast<char>(e.text.unicode));
			break;
		case Event::MouseButtonPressed:
			m_upInputSystem->mbPressed(MouseButton(e.mouseButton.button));
			break;
		case Event::MouseButtonReleased:
			m_upInputSystem->mbReleased(MouseButton(e.mouseButton.button));
			break;
		case Event::MouseMoved:
			m_upInputSystem->mouseMoved(e.mouseMove.x, e.mouseMove.y);
			break;
		}
	}
}

void AppBase::checkTime()
{
	m_fDeltaTime = m_upClock->restart().asSeconds();
}
