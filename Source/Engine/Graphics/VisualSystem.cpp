#include "VisualSystem.h"

#include <iostream>
#include <vector>

#include <Engine/Graphics/Visual.h>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace graphics {

	struct VisualSystem::SFMLMembers
	{
		RenderWindow *pWindow;
		Font font;
		Text text;
	};

	VisualSystem::VisualSystem(RenderWindow *pWindow)
		: m_fDeltaTime(0.0f)
		, m_fDeltaTimeSmoothed(0.0f)
		, m_bVSync(true)
		, m_bFullscreen(false)
	{
		m_pSFML = new SFMLMembers;
		m_pSFML->pWindow = pWindow;

		m_pSFML->pWindow->create(VideoMode(800U, 600U, 32U), "Test");
		m_pSFML->pWindow->setVerticalSyncEnabled(m_bVSync);

		m_pSFML->font.loadFromFile("../Data/Fonts/f.ttf");
		m_pSFML->text.move(10.0f, 5.0f);
		m_pSFML->text.setFont(m_pSFML->font);
		m_pSFML->text.setCharacterSize(10U);
	}

	VisualSystem::~VisualSystem()
	{
		delete m_pSFML;
	}

	boost::shared_ptr<Visual> VisualSystem::createVisual()
	{
		auto spVisual = new Visual(this);
		return nullPtr;
	}

	void VisualSystem::update(float fDT)
	{
		m_fDeltaTime = fDT;
		m_fDeltaTimeSmoothed = m_fDeltaTimeSmoothed*0.98f + m_fDeltaTime*0.02f;
	}

	void VisualSystem::render()
	{
		m_pSFML->pWindow->clear();
		// Draw custom OpenGL stuff here
		m_pSFML->pWindow->pushGLStates();
		// Draw via SFML (Convenient wrappers for text, 2d rendering etc.)

		//////
		// TEMP TEST RENDERING
		m_pSFML->text.setString(to_string(1.0f / m_fDeltaTimeSmoothed));
		m_pSFML->pWindow->draw(m_pSFML->text);
		//////

		m_pSFML->pWindow->popGLStates();
		// Flip buffers 
		m_pSFML->pWindow->display();
	}

	void VisualSystem::resize(int iWidth, int iHeight)
	{
		m_pSFML->pWindow->setView(View(FloatRect(0, 0, float(iWidth), float(iHeight))));
	}

	void VisualSystem::toggleFullscreen()
	{
		m_bFullscreen = !m_bFullscreen;
		if (m_bFullscreen)
			m_pSFML->pWindow->create(VideoMode::getDesktopMode(), "Test", Style::Fullscreen);
		else
			m_pSFML->pWindow->create(VideoMode(800U, 600U, 32U), "Test");

		m_pSFML->pWindow->setVerticalSyncEnabled(m_bVSync);
	}
	
}