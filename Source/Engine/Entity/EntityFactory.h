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

		std::unique_ptr<Entity> create(const string& sEntity);

	protected:
		void registerEntity(const string sEntity, const function<std::unique_ptr<Entity>()>& func);

	private:
		unordered_map<string, function<std::unique_ptr<Entity>()>> m_FactoryMap;

		//unordered_map<string, PoolInterface> m_PoolMap;
	};
}