#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Math/Math.h>
#include <SFML/Graphics.hpp>

using namespace math;

namespace graphics
{
	class VisualShape
	{
	public:
		VisualShape();
		virtual ~VisualShape();

		void init();
		void destroy();
		bool isAlive() const;

		void update(float fDT);
		void draw(sf::RenderWindow& window);

	private:
        virtual void onInit() {}
        virtual void onDestroy() {}
		virtual void onUpdate(float fDT) {}
		virtual void onDraw(sf::RenderWindow& window) {}

		friend class VisualSystem;
		bool m_bAlive;
	};
}
