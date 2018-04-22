#pragma once

#include <vector>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Math/Math.h>
#include <Engine/Entity/Entity.h>

using namespace math;
using namespace entity;

class Ball : public Entity
{
public:
	Ball();
	virtual ~Ball();

private:
	virtual void onInit() override;
	virtual void onUpdate(float fDT) override;

	void updateState();
	void applyState();

	Vec2 m_vPos;
	
	uint m_uVisual;
	uint m_uSound;
};
