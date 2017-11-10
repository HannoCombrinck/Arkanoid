#pragma once

#include <memory>

namespace sf
{
	class RenderWindow;
	class Clock;
}
namespace input
{
	class InputSystem;
}
namespace graphics
{
	class VisualSystem;
}
namespace sound
{
	class SoundSystem;
}

class AppBase
{
public:
	AppBase();
	virtual ~AppBase();

	// Public interface
	// {
	void start();
	// }

protected:
	// Derived application
	// {
	void closeApplication();
	input::InputSystem* InputSys() { return m_upInputSystem.get(); }
	graphics::VisualSystem* VisualSys() { return m_upVisualSystem.get(); }
	sound::SoundSystem* SoundSys() { return m_upSoundSystem.get(); }
	// }

private:
	// Application events (to be overridden by derived applications)
	// {
	virtual void onUpdate(float fDT) {}
	virtual void onInit() {}
	// }

	// Application internals
	// {
	void update();
	void render();
	void handleEvents();
	void checkTime();

	std::unique_ptr<sf::RenderWindow> m_upWindow;
	std::unique_ptr<sf::Clock> m_upClock;
	float m_fDeltaTime;

	// Move to application config
	bool m_bFullscreen;
	bool m_bVSync;
	// }

	// Application systems - dependent on Application internals
	// {
	std::unique_ptr<input::InputSystem> m_upInputSystem;
	std::unique_ptr<graphics::VisualSystem> m_upVisualSystem;
	std::unique_ptr<sound::SoundSystem> m_upSoundSystem;
	// }
};
