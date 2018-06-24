#include "VisualText.h"

#include <iostream>

using namespace std;
using namespace sf;

namespace graphics {

	VisualText::VisualText()
		: m_bAlive(false)
		, m_vPos(Vec2(0.0f, 0.0f))
		, m_bPosChanged(false)
		, m_vSize(Vec2(1.0f, 1.0f))
		, m_bSizeChanged(false)
	{
	}

	VisualText::~VisualText()
	{
	}

	void VisualText::init()
	{
		m_bAlive = true;
	}

	void VisualText::destroy()
	{
		m_bAlive = false;
		m_Text = sf::Text();
		m_Font = sf::Font();
	}

	bool VisualText::isAlive() const
	{
		return m_bAlive;
	}

	VisualText& VisualText::setFont(const std::string& sFilename)
	{
		m_Font.loadFromFile(sFilename);
		m_Text.setFont(m_Font);
		return *this;
	}

	void VisualText::update(float fDT)
	{
		if (!isAlive())
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
