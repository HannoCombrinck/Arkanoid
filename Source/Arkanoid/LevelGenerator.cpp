#include "LevelGenerator.h"

#include <iostream>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/EngineSystems.h>
#include <Engine/SystemsInclude.h>
#include <Engine/Entity/World.h>
#include <Engine/Entity/Entity.h>

#include <Arkanoid/ArkanoidFactory.h>

#include <boost/make_shared.hpp>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;
using namespace entity;

LevelGenerator::LevelGenerator()
{
}

LevelGenerator::~LevelGenerator()
{
}

World* LevelGenerator::generate(ArkanoidFactory& factory)
{
	World* pWorld = new World;
	pWorld->addEntity(factory.create("Paddle"));

	return pWorld;
}
