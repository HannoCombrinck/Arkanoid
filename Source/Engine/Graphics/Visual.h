#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Math/Math.h>
#include <SFML/Graphics.hpp>

using namespace math;

namespace graphics
{
	class Visual
	{
	public:
		Visual();
		~Visual();

		void init();
		void destroy();
		bool isAlive() const;

		void update(float fDT);
		Visual& loadSprite(const std::string& sFilename);
		Visual& setPosition(const Vec2& vPos);
		Visual& setSize(const Vec2& vSize);

	private:
		friend class VisualSystem;
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
