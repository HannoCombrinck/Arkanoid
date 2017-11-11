#include "StatePlaying.h"

#include <iostream>

#include <Arkanoid/Arkanoid.h>

using namespace std;

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
}

void StatePlaying::onCharEntered(char ch)
{
	cout << ch;
}
