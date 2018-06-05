#include "VisualText.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

using namespace std;
using namespace sf;

namespace graphics {

	VisualText::VisualText()
		: m_pVisualSystem(0)
		, m_bAlive(false)
		, m_vPos(Vec2(0.0f, 0.0f))
		, m_bPosChanged(false)
		, m_vSize(Vec2(1.0f, 1.0f))
		, m_bSizeChanged(false)
	{
	}

	VisualText::~VisualText()
	{
	}

	void VisualText::init(VisualSystem* pVisualSystem)
	{
		m_pVisualSystem = pVisualSystem;
	}

	void VisualText::created()
	{
	}

	bool VisualText::alive() const
	{
		return m_bAlive;
	}

	void VisualText::clean()
	{
		m_Text = sf::Text();
		m_Font = sf::Font();
		m_bAlive = false;
	}

	VisualText& VisualText::loadFont(const std::string& sFilename)
	{
		m_Font.loadFromFile(sFilename);
		m_Text.setFont(m_Font);
		m_bAlive = true;
		return *this;
	}

	void VisualText::update(float fDT)
	{
		if (!alive())
			return;

		if (m_bPosChanged)
		{
			m_Text.setPosition(m_vPos.x, m_vPos.y);
			m_bPosChanged = false;
		}
		if (m_bSizeChanged)
		{
			m_Text.setScale(m_vSize.x, m_vSize.y);
			m_bSizeChanged = false;
		}
	}

	VisualText& VisualText::setText(const std::string & sString)
	{
		m_sString = sString;
		m_Text.setString(sString);
		return *this;
	}

	VisualText& VisualText::setPosition(const Vec2& vPos)
	{
		m_bPosChanged = true;
		m_vPos = vPos;
		return *this;
	}

	VisualText& VisualText::setSize(const Vec2 & vSize)
	{
		m_bSizeChanged = true;
		m_vSize = vSize;
		return *this;
	}

}
