#include "StatePlaying.h"

#include <iostream>

#include <Engine/Entity/World.h>
#include <Engine/Entity/Entity.h>
#include <Arkanoid/Arkanoid.h>

using namespace std;
using namespace entity;

StatePlaying::StatePlaying(Arkanoid * pArkanoid)
	: ArkanoidState(pArkanoid)
{
}

StatePlaying::~StatePlaying()
{
}

void StatePlaying::onUpdate(float fDT)
{
}

void StatePlaying::onSetWorld(World* pWorld)
{
}

void StatePlaying::onKeyPressed(KeyboardKey eKey)
{
	switch (eKey)
	{
		case KEY_Num1:
			arkanoid().stopGame(); 
			return;  
			break;
	}
}

void StatePlaying::onKeyReleased(KeyboardKey eKey)
{
}

void StatePlaying::onCharEntered(char ch)
{
	//cout << ch;
}
