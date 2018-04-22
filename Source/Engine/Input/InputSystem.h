#pragma once

#include <vector>

#include <Engine/Math/Math.h>
#include <Engine/Core/ComponentHandler.h>
#include <Engine/Input/InputCodes.h>
#include <Engine/Input/TextBuffer.h>

#include <boost/shared_ptr.hpp>

class EngineSystems;
class AppBase;

namespace input
{
	class InputSystem
	{
	public:
		InputSystem();
		~InputSystem();

		ADD_COMPONENT(InputSystem, TextBuffer)

		bool& isKeyPressed(KeyboardKey eKey) { return m_KBState[eKey]; }
		bool& isMBPressed(MouseButton eButton) { return m_MBState[eButton]; }
		math::Vec2i getMousePos() const { return m_MousePos; }
		math::Vec2i getMousePosRel() const { return m_MousePosRel; }

	private:
		// AppBase interface
		// {
		friend class ::EngineSystems;
		friend class ::AppBase;
		void update(float fDT);
		void keyPressed(KeyboardKey eKey);
		void keyReleased(KeyboardKey eKey);
		void charEntered(char ch);
		void mbPressed(MouseButton eButton);
		void mbReleased(MouseButton eButton);
		void mouseMoved(int iX, int iY);
		void mouseMovedRel(int iX, int iY);
		// }

		// Input state
		// {
		bool m_KBState[KEY_KeyCount];
		bool m_MBState[MB_ButtonCount];
		math::Vec2i m_MousePos;
		math::Vec2i m_MousePosRel;
		// }
	};
}
