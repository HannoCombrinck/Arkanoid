#include "GraphicsSystem.h"

#include <iostream>

#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

namespace engine {

	GraphicsSystem::GraphicsSystem(RenderWindow *pWindow)
		: m_pWindow(pWindow)
		, m_fDeltaTime(0.0f)
		, m_fDeltaTimeSmoothed(0.0f)
	{
		m_upFont = make_unique<Font>();
		m_upText = make_unique<Text>();

		m_upFont->loadFromFile("../Data/Fonts/f.ttf");
		m_upText->move(10.0f, 5.0f);
		m_upText->setFont(*m_upFont);
		m_upText->setCharacterSize(10U);
	}

	GraphicsSystem::~GraphicsSystem()
	{
	}

	void GraphicsSystem::update(float fDT)
	{
		m_fDeltaTime = fDT;
		m_fDeltaTimeSmoothed = m_fDeltaTimeSmoothed*0.98f + m_fDeltaTime*0.02f;
	}

	void GraphicsSystem::render()
	{
		m_pWindow->clear();
		// Draw custom OpenGL stuff here
		m_pWindow->pushGLStates();
		// Draw via SFML (Convenient wrappers for text, 2d rendering etc.)

		//////
		// TEMP TEST RENDERING
		m_upText->setString(to_string(1.0f / m_fDeltaTimeSmoothed));
		m_pWindow->draw(*m_upText);
		//////

		m_pWindow->popGLStates();
		// Flip buffers 
		m_pWindow->display();
	}

	void GraphicsSystem::resize(int iWidth, int iHeight)
	{
		m_pWindow->setView(View(FloatRect(0, 0, float(iWidth), float(iHeight))));
	}

}