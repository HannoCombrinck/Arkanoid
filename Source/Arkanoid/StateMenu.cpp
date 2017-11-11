#include "StateMenu.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>
#include <Arkanoid/Arkanoid.h>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;

StateMenu::StateMenu(Arkanoid * pArkanoid)
	: ArkanoidState(pArkanoid)
{
}

StateMenu::~StateMenu() 
{
}

void StateMenu::onUpdate(float fDT)
{

}

void StateMenu::onKeyPressed(KeyboardKey eKey)
{
	switch (eKey)
	{
		case KEY_N: 
			getApp()->startNewGame(); 
			return;
			break;
	}
	cout << "Menu state key pressed: " << eKey << endl;
}
