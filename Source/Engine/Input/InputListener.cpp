#include "InputListener.h"

#include <iostream>

using namespace std;
using namespace core;

namespace input {

	InputListener::InputListener()
	{
	}

	InputListener::~InputListener()
	{
	}

	void InputListener::keyPressed(KeyboardKey eKey)
	{
		onKeyPressed(eKey);
	}

	void InputListener::keyReleased(KeyboardKey eKey)
	{
		onKeyReleased(eKey);
	}

	void InputListener::charEntered(char ch)
	{
		onCharEntered(ch);
	}

	void InputListener::mbPressed(MouseButton eButton)
	{
		onMBPressed(eButton);
	}

	void InputListener::mbReleased(MouseButton eButton)
	{
		onMBReleased(eButton);
	}

	void InputListener::mouseMoved(int iX, int iY)
	{
		onMouseMoved(iX, iY);
	}

	void InputListener::mouseMovedRel(int iX, int iY)
	{
		onMouseMovedRel(iX, iY);
	}

}