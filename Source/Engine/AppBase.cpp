#include "AppBase.h"

#include <iostream>

#include <Engine/InputSystem.h>
#include <Engine/GraphicsSystem.h>
#include <Engine/SoundSystem.h>

using namespace sf;
using namespace std;

namespace engine {

	AppBase::AppBase()
		: m_bFullscreen(false)
		, m_bVSync(true)
		, m_fDeltaTime(0.0f)
	{
		m_Window.create(VideoMode(800U, 600U, 32U), "Test");
		m_Window.setVerticalSyncEnabled(m_bVSync);

		m_upInputSystem = make_unique<InputSystem>();
		m_upGraphicsSystem = make_unique<GraphicsSystem>(&m_Window);
		m_upSoundSystem = make_unique<SoundSystem>();

		// Initialize systems
		//m_Systems.spVS = boost::make_shared<VisualSystem>();
		//m_Systems.spPS = boost::make_shared<PhysicsSystem>();
		//m_Systems.spSS = boost::make_shared<SoundSystem>();
		//m_Systems.spIS = boost::make_shared<InputSystem>();

		mainLoop();
	}

	AppBase::~AppBase()
	{

	}

	void AppBase::mainLoop()
	{
		while (m_Window.isOpen())
		{
			handleEvents();
			checkTime();
			update();
			render();
		}
	}

	void AppBase::closeApplication()
	{
		m_Window.close();
	}

	void AppBase::update()
	{
		m_upInputSystem->update(m_fDeltaTime);
		m_upGraphicsSystem->update(m_fDeltaTime);
		m_upSoundSystem->update(m_fDeltaTime);

		onUpdate(m_fDeltaTime);
	}

	void AppBase::render()
	{
		// for all entities: preRender()
		//m_Systems.spVS->render();
		// for all entities: postRender()
		m_upGraphicsSystem->render();
	}

	void AppBase::handleEvents()
	{
		Event e;
		while (m_Window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				m_Window.close();
				break;
			case Event::Resized:
				m_Window.setView(View(FloatRect(0, 0, float(e.size.width), float(e.size.height))));
				break;

			case Event::KeyPressed:
				m_upInputSystem->keyPressed(e.key.code);
				
				{
					switch (e.key.code)
					{
					case Keyboard::Escape:
						m_Window.close();
						break;
					case Keyboard::F:
					{
						m_bFullscreen = !m_bFullscreen;
						if (m_bFullscreen)
							m_Window.create(VideoMode::getDesktopMode(), "Test", Style::Fullscreen);
						else
							m_Window.create(VideoMode(800U, 600U, 32U), "Test");

						m_Window.setVerticalSyncEnabled(true);
					}
					break;
					}
				}
				break;
			case Event::KeyReleased:
				m_upInputSystem->keyReleased(e.key.code);
				break;
			case Event::MouseButtonPressed:
				m_upInputSystem->mbPressed(e.mouseButton.button);
				break;
			case Event::MouseButtonReleased:
				m_upInputSystem->mbReleased(e.mouseButton.button);
				break;
			case Event::MouseMoved:
				m_upInputSystem->mouseMoved(e.mouseMove.x, e.mouseMove.y);
				break;
			}
		}
	}

	void AppBase::checkTime()
	{
		m_fDeltaTime = m_Clock.restart().asSeconds();
	}

}