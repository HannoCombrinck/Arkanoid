#include <iostream>
#include <Engine/Core/Math/MathHelpers.h>
#include <Engine/AppBase.h>
#include <Engine/Input/InputSystem.h>
#include <Arkanoid/Arkanoid.h>

using namespace std;

int main(int argc, char** argv)
{
	Arkanoid arkanoid;
	arkanoid.start();

	return 0;
}

