#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Math/Math.h>
#include <SFML/Graphics.hpp>

using namespace math;

namespace graphics
{
	class VisualSystem;
}

namespace sf
{
	class RenderWindow;
}

namespace graphics
{
	class Visual
	{
	public:
		Visual();
		~Visual();

		void init(VisualSystem* pVisualSystem);
		void created();
		bool alive() const;
		void clean();

		void update(float fDT);
		Visual& loadSprite(const std::string& sFilename);
		Visual& setPosition(const Vec2& vPos);
		Visual& setSize(const Vec2& vSize);

	private:
		friend class VisualSystem;
		VisualSystem* m_pVisualSystem;
		bool m_bAlive;
		uint m_uSprite;
		sf::Sprite m_Sprite;
		sf::Texture m_Texture;
		Vec2 m_vPos;
		bool m_bPosChanged;
		Vec2 m_vSize;
		bool m_bSizeChanged;

	};
}
