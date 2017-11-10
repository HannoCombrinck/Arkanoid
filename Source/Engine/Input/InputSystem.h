#pragma once

#include <Engine\Core\Math\Math.h>
#include <Engine\Input\InputCodes.h>

namespace input
{
	class InputSystem
	{
	public:
		InputSystem();
		~InputSystem();

		// Public interface
		// {
		bool getKeyState(KeyboardKey eKey) const { return m_KBState[eKey]; }
		bool getMBState(MouseButton eButton) const { return m_MBState[eButton]; }
		core::Vec2i getMousePos() const { return m_MousePos; }
		// }

	private:
		// AppBase interface
		// {
		friend class AppBase;
		void update(float fDT);
		void keyPressed(KeyboardKey eKey);
		void keyReleased(KeyboardKey eKey);
		void mbPressed(MouseButton eButton);
		void mbReleased(MouseButton eButton);
		void mouseMoved(int iX, int iY);
		// }

		// Input state
		// {
		bool m_KBState[KEY_KeyCount];
		bool m_MBState[MB_ButtonCount];
		core::Vec2i m_MousePos;
		// }

	};
}