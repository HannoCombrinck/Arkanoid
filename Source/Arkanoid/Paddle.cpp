#include "Paddle.h"

#include <iostream>

#include <Engine/EngineSystems.h>

using namespace std;

Paddle* Paddle::create()
{
	return new Paddle;
}

Paddle::Paddle()
{
}

Paddle::~Paddle()
{
}

void Paddle::onInit(EngineSystems& engine)
{
	// TODO: Create visuals, collision objects, sounds i.e. all the components that make up the Paddle object
}

void Paddle::onUpdate(float fDT)
{
	//engine().input().IsKeyDown(KEY_W);
}
