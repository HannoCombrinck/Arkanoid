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

namespace sf
{
	class RenderWindow;
}

namespace graphics
{
	class VisualText
	{
	public:
		VisualText();
		~VisualText();

		void init(VisualSystem* pVisualSystem);
		bool alive() const;
		void clean();
		void update(float fDT);

		void setText(const std::string& sString);
		void setPosition(const Vec2& vPos);
		void setSize(const Vec2& vSize);

	private:
		// VisualSystem interface
		// {
		friend class VisualSystem;
		void loadFont(const std::string& sFilename);
		// }

		VisualSystem* m_pVisualSystem;
		bool m_bAlive;
		sf::Text m_Text;
		sf::Font m_Font;

		std::string m_sString;
		Vec2 m_vPos;
		bool m_bPosChanged;
		Vec2 m_vSize;
		bool m_bSizeChanged;

	};
}