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
	class VisualShapeCircle : public VisualShape
	{
	public:
		VisualShapeCircle();
		virtual ~VisualShapeCircle();

		void setPosition(const Vec2& vPos);
		const Vec2& getPosition() const;

		void setRadius(float fRadius);
		float getRadius() const;

		void setColour(const Vec4& vColour);
		const Vec4& getColour() const;

	private:
        void onCreated() override;
        void onUpdate(float fDT) override;
        void onDraw(sf::RenderWindow& window) override;

        sf::CircleShape m_Circle;
	};
}
