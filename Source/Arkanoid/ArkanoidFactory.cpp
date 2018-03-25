#include "ArkanoidFactory.h"

#include <Arkanoid/Paddle.h>
#include <Arkanoid/Ball.h>

using namespace std;

ArkanoidFactory::ArkanoidFactory()
{
	registerEntity("Paddle", []() { return unique_ptr<Paddle>(new Paddle); });
	registerEntity("Ball", []() { return unique_ptr<Ball>(new Ball); });
}

ArkanoidFactory::~ArkanoidFactory()
{
}
