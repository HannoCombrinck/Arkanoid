#pragma once
#include <memory>

namespace sf
{
	class RenderWindow;
	class Font;
	class Text;
}

namespace engine
{
	class VisualSystem
	{
	public:
		VisualSystem(sf::RenderWindow *pWindow);
		~VisualSystem();

	private:
		// AppBase interface
		// {
		friend class AppBase;
		void update(float fDT);
		void render();
		void resize(int iWidth, int iHeight);
		// }

		// VisualSystem internals
		// {
		sf::RenderWindow *m_pWindow;
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;
		// }

		// TEMP
		std::unique_ptr<sf::Font> m_upFont;
		std::unique_ptr<sf::Text> m_upText;
	};
}