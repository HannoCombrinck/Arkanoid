#include "Visual.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace graphics {

	Visual::Visual(VisualSystem* pVisualSystem)
		: m_pVisualSystem(pVisualSystem)
		, m_uSprite(~0)
		, m_vPos(Vec2(0.0f, 0.0f))
		, m_bPosChanged(false)
		, m_vSize(Vec2(1.0f, 1.0f))
		, m_bSizeChanged(false)
	{
		m_uSprite = m_pVisualSystem->createSprite("../Data/Textures/test.tga");
	}

	Visual::~Visual()
	{
		if (m_uSprite == ~0)
			return;

		m_pVisualSystem->removeSprite(m_uSprite);
		m_uSprite = ~0;
	}

	void Visual::update(float fDT)
	{
		if (m_uSprite == ~0)
			return;

		if (m_bPosChanged)
		{
			m_pVisualSystem->modifySprite(m_uSprite).setPosition(m_vPos.x, m_vPos.y);
			m_bPosChanged = false;
		}
		if (m_bSizeChanged)
		{
			m_pVisualSystem->modifySprite(m_uSprite).setScale(m_vSize.x, m_vSize.y);
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