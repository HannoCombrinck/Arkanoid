#pragma once
#include <memory>
#include <vector>
#include <Engine/Core/Math/Math.h>

using namespace std;

namespace entity
{
	class Entity;

	class World
	{
	public:
		World();
		~World();

		static World* load(const string& sFilename);

		void update(float fDT);

	private:
		vector<shared_ptr<Entity>> m_aspEntities;

	};
}