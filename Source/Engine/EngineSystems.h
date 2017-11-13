#pragma once

#include <memory>

namespace sf
{
	class RenderWindow;
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

class EngineSystems
{
public:
	EngineSystems(sf::RenderWindow* pWindow);
	~EngineSystems();

	void update(float fDT);

	input::InputSystem* inputs();
	graphics::VisualSystem* visuals();
	sound::SoundSystem* sounds();

private:
	std::unique_ptr<input::InputSystem> m_upInputSystem;
	std::unique_ptr<graphics::VisualSystem> m_upVisualSystem;
	std::unique_ptr<sound::SoundSystem> m_upSoundSystem;

};
