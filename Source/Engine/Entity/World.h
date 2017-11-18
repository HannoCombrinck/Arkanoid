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
		void addEntity(Entity* pEntity);
		void update(float fDT);

	private:
		vector<boost::shared_ptr<Entity>> m_aspEntities;

	};
}