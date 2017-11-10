#pragma once

#include <Engine\Core\Math\Math.h>

namespace engine
{
	class InputSystem
	{
	public:
		// Input device enums
		// {
		enum KeyboardKey
		{
			KEY_Unknown = -1, // Unhandled key
			KEY_A = 0,        // The A key
			KEY_B,            // The B key
			KEY_C,            // The C key
			KEY_D,            // The D key
			KEY_E,            // The E key
			KEY_F,            // The F key
			KEY_G,            // The G key
			KEY_H,            // The H key
			KEY_I,            // The I key
			KEY_J,            // The J key
			KEY_K,            // The K key
			KEY_L,            // The L key
			KEY_M,            // The M key
			KEY_N,            // The N key
			KEY_O,            // The O key
			KEY_P,            // The P key
			KEY_Q,            // The Q key
			KEY_R,            // The R key
			KEY_S,            // The S key
			KEY_T,            // The T key
			KEY_U,            // The U key
			KEY_V,            // The V key
			KEY_W,            // The W key
			KEY_X,            // The X key
			KEY_Y,            // The Y key
			KEY_Z,            // The Z key
			KEY_Num0,         // The 0 key
			KEY_Num1,         // The 1 key
			KEY_Num2,         // The 2 key
			KEY_Num3,         // The 3 key
			KEY_Num4,         // The 4 key
			KEY_Num5,         // The 5 key
			KEY_Num6,         // The 6 key
			KEY_Num7,         // The 7 key
			KEY_Num8,         // The 8 key
			KEY_Num9,         // The 9 key
			KEY_Escape,       // The Escape key
			KEY_LControl,     // The left Control key
			KEY_LShift,       // The left Shift key
			KEY_LAlt,         // The left Alt key
			KEY_LSystem,      // The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
			KEY_RControl,     // The right Control key
			KEY_RShift,       // The right Shift key
			KEY_RAlt,         // The right Alt key
			KEY_RSystem,      // The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
			KEY_Menu,         // The Menu key
			KEY_LBracket,     // The [ key
			KEY_RBracket,     // The ] key
			KEY_SemiColon,    // The ; key
			KEY_Comma,        // The , key
			KEY_Period,       // The . key
			KEY_Quote,        // The ' key
			KEY_Slash,        // The / key
			KEY_BackSlash,    // The \ key
			KEY_Tilde,        // The ~ key
			KEY_Equal,        // The = key
			KEY_Dash,         // The - key
			KEY_Space,        // The Space key
			KEY_Return,       // The Return key
			KEY_BackSpace,    // The Backspace key
			KEY_Tab,          // The Tabulation key
			KEY_PageUp,       // The Page up key
			KEY_PageDown,     // The Page down key
			KEY_End,          // The End key
			KEY_Home,         // The Home key
			KEY_Insert,       // The Insert key
			KEY_Delete,       // The Delete key
			KEY_Add,          // The + key
			KEY_Subtract,     // The - key
			KEY_Multiply,     // The * key
			KEY_Divide,       // The / key
			KEY_Left,         // Left arrow
			KEY_Right,        // Right arrow
			KEY_Up,           // Up arrow
			KEY_Down,         // Down arrow
			KEY_Numpad0,      // The numpad 0 key
			KEY_Numpad1,      // The numpad 1 key
			KEY_Numpad2,      // The numpad 2 key
			KEY_Numpad3,      // The numpad 3 key
			KEY_Numpad4,      // The numpad 4 key
			KEY_Numpad5,      // The numpad 5 key
			KEY_Numpad6,      // The numpad 6 key
			KEY_Numpad7,      // The numpad 7 key
			KEY_Numpad8,      // The numpad 8 key
			KEY_Numpad9,      // The numpad 9 key
			KEY_F1,           // The F1 key
			KEY_F2,           // The F2 key
			KEY_F3,           // The F3 key
			KEY_F4,           // The F4 key
			KEY_F5,           // The F5 key
			KEY_F6,           // The F6 key
			KEY_F7,           // The F7 key
			KEY_F8,           // The F8 key
			KEY_F9,           // The F9 key
			KEY_F10,          // The F10 key
			KEY_F11,          // The F11 key
			KEY_F12,          // The F12 key
			KEY_F13,          // The F13 key
			KEY_F14,          // The F14 key
			KEY_F15,          // The F15 key
			KEY_Pause,        // The Pause key
			KEY_KeyCount      // Keep last -- the total number of keyboard keys
		};

		enum MouseButton
		{
			MB_Left,       // The left mouse button
			MB_Right,      // The right mouse button
			MB_Middle,     // The middle (wheel) mouse button
			MB_XButton1,   // The first extra mouse button
			MB_XButton2,   // The second extra mouse button
			MB_ButtonCount // Keep last -- the total number of mouse buttons
		};

		enum MouseWheel
		{
			MW_VerticalWheel,  // The vertical mouse wheel
			MW_HorizontalWheel // The horizontal mouse wheel
		};
		// }

		InputSystem();
		~InputSystem();

		// Public interface
		// {
		
		// }

	private:
		// AppBase interface
		// {
		friend class AppBase;
		void update(float fDT);
		void keyPressed(unsigned int uKey);
		void keyReleased(unsigned int uKey);
		void mbPressed(unsigned int uButton);
		void mbReleased(unsigned int uButton);
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