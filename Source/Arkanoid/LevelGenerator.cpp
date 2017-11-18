#include "LevelGenerator.h"

#include <iostream>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/EngineSystems.h>
#include <Engine/SystemsInclude.h>
#include <Engine/Entity/World.h>
#include <Engine/Entity/Entity.h>
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

World* LevelGenerator::generate()
{
	World* pWorld = new World;
	//pWorld->addEntity(createPaddle());
	//pWorld->addEntity(createBricks(20, 5));
	//pWorld->addEntity(createBall(Ball::STUCK_ON_PADDLE));
	
	return nullPtr;
}
