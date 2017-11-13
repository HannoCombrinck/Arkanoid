#include "StatePlaying.h"

#include <iostream>

#include <Engine/Entity/World.h>
#include <Engine/Entity/Entity.h>
#include <Arkanoid/Arkanoid.h>

using namespace std;
using namespace entity;

StatePlaying::StatePlaying(Arkanoid * pArkanoid)
	: ArkanoidState(pArkanoid)
	, m_bForward(false)
	, m_bBackward(false)
	, m_bLeft(false)
	, m_bRight(false)
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
		case KEY_W:
			m_bForward = true;
			break;
		case KEY_S:
			m_bBackward = true;
			break;
		case KEY_A:
			m_bLeft = true;
			break;
		case KEY_D:
			m_bRight = true;
			break;
		case KEY_Num1:
			getApp()->stopGame(); 
			return;  
			break;
	}
}

void StatePlaying::onKeyReleased(KeyboardKey eKey)
{
	switch (eKey)
	{
		case KEY_W:
			m_bForward = false;
			break;
		case KEY_S:
			m_bBackward = false;
			break;
		case KEY_A:
			m_bLeft = false;
			break;
		case KEY_D:
			m_bRight = false;
			break;
	}
}

void StatePlaying::onCharEntered(char ch)
{
	cout << ch;
}
