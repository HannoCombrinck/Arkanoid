#pragma once
#include <memory>

#include <Engine/Graphics/VisualShape.h>

using namespace math;

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
		Vec2 getPosition() const;

		void setRadius(float fRadius);
		float getRadius() const;

		void setColour(uint r, uint g, uint b, uint a);
		void getColour(uint& r, uint& g, uint& b, uint& a) const;

	private:
        void onCreated() override;
        void onUpdate(float fDT) override;
        void onDraw(sf::RenderWindow& window) override;

        sf::CircleShape m_Circle;
	};
}
