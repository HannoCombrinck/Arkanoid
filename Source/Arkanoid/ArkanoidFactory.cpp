#include "ArkanoidFactory.h"

#include <Arkanoid/Paddle.h>
#include <Arkanoid/Ball.h>

using namespace std;

ArkanoidFactory::ArkanoidFactory()
{
	registerEntity("Paddle", []() { return std::make_unique<Paddle>(); });
	registerEntity("Ball", []() { return std::make_unique<Ball>(); });
}

ArkanoidFactory::~ArkanoidFactory()
{
}
