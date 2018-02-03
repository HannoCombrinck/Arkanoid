#pragma once
#include <memory>
#include <vector>

#include <Engine/Core/GlobalTypes.h>

namespace entity
{
	class World;
}

namespace entity
{
	class EntitySystem
	{
	public:
		EntitySystem();
		~EntitySystem();

		void setActiveWorld(const boost::shared_ptr<World>& spWorld);

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		friend class AppBase;
		// TODO: Add several entitysystem updates (prePhysics, postPhysics, preVisuals, postVisuals etc.)
		void update(float fDT);
		// }

		// EntitySystem internals
		// {
		boost::shared_ptr<World> m_spActiveWorld;
		// }
		
	};
}