#include "StatePlaying.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>
#include <Arkanoid/Arkanoid.h>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;

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

void StatePlaying::onKeyPressed(KeyboardKey eKey)
{
	switch (eKey)
	{
		case KEY_M: 
			getApp()->stopGame(); 
			return;  
			break;
	}
	cout << "Playing state key pressed: " << eKey << endl;
}
