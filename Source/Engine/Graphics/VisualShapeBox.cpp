#include "VisualShapeBox.h"

#include <iostream>

using namespace std;
using namespace sf;

namespace graphics {

	VisualShapeBox::VisualShapeBox()
		: VisualShape()
	{
	}

	VisualShapeBox::~VisualShapeBox()
	{
	}

	VisualShapeBox& VisualShapeBox::setPosition(const Vec2& vPos)
    {
        m_Rectangle.setPosition(vPos.x, vPos.y);
		return *this;
    }

    Vec2 VisualShapeBox::getPosition() const
    {
        auto vPos = m_Rectangle.getPosition();
        return Vec2(vPos.x, vPos.y);
    }

	VisualShapeBox& VisualShapeBox::setSize(const Vec2& vSize)
    {
        m_Rectangle.setSize(Vector2f(vSize.x, vSize.y));
		return *this;
    }

    Vec2 VisualShapeBox::getSize() const
    {
        auto vSize = m_Rectangle.getSize();
        return Vec2(vSize.x, vSize.y);
    }

	VisualShapeBox& VisualShapeBox::setColour(uint r, uint g, uint b, uint a)
	{
		m_Rectangle.setFillColor(Color(r, g, b, a));
		return *this;
	}

	void VisualShapeBox::getColour(uint& r, uint& g, uint& b, uint& a) const
	{
		auto Colour = m_Rectangle.getFillColor();
		r = Colour.r;
		g = Colour.g;
		b = Colour.b;
		a = Colour.a;
	}

    void VisualShapeBox::onInit()
    {
    }

	void VisualShapeBox::onUpdate(float fDT)
	{
	}

	void VisualShapeBox::onDraw(sf::RenderWindow& window)
	{
        window.draw(m_Rectangle);
	}
}
