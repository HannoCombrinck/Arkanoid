#pragma once
#include <memory>
#include <vector>
#include <Engine/Core/Math/Math.h>
#include <boost/shared_ptr.hpp>

using namespace std;

class EngineSystems;

namespace entity
{
	class Entity;

	class World
	{
	public:
		World();
		virtual ~World();

		static World* load(const string& sFilename);

		void init(EngineSystems& rEngine);
		void addEntity(const boost::shared_ptr<Entity> spEntity);
		// TODO: Add several entitysystem updates (prePhysics, postPhysics, preVisuals, postVisuals etc.)
		void update(float fDT);

	private:
		// TODO: Add several onUpdate* overrides for updating before and after physics/sound/input etc.
		vector<boost::shared_ptr<Entity>> m_aspEntities;

	};
}