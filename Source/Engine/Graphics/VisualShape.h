#pragma once
#include <memory>

#include <Engine/Math/Math.h>
#include <Engine/Core/GlobalTypes.h>
#include <SFML/Graphics.hpp>

using namespace core;

namespace graphics
{
	class VisualSystem;
}

namespace graphics
{
	class VisualShape
	{
	public:
		VisualShape();
		virtual ~VisualShape();

		void init(VisualSystem* pVisualSystem);
		void created();
		bool alive() const;
		void clean();
		void update(float fDT);
		void draw(sf::RenderWindow& window);

	private:
        virtual void onInit(VisualSystem* pVisualSystem) {}
        virtual void onCreated() {}
        virtual void onClean() {}
		virtual void onUpdate(float fDT) {}
		virtual void onDraw(sf::RenderWindow& window) {}

		friend class VisualSystem;
		VisualSystem* m_pVisualSystem;
		bool m_bAlive;
	};
}
