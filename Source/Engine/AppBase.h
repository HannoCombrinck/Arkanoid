#pragma once

#include <memory>

namespace sf
{
	class RenderWindow;
	class Clock;
}
class EngineSystems;

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
	EngineSystems* engine();
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

	// Engine systems
	std::unique_ptr<EngineSystems> m_upEngineSystems;
};
