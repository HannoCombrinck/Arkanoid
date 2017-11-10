#include "InputSystem.h"

#include <iostream>

#include <SFML\Window.hpp>

using namespace std;
using namespace core;

namespace input {

	InputSystem::InputSystem()
	{
		memset(m_KBState, false, sizeof(bool)*KEY_KeyCount);
		memset(m_MBState, false, sizeof(bool)*MB_ButtonCount);
		m_MousePos = Vec2i(0, 0);
	}

	InputSystem::~InputSystem()
	{
	}

	void InputSystem::update(float fDT)
	{

	}

	void InputSystem::keyPressed(unsigned int uKey)
	{
		m_KBState[uKey] = true;
	}

	void InputSystem::keyReleased(unsigned int uKey)
	{
		m_KBState[uKey] = false;
	}

	void InputSystem::mbPressed(unsigned int uButton)
	{
		m_MBState[uButton] = true;
	}

	void InputSystem::mbReleased(unsigned int uButton)
	{
		m_MBState[uButton] = false;
	}

	void InputSystem::mouseMoved(int iX, int iY)
	{
		m_MousePos.x = iX;
		m_MousePos.y = iY;
	}

}