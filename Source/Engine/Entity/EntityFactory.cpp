#include "EntityFactory.h"

#include <iostream>

#include <Engine/Core/GlobalTypes.h>

using namespace std;

namespace entity {

	EntityFactory::EntityFactory()
	{
	}

	EntityFactory::~EntityFactory()
	{
	}

	void EntityFactory::registerEntity(const string sEntity, const function<Entity*()>& func)
	{
		m_FactoryMap[sEntity] = func;
	}

	Entity* EntityFactory::create(const string & sEntity)
	{
		auto it = m_FactoryMap.find(sEntity);
		if (it == m_FactoryMap.end())
		{
			cout << "Entity type: " << sEntity << " unknown\n";
			return nullPtr;
		}

		return nullPtr;
	}

}