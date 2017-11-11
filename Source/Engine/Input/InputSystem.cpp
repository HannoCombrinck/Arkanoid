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

	void InputSystem::setListener(const boost::shared_ptr<InputListener>& spListener)
	{
		m_spListener = spListener;
	}

	void InputSystem::update(float fDT)
	{

	}

	void InputSystem::keyPressed(KeyboardKey eKey)
	{
		m_KBState[eKey] = true;
		m_spListener->keyPressed(eKey);
	}

	void InputSystem::keyReleased(KeyboardKey eKey)
	{
		m_KBState[eKey] = false;
		m_spListener->keyReleased(eKey);
	}

	void InputSystem::charEntered(char ch)
	{
		m_spListener->charEntered(ch);
	}

	void InputSystem::mbPressed(MouseButton eButton)
	{
		m_MBState[eButton] = true;
		m_spListener->mbPressed(eButton);
	}

	void InputSystem::mbReleased(MouseButton eButton)
	{
		m_MBState[eButton] = false;
		m_spListener->mbReleased(eButton);
	}

	void InputSystem::mouseMoved(int iX, int iY)
	{
		m_MousePos.x = iX;
		m_MousePos.y = iY;
		m_spListener->mouseMoved(iX, iY);
	}

}