#include "VisualSystem.h"

#include <iostream>
#include <vector>


#include <Engine/Graphics/VisualText.h>

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

		m_pSFML->font.loadFromFile("../Data/Fonts/impact.ttf");
		m_pSFML->text.move(10.0f, 5.0f);
		m_pSFML->text.setFont(m_pSFML->font);
		m_pSFML->text.setCharacterSize(20U);

		CREATE_COMPONENT_HANDLER(Visual, 20U);
		CREATE_COMPONENT_HANDLER(VisualText, 20U);
	}

	VisualSystem::~VisualSystem()
	{
		delete m_pSFML;
	}
	
	void VisualSystem::update(float fDT)
	{
		m_fDeltaTime = fDT;
		m_fDeltaTimeSmoothed = m_fDeltaTimeSmoothed*0.98f + m_fDeltaTime*0.02f;

		/*auto uSize = m_upCompHandler->getSize();
		auto& aData = m_upCompHandler->getData();
		for (uint i = 0U; i < uSize; ++i)
			aData[i].update(fDT);*/

		m_upVisualHandler->foreach([fDT](Visual& v) {
			v.update(fDT);
		});
	}

	void VisualSystem::render()
	{
		m_pSFML->pWindow->clear();
		// Draw custom OpenGL stuff here
		m_pSFML->pWindow->pushGLStates();
		// Draw via SFML (Convenient wrappers for text, 2d rendering etc.)

		//////
		// TEMP TEST RENDERING
		
		// Draw sprites
		auto pWindow = m_pSFML->pWindow;
		m_upVisualHandler->foreach([pWindow](Visual& v) {
			pWindow->draw(v.m_Sprite); 
		});

		m_pSFML->text.setString(to_string(1.0f / m_fDeltaTimeSmoothed));
		auto c1 = Color(66U, 203U, 248U);
		auto c2 = Color(61U, 155U, 161U);
		auto c3 = Color(18U, 60U, 87U);

		auto cTB = Color(20U, 204U, 250U);
		auto cTD = Color(4U, 82U, 113U);

		m_pSFML->text.setFillColor(c2);
		m_pSFML->text.setPosition(10.0f, 5.0f);
		m_pSFML->pWindow->draw(m_pSFML->text);

		m_pSFML->text.setString("BRIGHT");
		m_pSFML->text.setFillColor(cTB);
		m_pSFML->text.setPosition(10.0f, 35.0f);
		m_pSFML->pWindow->draw(m_pSFML->text);
		m_pSFML->text.setString("Dim Text");
		m_pSFML->text.setFillColor(cTD);
		m_pSFML->text.setPosition(150.0f, 35.0f);
		m_pSFML->pWindow->draw(m_pSFML->text);

		m_upVisualTextHandler->foreach([pWindow](VisualText& vt) {
			pWindow->draw(vt.m_Text);
		});
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

	void VisualSystem::toggleVSync()
	{
		m_bVSync = !m_bVSync;
		m_pSFML->pWindow->setVerticalSyncEnabled(m_bVSync);
	}

}