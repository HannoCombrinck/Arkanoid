#pragma once

#include <memory>
#include <string>
#include <boost/shared_ptr.hpp>

namespace entity
{
	class World;
}

class ArkanoidFactory;

class WorldGenerator
{
public:
	WorldGenerator();
	~WorldGenerator();

	void generate(const boost::shared_ptr<entity::World>& spWorld, ArkanoidFactory& factory);

private:

};
