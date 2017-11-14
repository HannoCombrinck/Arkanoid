#pragma once

#include <Engine/Entity/Entity.h>

using namespace entity;

class Paddle : public Entity
{
public:
	Paddle();
	virtual ~Paddle();

private:
	virtual void onInit(EngineSystems& engine) override;
	virtual void onUpdate(float fDT) override;


	bool m_bLeft;
	bool m_bRight;
	bool m_bAction;
	
};
