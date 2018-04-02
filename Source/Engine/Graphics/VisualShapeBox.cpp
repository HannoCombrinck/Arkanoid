#include "VisualShapeBox.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

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

    void VisualShapeBox::setPosition(const Vec2& vPos)
    {
        m_Rectangle.setPosition(vPos.x, vPos.y);
    }

    const Vec2& VisualShapeBox::getPosition() const
    {
        auto vPos = m_Rectangle.getPosition();
        return Vec2(vPos.x, vPos.y);
    }

    void VisualShapeBox::setSize(const Vec2& vSize)
    {
        m_Rectangle.setSize(Vector2f(vSize.x, vSize.y));
    }

    const Vec2& VisualShapeBox::getSize() const
    {
        auto vSize = m_Rectangle.getSize();
        return Vec2(vSize.x, vSize.y);
    }

    void VisualShapeBox::setColour(const Vec4& vColour)
    {
        m_Rectangle.setFillColor(Color(vColour.x, vColour.y, vColour.z, vColour.w));
    }

    const Vec4& VisualShapeBox::getColour() const
    {
        auto vColour = m_Rectangle.getFillColor();
        return Vec4(vColour.r, vColour.g, vColour.b, vColour.a);
    }

    void VisualShapeBox::onInit(VisualSystem* pVisualSystem)
    {
    }

    void VisualShapeBox::onCreated()
    {
    }

    void VisualShapeBox::onClean()
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
