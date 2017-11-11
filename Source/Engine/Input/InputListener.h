#pragma once

#include <Engine\Core\Math\Math.h>
#include <Engine\Input\InputCodes.h>

namespace input
{
	class InputListener
	{
	public:
		InputListener();
		virtual ~InputListener();

	private:
		// InputSystem interface
		// {
		friend class InputSystem;
		void keyPressed(KeyboardKey eKey);
		void keyReleased(KeyboardKey eKey);
		void charEntered(char ch);
		void mbPressed(MouseButton eButton);
		void mbReleased(MouseButton eButton);
		void mouseMoved(int iX, int iY);
		// }

		// Derived listener overrides
		// {
		virtual void onKeyPressed(KeyboardKey eKey) {}
		virtual void onKeyReleased(KeyboardKey eKey) {}
		virtual void onCharEntered(char ch) {}
		virtual void onMBPressed(MouseButton eButton) {}
		virtual void onMBReleased(MouseButton eButton) {}
		virtual void onMouseMoved(int iX, int iY) {}
		// }
	};
}