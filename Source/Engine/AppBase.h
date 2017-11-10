#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace engine
{
	class InputSystem;

	class AppBase
	{
	public:
		AppBase();
		virtual ~AppBase();

	protected:
		// Derived application
		// {
		void closeApplication();
		// }

	private:
		// Application events (to be overridden by derived applications)
		// {
		virtual void onUpdate(float fDT) {}
		// }


		// Application internals
		// {
		void mainLoop();
		void update();
		void render();
		void handleEvents();
		void checkTime();

		sf::RenderWindow m_Window;
		sf::Clock m_Clock;

		// Application state
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;

		// Move to application config
		bool m_bFullscreen;
		bool m_bVSync;
		// }


		// Application systems - dependent on Application internals
		// {
		std::unique_ptr<InputSystem> m_upInputSystem;
		// }


		// TEMP
		sf::Font m_Font;
		sf::Text m_Text;
		sf::Sound m_BeepSound;
		sf::SoundBuffer m_BeepSoundBuffer;
		sf::Music m_Music;
	};
}