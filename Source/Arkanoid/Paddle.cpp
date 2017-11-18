#include "Paddle.h"

#include <iostream>

#include <Engine/EngineSystems.h>
#include <Engine/SystemsInclude.h>

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

void Paddle::onInit()
{
	// TODO: Create visuals, collision objects, sounds i.e. all the components that make up the Paddle object
	m_uVisual = engine().visuals().createVisual();
}

void Paddle::onUpdate(float fDT)
{
	//engine().inputs().IsKeyDown(KEY_W);
	//engine().visuals().
}
