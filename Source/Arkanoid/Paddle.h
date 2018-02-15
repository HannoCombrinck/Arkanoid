#pragma once

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Core/Math/Math.h>
#include <Engine/Entity/Entity.h>

using namespace core;
using namespace entity;

class Paddle : public Entity
{
public:
	Paddle();
	virtual ~Paddle();

private:
	// Entity callbacks
	// {
	virtual void onInit() override;
	virtual void onUpdate(float fDT) override;
	// }

	// Paddle internals
	// {
	void getInputs();
	void updateState();
	void applyState();
	// }

	Vec2 m_vPos;
	bool m_bLeft;
	bool m_bRight;
	bool m_bUp;
	bool m_bDown;
	bool m_bAction;
	
	uint m_uVisual;
	uint m_uSound;
};
