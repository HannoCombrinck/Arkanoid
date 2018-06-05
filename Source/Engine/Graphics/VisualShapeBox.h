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
	class VisualShapeBox : public VisualShape
	{
	public:
		VisualShapeBox();
		virtual ~VisualShapeBox();

		VisualShapeBox& setPosition(const Vec2& vPos);
		Vec2 getPosition() const;

		VisualShapeBox& setSize(const Vec2& vSize);
		Vec2 getSize() const;

		VisualShapeBox& setColour(uint r, uint g, uint b, uint a);
		void getColour(uint& r, uint& g, uint& b, uint& a) const;

	private:
        void onInit(VisualSystem* pVisualSystem) override;
        void onCreated() override;
        void onClean() override;
        void onUpdate(float fDT) override;
        void onDraw(sf::RenderWindow& window) override;

        sf::RectangleShape m_Rectangle;

	};
}
