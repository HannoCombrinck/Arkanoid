#include "WorldGenerator.h"

#include <iostream>

#include <Engine/Engine.h>
#include <Engine/Entity/World.h>
#include <Engine/Entity/Entity.h>

#include <Arkanoid/ArkanoidFactory.h>

#include <boost/make_shared.hpp>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;
using namespace entity;

WorldGenerator::WorldGenerator()
{
}

WorldGenerator::~WorldGenerator()
{
}

void WorldGenerator::generate(const boost::shared_ptr<World>& spWorld, ArkanoidFactory& factory)
{
	spWorld->addEntity(boost::shared_ptr<Entity>(factory.create("Paddle")));
}
