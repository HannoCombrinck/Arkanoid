#include "ArkanoidFactory.h"

#include <iostream>

#include <Arkanoid/Paddle.h>

using namespace std;

ArkanoidFactory::ArkanoidFactory()
{
	registerEntity("Paddle", []() { return new Paddle; });
	registerEntity("PaddleStatic", Paddle::create);
}

ArkanoidFactory::~ArkanoidFactory()
{
}
