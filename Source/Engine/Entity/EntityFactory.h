#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

namespace entity
{
	class Entity;
}

//class PoolInterface;

namespace entity
{
	class EntityFactory
	{
	public:
		EntityFactory();
		virtual ~EntityFactory();

		void registerEntity(const string sEntity, const function<Entity*()>& func);
		Entity* create(const string& sEntity);

	private:
		unordered_map<string, function<Entity*()>> m_FactoryMap;

		//unordered_map<string, PoolInterface> m_PoolMap;
	};
}