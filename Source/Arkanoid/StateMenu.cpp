#include "StateMenu.h"

#include <iostream>

#include <Arkanoid/Arkanoid.h>

using namespace std;

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
