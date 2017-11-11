#pragma once

#include <Arkanoid/ArkanoidState.h>

class StatePlaying : public ArkanoidState
{
public:
	StatePlaying(Arkanoid* pArkanoid);
	virtual ~StatePlaying();

private:
	// AkranoidState overrides
	// {
	virtual void onUpdate(float fDT);
	// }

	// InputListener overrides
	// {
	virtual void onKeyPressed(KeyboardKey eKey) override;
	virtual void onKeyReleased(KeyboardKey eKey) override;
	virtual void onCharEntered(char ch) override;
	virtual void onMBPressed(MouseButton eButton) override {}
	virtual void onMBReleased(MouseButton eButton) override {}
	virtual void onMouseMoved(int iX, int iY) override {}
	// }

	bool m_bForward;
	bool m_bBackward;
	bool m_bLeft;
	bool m_bRight;
};
