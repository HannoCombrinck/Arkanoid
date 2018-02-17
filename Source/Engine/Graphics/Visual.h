#pragma once
#include <memory>

#include <Engine/Core/Math/Math.h>
#include <Engine/Core/GlobalTypes.h>
#include <SFML/Graphics.hpp>

using namespace core;

namespace graphics
{
	class VisualSystem;
}

namespace graphics
{
	class Visual
	{
	public:
		Visual();
		~Visual();

		void init(VisualSystem* pVisualSystem);
		void clean();
		void update(float fDT);

		void setPosition(const Vec2& vPos);
		void setSize(const Vec2& vSize);

	private:
		// VisualSystem interface
		// {
		friend class VisualSystem;
		void loadSprite(const std::string& sFilename);
		// }

		VisualSystem* m_pVisualSystem;
		uint m_uSprite;
		sf::Sprite m_Sprite;
		sf::Texture m_Texture;
		Vec2 m_vPos;
		bool m_bPosChanged;
		Vec2 m_vSize;
		bool m_bSizeChanged;

	};
}