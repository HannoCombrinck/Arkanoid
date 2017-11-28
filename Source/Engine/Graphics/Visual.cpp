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
	{
		m_uSprite = m_pVisualSystem->createSprite("../Data/Textures/test.tga");
	}

	Visual::~Visual()
	{
		m_pVisualSystem->removeSprite(m_uSprite);
		m_uSprite = ~0;
	}

	void Visual::update(float fDT)
	{
		if (m_uSprite == ~0)
			return;

		m_pVisualSystem->modifySprite(m_uSprite).setPosition(m_vPos.x, m_vPos.y);
	}
	
}