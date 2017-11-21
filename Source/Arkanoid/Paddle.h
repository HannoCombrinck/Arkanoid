#pragma once

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Core/Math/Math.h>
#include <Engine/Entity/Entity.h>

namespace graphics
{
	class Visual;
}

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
	
	boost::shared_ptr<graphics::Visual> m_spVisual;
};
