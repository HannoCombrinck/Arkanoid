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
		Vec2 getPosition() const;

		void setSize(const Vec2& vSize);
		Vec2 getSize() const;

		void setColour(uint r, uint g, uint b, uint a);
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
