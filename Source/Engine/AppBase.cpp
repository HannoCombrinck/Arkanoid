#include "AppBase.h"

#include <iostream>

using namespace sf;
using namespace std;

namespace engine {

	AppBase::AppBase()
		: m_bFullscreen(false)
		, m_bVSync(true)
		, m_fDeltaTime(0.0f)
		, m_fDeltaTimeSmoothed(0.0f)
	{
		m_Window.create(VideoMode(800U, 600U, 32U), "Test");
		m_Window.setVerticalSyncEnabled(m_bVSync);

		m_Font.loadFromFile("../Data/Fonts/f.ttf");
		m_Text.move(10.0f, 5.0f);
		m_Text.setFont(m_Font);
		m_Text.setCharacterSize(10U);

		// TEMP
		if (!m_BeepSoundBuffer.loadFromFile("../Data/Sounds/beep.wav"))
			std::cout << "Couldn't load beep.wav\n";

		m_BeepSound.setBuffer(m_BeepSoundBuffer);

		if (!m_Music.openFromFile("../Data/Sounds/ambient.ogg"))
			std::cout << "Couldn't load ambient.ogg";

		m_Music.setLoop(true);
		m_Music.play();
		//

		// Initialize systems
		//m_Systems.spVS = boost::make_shared<VisualSystem>();
		//m_Systems.spPS = boost::make_shared<PhysicsSystem>();
		//m_Systems.spSS = boost::make_shared<SoundSystem>();
		//m_Systems.spIS = boost::make_shared<InputSystem>();
	}

	AppBase::~AppBase()
	{

	}

	void AppBase::startMainLoop()
	{
		while (m_Window.isOpen())
		{
			handleEvents();
			checkTime();
			update();
			render();
		}
	}

	void AppBase::update()
	{
		// Systems updates
		//m_Systems.spIS->update(ddT);
		//m_Systems.spPS->update(ddT);
		//m_Systems.spSS->update(ddT);
		//m_Systems.spVS->update(ddT);
		onUpdate(m_fDeltaTime);
	}

	void AppBase::render()
	{
		// for all entities: preRender()
		//m_Systems.spVS->render();
		// for all entities: postRender()

		// Clear the back buffer
		m_Window.clear();
		
		// Draw custom OpenGL stuff here
		
		// Draw via SFML (Convenient wrappers for text, 2d rendering etc.)
		m_Window.pushGLStates();
		m_Text.setString(to_string(1.0f / m_fDeltaTimeSmoothed));
		m_Window.draw(m_Text);
		m_Window.popGLStates();

		// Flip buffers 
		m_Window.display();
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
			{
				if (m_BeepSound.getStatus() == Sound::Playing)
					m_BeepSound.stop();
				
				m_BeepSound.play();

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
			}
		}
	}

	void AppBase::checkTime()
	{
		m_fDeltaTime = m_Clock.restart().asSeconds();
		m_fDeltaTimeSmoothed = m_fDeltaTimeSmoothed*0.98f + m_fDeltaTime*0.02f;
	}

}