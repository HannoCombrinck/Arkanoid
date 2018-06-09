#include "Visual.h"

#include <iostream>

using namespace std;
using namespace sf;

namespace graphics {

	Visual::Visual()
		: m_bAlive(false)
		, m_uSprite(~0)
		, m_vPos(Vec2(0.0f, 0.0f))
		, m_bPosChanged(false)
		, m_vSize(Vec2(1.0f, 1.0f))
		, m_bSizeChanged(false)
	{
	}

	Visual::~Visual()
	{
	}

	void Visual::init()
	{
		m_bAlive = true;
	}

	void Visual::destroy()
	{
		m_bAlive = false;
		m_Texture = sf::Texture();
		m_Sprite = sf::Sprite();
	}

	bool Visual::alive() const
	{
		return m_bAlive;
	}
		
	Visual& Visual::loadSprite(const std::string& sFilename)
	{
		m_Texture.loadFromFile(sFilename);
		m_Sprite.setTexture(m_Texture);
		return *this;
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

	Visual& Visual::setPosition(const Vec2& vPos)
	{
		m_bPosChanged = true;
		m_vPos = vPos;
		return *this;
	}

	Visual& Visual::setSize(const Vec2 & vSize)
	{
		m_bSizeChanged = true;
		m_vSize = vSize;
		return *this;
	}

}
