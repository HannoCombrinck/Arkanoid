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

		Entity* create(const string& sEntity);

	protected:
		void registerEntity(const string sEntity, const function<Entity*()>& func);

	private:
		unordered_map<string, function<Entity*()>> m_FactoryMap;

		//unordered_map<string, PoolInterface> m_PoolMap;
	};
}