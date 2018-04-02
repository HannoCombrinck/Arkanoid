#include "VisualShapeCircle.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

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

    const Vec2& VisualShapeCircle::getPosition() const
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

    void VisualShapeCircle::setColour(const Vec4& vColour)
    {
        m_Circle.setFillColor(Color(vColour.x, vColour.y, vColour.z, vColour.w));
    }

    const Vec4& VisualShapeCircle::getColour() const
    {
        auto vColour = m_Circle.getFillColor();
        return Vec4(vColour.r, vColour.g, vColour.b, vColour.a);
    }

    void VisualShapeCircle::onCreated()
    {
    }

	void VisualShapeCircle::onUpdate(float fDT)
	{
	}

	void VisualShapeCircle::onDraw(sf::RenderWindow& window)
	{
        window.draw(m_Circle);
	}
}
