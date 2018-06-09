#include "VisualSystem.h"

#include <iostream>
#include <vector>

#include <Engine/Graphics/VisualText.h>

#include <SFML/Graphics.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

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
        : m_bVSync(true)
		, m_bFullscreen(false)
		, m_fDeltaTime(0.0f)
		, m_fDeltaTimeSmoothed(0.0f)

	{
		m_pSFML = new SFMLMembers;
		m_pSFML->pWindow = pWindow;

		m_pSFML->pWindow->create(VideoMode(800U, 600U, 32U), "Test");
		m_pSFML->pWindow->setVerticalSyncEnabled(m_bVSync);
		auto uFrameLimit = m_bVSync ? 61U : 0U;
        m_pSFML->pWindow->setFramerateLimit(uFrameLimit);

		m_pSFML->font.loadFromFile("../Data/Fonts/impact.ttf");
		m_pSFML->text.move(10.0f, 5.0f);
		m_pSFML->text.setFont(m_pSFML->font);
		m_pSFML->text.setCharacterSize(20U);

		ImGui::SFML::Init(*m_pSFML->pWindow);

		CREATE_COMPONENT_HANDLER(Visual, 20U);
		CREATE_COMPONENT_HANDLER(VisualShapeBox, 20U);
		CREATE_COMPONENT_HANDLER(VisualShapeCircle, 20U);
		CREATE_COMPONENT_HANDLER(VisualText, 20U);
	}

	VisualSystem::~VisualSystem()
	{
		ImGui::SFML::Shutdown();
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

		VisualHandler().foreach([fDT](Visual& v) {
			v.update(fDT);
		});

		ImGui::SFML::Update(*m_pSFML->pWindow, seconds(fDT));

		///////////////////////////////////////////
		///////////////////////////////////////////
		ImGui::Begin("Sample window");
		
		static float colour[3] = { 0.0f, 0.0f, 0.0f };

		if (ImGui::ColorEdit3("Background color", colour))
		{
			cout << "Color R: " << static_cast<Uint8>(colour[0] * 255.f) << endl;
			cout << "Color G: " << static_cast<Uint8>(colour[1] * 255.f) << endl;
			cout << "Color B: " << static_cast<Uint8>(colour[2] * 255.f) << endl;
		}

		static char windowTitle[255];
		if (ImGui::InputText("Window title", windowTitle, 255))
		{
			cout << "Input text changed: " << windowTitle << endl;
		}

		if (ImGui::Button("Update window title"))
		{
			m_pSFML->pWindow->setTitle(windowTitle);
		}
		ImGui::End();
		///////////////////////////////////////////////
		///////////////////////////////////////////
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
		VisualHandler().foreach([pWindow](Visual& v) {
			pWindow->draw(v.m_Sprite);
		});

		VisualShapeBoxHandler().foreach([pWindow](VisualShapeBox& v) {
            v.draw(*pWindow);
		});

		m_pSFML->text.setString(to_string(1.0f / m_fDeltaTimeSmoothed));
		auto c1 = Color(66U, 203U, 248U);
		auto c2 = Color(61U, 155U, 161U);
		auto c3 = Color(18U, 60U, 87U);

		auto cTB = Color(20U, 204U, 250U);
		auto cTD = Color(4U, 82U, 113U);

		m_pSFML->text.setColor(c2);
		m_pSFML->text.setPosition(10.0f, 5.0f);
		m_pSFML->pWindow->draw(m_pSFML->text);

		m_pSFML->text.setString("BRIGHT");
		m_pSFML->text.setColor(cTB);
		m_pSFML->text.setPosition(10.0f, 35.0f);
		m_pSFML->pWindow->draw(m_pSFML->text);
		m_pSFML->text.setString("Dim Text");
		m_pSFML->text.setColor(cTD);
		m_pSFML->text.setPosition(150.0f, 35.0f);
		m_pSFML->pWindow->draw(m_pSFML->text);

		VisualTextHandler().foreach([pWindow](VisualText& vt) {
			pWindow->draw(vt.m_Text);
		});
		//////

		ImGui::SFML::Render(*m_pSFML->pWindow);

		m_pSFML->pWindow->popGLStates();
		// Flip buffers
		m_pSFML->pWindow->display();
	}

	void VisualSystem::processGUIEvents(const Event & e)
	{
		ImGui::SFML::ProcessEvent(e);
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
		auto uFrameLimit = m_bVSync ? 61U : 0U;
        m_pSFML->pWindow->setFramerateLimit(uFrameLimit);
	}

	void VisualSystem::toggleVSync()
	{
		m_bVSync = !m_bVSync;
		m_pSFML->pWindow->setVerticalSyncEnabled(m_bVSync);
		auto uFrameLimit = m_bVSync ? 61U : 0U;
        m_pSFML->pWindow->setFramerateLimit(uFrameLimit);
	}

}
