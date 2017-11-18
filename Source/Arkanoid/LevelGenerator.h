#pragma once

#include <memory>
#include <string>
#include <boost/shared_ptr.hpp>

namespace entity
{
	class World;
}

class ArkanoidFactory;

class LevelGenerator
{
public:
	LevelGenerator();
	~LevelGenerator();

	entity::World* generate(ArkanoidFactory& factory);

private:

};
