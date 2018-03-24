#include "VisualShape.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

using namespace std;
using namespace sf;

namespace graphics {
	
	VisualShape::VisualShape()
		: m_pVisualSystem(0)
		, m_bAlive(false)
		, m_eType(SHAPE_BOX)
		, m_vPos(Vec2(0.0f, 0.0f))
		, m_bPosChanged(false)
		, m_vSize(Vec2(1.0f, 1.0f))
		, m_bSizeChanged(false)
	{
	}

	VisualShape::~VisualShape()
	{
	}

	void VisualShape::init(VisualSystem* pVisualSystem)
	{
		m_pVisualSystem = pVisualSystem;
	}

	bool VisualShape::alive() const
	{
		return m_bAlive;
	}

	void VisualShape::clean()
	{
		m_Sprite = sf::Sprite();
		m_bAlive = false;
	}

	void VisualShape::update(float fDT)
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
	
	void VisualShape::setType(EShapeType eType)
	{
		m_eType = eType;
	}

	void VisualShape::setPosition(const Vec2& vPos)
	{
		m_bPosChanged = true;
		m_vPos = vPos;
		
	}

	void VisualShape::setSize(const Vec2 & vSize)
	{
		m_bSizeChanged = true;
		m_vSize = vSize;
	}

}