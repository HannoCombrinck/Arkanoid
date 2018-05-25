#pragma once

#include <memory>
#include <Engine/SystemsInclude_fwd.h>

class EngineSystems
{
public:
	EngineSystems(sf::RenderWindow* pWindow);
	~EngineSystems();

	void update(float fDT);

	input::InputSystem& is();
	graphics::VisualSystem& vs();
	sound::SoundSystem& ss();
	entity::EntitySystem& es();

private:
	std::unique_ptr<input::InputSystem> m_upInputSystem;
	std::unique_ptr<graphics::VisualSystem> m_upVisualSystem;
	std::unique_ptr<sound::SoundSystem> m_upSoundSystem;
	std::unique_ptr<entity::EntitySystem> m_upEntitySystem;

};
