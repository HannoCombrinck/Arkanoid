#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace engine
{
	class InputSystem;
	class VisualSystem;
	class SoundSystem;

	class AppBase
	{
	public:
		AppBase();
		virtual ~AppBase();

	protected:
		// Derived application
		// {
		void closeApplication();
		InputSystem* InputSys() { return m_upInputSystem.get(); }
		VisualSystem* VisualSys() { return m_upVisualSystem.get(); }
		SoundSystem* SoundSys() { return m_upSoundSystem.get(); }
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
		float m_fDeltaTime;

		// Move to application config
		bool m_bFullscreen;
		bool m_bVSync;
		// }

		// Application systems - dependent on Application internals
		// {
		std::unique_ptr<InputSystem> m_upInputSystem;
		std::unique_ptr<VisualSystem> m_upVisualSystem;
		std::unique_ptr<SoundSystem> m_upSoundSystem;
		// }
	};
}