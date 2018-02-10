#include "ArkanoidFactory.h"

#include <Arkanoid/Paddle.h>

using namespace std;

ArkanoidFactory::ArkanoidFactory()
{
	registerEntity("Paddle", []() { return std::make_unique<Paddle>(); });
	registerEntity("PaddleStatic", Paddle::create);
}

ArkanoidFactory::~ArkanoidFactory()
{
}
