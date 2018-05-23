#pragma once

#include <memory>
#include <Engine/Input/InputCodes.h>
#include <Engine/Math/Math.h>

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
	void toggleFullscreen();
	void toggleMouseLock();
	void toggleVSync();
	EngineSystems& engine();
	// }

private:
	// Application events (to be overridden by derived applications)
	// {
	virtual void onUpdate(float fDT) {}
	virtual void onInit() {}
	virtual void onKeyPressed(input::KeyboardKey eKey) {}
	virtual void onKeyReleased(input::KeyboardKey eKey) {}
	virtual void onCharEntered(char ch) {}
	virtual void onMBPressed(input::MouseButton eButton) {}
	virtual void onMBReleased(input::MouseButton eButton) {}
	virtual void onMouseMoved(int iX, int iY) {}
	virtual void onMouseMovedRel(int iX, int iY) {}
	// }

	// Application internals
	// {
	void update();
	void render();
	void handleEvents();
	void handleMouseInput();
	// }

	std::unique_ptr<sf::RenderWindow> m_upWindow;
	std::unique_ptr<sf::Clock> m_upClock;
	std::unique_ptr<EngineSystems> m_upEngineSystems;
	math::Vec2i m_vMousePos;
	bool m_bMouseLock;
};
