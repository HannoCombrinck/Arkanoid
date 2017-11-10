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
	class GraphicsSystem
	{
	public:
		GraphicsSystem(sf::RenderWindow *pWindow);
		~GraphicsSystem();

	private:
		// AppBase interface
		// {
		friend class AppBase;
		void update(float fDT);
		void render();
		void resize(int iWidth, int iHeight);
		// }

		// GraphicsSystem internals
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