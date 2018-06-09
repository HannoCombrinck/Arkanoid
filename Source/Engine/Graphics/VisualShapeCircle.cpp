#include "VisualShapeCircle.h"

#include <iostream>

using namespace std;
using namespace sf;

namespace graphics {

	VisualShapeCircle::VisualShapeCircle()
		: VisualShape()
	{
	}

	VisualShapeCircle::~VisualShapeCircle()
	{
	}

    void VisualShapeCircle::setPosition(const Vec2& vPos)
    {
        m_Circle.setPosition(vPos.x, vPos.y);
    }

    Vec2 VisualShapeCircle::getPosition() const
    {
        auto vPos = m_Circle.getPosition();
        return Vec2(vPos.x, vPos.y);
    }

    void VisualShapeCircle::setRadius(float fRadius)
    {
        m_Circle.setRadius(fRadius);
    }

    float VisualShapeCircle::getRadius() const
    {
        return m_Circle.getRadius();
    }

    void VisualShapeCircle::setColour(uint r, uint g, uint b, uint a)
    {
        m_Circle.setFillColor(Color(r, g, b, a));
    }

    void VisualShapeCircle::getColour(uint& r, uint& g, uint& b, uint& a) const
    {
        auto Colour = m_Circle.getFillColor();
		r = Colour.r;
		g = Colour.g;
		b = Colour.b;
		a = Colour.a;
    }

	void VisualShapeCircle::onUpdate(float fDT)
	{
	}

	void VisualShapeCircle::onDraw(sf::RenderWindow& window)
	{
        window.draw(m_Circle);
	}
}
