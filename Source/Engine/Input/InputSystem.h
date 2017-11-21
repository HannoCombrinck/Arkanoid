#pragma once

#include <vector>

#include <Engine/Core/Math/Math.h>
#include <Engine/Input/InputListener.h>

#include <boost/shared_ptr.hpp>

namespace input
{
	class InputSystem
	{
	public:
		InputSystem();
		~InputSystem();

		// Public interface
		// {
		bool& isKeyPressed(KeyboardKey eKey) { return m_KBState[eKey]; }
		bool& isMBPressed(MouseButton eButton) { return m_MBState[eButton]; }
		core::Vec2i getMousePos() const { return m_MousePos; }
		core::Vec2i getMousePosRel() const { return m_MousePosRel; }

		void setListener(const boost::shared_ptr<InputListener>& spListener);
		// }

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		friend class AppBase;
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
		core::Vec2i m_MousePos;
		core::Vec2i m_MousePosRel;
		// }

		// InputSystem internals
		// {
		boost::shared_ptr<InputListener> m_spListener;
		boost::shared_ptr<InputListener> m_spNewListener;
		// }

	};
}