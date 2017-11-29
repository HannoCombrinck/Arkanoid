#pragma once

#include <memory>
#include <Engine/SystemsInclude_fwd.h>

class EngineSystems
{
public:
	EngineSystems(sf::RenderWindow* pWindow);
	~EngineSystems();

	void update(float fDT);

	input::InputSystem& inputs();
	entity::EntitySystem& entities();
	graphics::VisualSystem& visuals();
	sound::SoundSystem& sounds();

private:
	std::unique_ptr<input::InputSystem> m_upInputSystem;
	std::unique_ptr<entity::EntitySystem> m_upEntitySystem;
	std::unique_ptr<graphics::VisualSystem> m_upVisualSystem;
	std::unique_ptr<sound::SoundSystem> m_upSoundSystem;

};
