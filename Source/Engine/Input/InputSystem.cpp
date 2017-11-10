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

	void InputSystem::keyPressed(KeyboardKey eKey)
	{
		m_KBState[eKey] = true;
	}

	void InputSystem::keyReleased(KeyboardKey eKey)
	{
		m_KBState[eKey] = false;
	}

	void InputSystem::mbPressed(MouseButton eButton)
	{
		m_MBState[eButton] = true;
	}

	void InputSystem::mbReleased(MouseButton eButton)
	{
		m_MBState[eButton] = false;
	}

	void InputSystem::mouseMoved(int iX, int iY)
	{
		m_MousePos.x = iX;
		m_MousePos.y = iY;
	}

}