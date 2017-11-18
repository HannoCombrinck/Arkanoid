#pragma once

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Core/Math/Math.h>
#include <Engine/Entity/Entity.h>

using namespace core;
using namespace entity;

class Paddle : public Entity
{
public:
	static Paddle* create();

	Paddle();
	virtual ~Paddle();

private:
	virtual void onInit() override;
	virtual void onUpdate(float fDT) override;

	Vec2 m_vPos;
	bool m_bLeft;
	bool m_bRight;
	bool m_bAction;
	
	uint m_uVisual;
};
