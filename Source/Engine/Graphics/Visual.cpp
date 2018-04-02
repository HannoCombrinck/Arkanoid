#include "Visual.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

using namespace std;
using namespace sf;

namespace graphics {

	Visual::Visual()
		: m_pVisualSystem(0)
		, m_bAlive(false)
		, m_uSprite(~0)
		, m_vPos(Vec2(0.0f, 0.0f))
		, m_bPosChanged(false)
		, m_vSize(Vec2(1.0f, 1.0f))
		, m_bSizeChanged(false)
	{
	}

	Visual::~Visual()
	{
		/*if (m_uSprite == ~0)
			return;

		m_pVisualSystem->removeSprite(m_uSprite);
		m_uSprite = ~0;*/
	}

	void Visual::init(VisualSystem* pVisualSystem)
	{
		m_pVisualSystem = pVisualSystem;
	}

	void Visual::created()
	{
	}

	bool Visual::alive() const
	{
		return m_bAlive;
	}

	void Visual::clean()
	{
		m_Texture = sf::Texture();
		m_Sprite = sf::Sprite();
		m_bAlive = false;
		/*if (m_uSprite == ~0)
			return;

		m_pVisualSystem->removeSprite(m_uSprite);
		m_uSprite = ~0;*/
	}

	void Visual::loadSprite(const std::string& sFilename)
	{
		//m_uSprite = m_pVisualSystem->createSprite(sFilename);
		m_Texture.loadFromFile(sFilename);
		m_Sprite.setTexture(m_Texture);
		m_bAlive = true;
	}

	void Visual::update(float fDT)
	{
		if (!alive())
			return;

		if (m_bPosChanged)
		{
			m_Sprite.setPosition(m_vPos.x, m_vPos.y);
			m_bPosChanged = false;
		}
		if (m_bSizeChanged)
		{
			m_Sprite.setScale(m_vSize.x, m_vSize.y);
			m_bSizeChanged = false;
		}
	}

	void Visual::setPosition(const Vec2& vPos)
	{
		m_bPosChanged = true;
		m_vPos = vPos;

	}

	void Visual::setSize(const Vec2 & vSize)
	{
		m_bSizeChanged = true;
		m_vSize = vSize;
	}

}
