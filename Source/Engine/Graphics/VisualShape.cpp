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
		onInit(pVisualSystem);
	}

	void VisualShape::created()
	{
        m_bAlive = true;
        onCreated();
	}

	bool VisualShape::alive() const
	{
		return m_bAlive;
	}

	void VisualShape::clean()
	{
		m_bAlive = false;
		onClean();
	}

	void VisualShape::update(float fDT)
	{
		if (!alive())
			return;

        onUpdate(fDT);
	}

    void VisualShape::draw(sf::RenderWindow& window)
    {
        onDraw(window);
    }

}
