#include "VisualShape.h"

#include <iostream>

using namespace std;
using namespace sf;

namespace graphics {

	VisualShape::VisualShape()
		: m_bAlive(false)
	{
	}

	VisualShape::~VisualShape()
	{
	}

	void VisualShape::init()
	{
		onInit();
		m_bAlive = true;
	}

	void VisualShape::destroy()
	{
		m_bAlive = false;
		onDestroy();
	}

	bool VisualShape::alive() const
	{
		return m_bAlive;
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
