#include "VisualShape.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

using namespace std;
using namespace sf;

namespace graphics {

	VisualShape::VisualShape()
		: m_pVisualSystem(0)
		, m_bAlive(false)
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
		m_bAlive = false;
	}

	void VisualShape::update(float fDT)
	{
		if (!alive())
			return;
	}

    void VisualShape::draw(sf::RenderWindow& window)
    {
        //window.draw(
    }

}
