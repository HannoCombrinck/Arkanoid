#pragma once
#include <memory>

class EngineSystems;

namespace entity
{
	class EntitySystem;
}
namespace graphics
{
	class VisualSystem;
}
namespace input
{
	class InputSystem;
}
namespace sound
{
	class SoundSystem;
}

namespace entity
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

	protected:
		entity::EntitySystem& es();
		graphics::VisualSystem& vs();
		input::InputSystem& is();
		sound::SoundSystem& ss();

	private:
		// World interface
		// {
		friend class World;
		void init(EngineSystems& rEngine);
		// TODO: Add several entitysystem updates (prePhysics, postPhysics, preVisuals, postVisuals etc.)
		void update(float fDT);
		// }

		// Entity events (to be overridden by derived entities)
		// {
		virtual void onInit() {}
		// TODO: Add several entitysystem onUpdates (onPrePhysics, onPostPhysics, onPreVisuals, onPostVisuals etc.)
		virtual void onUpdate(float fDT) {}
		// }

		EngineSystems* m_pEngine;
	};
}
