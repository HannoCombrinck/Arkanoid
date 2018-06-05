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
	class VisualText
	{
	public:
		VisualText();
		~VisualText();

		void init(VisualSystem* pVisualSystem);
		void created();
		bool alive() const;
		void clean();

		void update(float fDT);

		VisualText& loadFont(const std::string& sFilename);
		VisualText& setText(const std::string& sString);
		VisualText& setPosition(const Vec2& vPos);
		VisualText& setSize(const Vec2& vSize);

	private:
		friend class VisualSystem;
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
