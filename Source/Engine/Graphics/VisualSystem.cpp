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
		vector<pair<Sprite,Texture>> aSprites;
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

		/////////////////////////////////////
		m_upCompHandler = std::make_unique<visual_handler_type>(this, 20U);
		/////////////////////////////////////
	}

	VisualSystem::~VisualSystem()
	{
		//m_aupVisuals.clear();

		delete m_pSFML;
	}

	uint VisualSystem::createVisual(const std::string& sFilename)
	{
		auto uHandle = m_upCompHandler->create();
		m_upCompHandler->modify(uHandle).loadSprite(sFilename);
		return uHandle;

		//auto upVisual = std::make_unique<Visual>(this);
		//upVisual->loadSprite(sFilename);
		//m_aupVisuals.push_back(std::move(upVisual));
		//return m_aupVisuals.size() - 1;
	}

	graphics::Visual& VisualSystem::modifyVisual(uint uVisual)
	{
		return m_upCompHandler->modify(uVisual);

		//assert(uVisual < m_aupVisuals.size());
		//return *(m_aupVisuals[uVisual]);
	}	

	void VisualSystem::removeVisual(uint uVisual)
	{
		m_upCompHandler->remove(uVisual);

		//m_aupVisuals.erase(m_aupVisuals.begin() + uVisual);
	}

	void VisualSystem::update(float fDT)
	{
		m_fDeltaTime = fDT;
		m_fDeltaTimeSmoothed = m_fDeltaTimeSmoothed*0.98f + m_fDeltaTime*0.02f;

		//for (auto& v : m_aupVisuals)
		//	v->update(fDT);

		/*auto uSize = m_upCompHandler->getSize();
		auto& aData = m_upCompHandler->getData();
		for (uint i = 0U; i < uSize; ++i)
			aData[i].update(fDT);*/

		m_upCompHandler->foreach([fDT](Visual& v) {
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
		for (const auto& s : m_pSFML->aSprites)
			m_pSFML->pWindow->draw(s.first);

		auto pWindow = m_pSFML->pWindow;
		m_upCompHandler->foreach([pWindow](Visual& v) {
			pWindow->draw(v.m_Sprite); 
		});

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

	void VisualSystem::toggleVSync()
	{
		m_bVSync = !m_bVSync;
		m_pSFML->pWindow->setVerticalSyncEnabled(m_bVSync);
	}
	
	uint VisualSystem::createSprite(const std::string& sTextureFilename)
	{
		auto uIndex = m_pSFML->aSprites.size();
		m_pSFML->aSprites.resize(uIndex + 1);
		auto& rTex = m_pSFML->aSprites[uIndex].second;
		rTex.loadFromFile(sTextureFilename);
		m_pSFML->aSprites[uIndex].first.setTexture(rTex);
		return uIndex;
	}

	void VisualSystem::removeSprite(uint uHandle)
	{
		//m_aspVisuals
		m_pSFML->aSprites.erase(m_pSFML->aSprites.begin() + uHandle);
	}

	Sprite& VisualSystem::modifySprite(uint uHandle)
	{
		return m_pSFML->aSprites[uHandle].first;
	}

}