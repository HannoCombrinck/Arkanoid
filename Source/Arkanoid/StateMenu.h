#pragma once

#include <memory>

#include <Arkanoid/ArkanoidState.h>

class StateMenu : public ArkanoidState
{
public:
	StateMenu(Arkanoid* pArkanoid);
	virtual ~StateMenu();

private:
	// AkranoidState overrides
	// {
	virtual void onUpdate(float fDT);
	// }

	// InputListener overrides
	// {
	virtual void onKeyPressed(KeyboardKey eKey) override;
	virtual void onKeyReleased(KeyboardKey eKey) override {}
	virtual void onMBPressed(MouseButton eButton) override {}
	virtual void onMBReleased(MouseButton eButton) override {}
	virtual void onMouseMoved(int iX, int iY) override {}
	// }
};
