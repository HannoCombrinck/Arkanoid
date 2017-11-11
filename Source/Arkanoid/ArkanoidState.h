#pragma once

#include <memory>

#include <Engine/AppBase.h>
#include <Engine/Input/InputListener.h>

using namespace input;

class Arkanoid;

class ArkanoidState : public InputListener
{
public:
	ArkanoidState(Arkanoid* pArkanoid);
	virtual ~ArkanoidState();

	void update(float fDT) { onUpdate(fDT); }

protected:
	Arkanoid* getApp() const { return m_pArkanoid; }

private:
	virtual void onUpdate(float fDT) {}
	Arkanoid* m_pArkanoid;
};
