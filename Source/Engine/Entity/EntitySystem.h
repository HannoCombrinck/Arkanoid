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

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		friend class AppBase;
		void update(float fDT);
		// }

		// EntitySystem internals
		// {
		std::vector<boost::shared_ptr<World>> m_aspWorlds;
		// }
		
	};
}