#pragma once
#include <memory>

#include <Engine/Graphics/VisualShape.h>

using namespace core;

namespace graphics
{
	class VisualSystem;
}

namespace graphics
{
	class VisualShapeBox : public VisualShape
	{
	public:
		VisualShapeBox();
		virtual ~VisualShapeBox();

		void setPosition(const Vec2& vPos);
		const Vec2& getPosition() const;

		void setSize(const Vec2& vSize);
		const Vec2& getSize() const;

		void setColour(const Vec4& vColour);
		const Vec4& getColour() const;

	private:
        void onUpdate(float fDT);
        void onDraw(sf::RenderWindow& window);

        sf::RectangleShape m_Rectangle;

        Vec2 m_vPos;
        Vec2 m_vSize;
        Vec4 m_vColour;

	};
}
