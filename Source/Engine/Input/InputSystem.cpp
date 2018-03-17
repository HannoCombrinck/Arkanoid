#include "InputSystem.h"

#include <iostream>
#include <Engine/Core/GlobalTypes.h>

#include <Engine/Input/TextBuffer.h>

using namespace std;
using namespace core;

namespace input {

	InputSystem::InputSystem()
	{
		memset(m_KBState, false, sizeof(bool)*KEY_KeyCount);
		memset(m_MBState, false, sizeof(bool)*MB_ButtonCount);
		m_MousePos = Vec2i(0, 0);

		m_upTextBufferHandler = std::make_unique<text_buffer_handler_type>(this, 10U);
	}

	InputSystem::~InputSystem()
	{
	}

	uint InputSystem::createTextBuffer()
	{
		auto uHandle = m_upTextBufferHandler->create();
		m_upTextBufferHandler->modify(uHandle).init(this);
		return uHandle;
	}

	TextBuffer & InputSystem::modifyTextBuffer(uint uHandle)
	{
		return m_upTextBufferHandler->modify(uHandle);
	}

	void InputSystem::removeTextBuffer(uint uHandle)
	{
		m_upTextBufferHandler->remove(uHandle);
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

	void InputSystem::charEntered(char ch)
	{
		auto& aTextBuffers = m_upTextBufferHandler->getData();
		for (auto i = 0U; i < m_upTextBufferHandler->getSize(); ++i)
			aTextBuffers[i].addChar(ch);
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

	void InputSystem::mouseMovedRel(int iX, int iY)
	{
		if (m_MousePosRel.x == iX && m_MousePosRel.y == iY)
			return;

		m_MousePosRel.x = iX;
		m_MousePosRel.y = iY;
	}

}