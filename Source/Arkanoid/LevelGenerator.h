#pragma once

#include <memory>
#include <string>
#include <boost/shared_ptr.hpp>

namespace entity
{
	class World;
}

class LevelGenerator
{
public:
	LevelGenerator();
	~LevelGenerator();

	entity::World* generate();

private:

};
