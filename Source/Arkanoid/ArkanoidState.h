#pragma once

#include <memory>

#include <Engine/AppBase.h>
#include <Engine/Input/InputListener.h>

namespace entity
{
	class World;
}

using namespace std;
using namespace input;

class Arkanoid;

class ArkanoidState : public InputListener
{
public:
	ArkanoidState(Arkanoid* pArkanoid);
	virtual ~ArkanoidState();

	void update(float fDT) { onUpdate(fDT); }

	void setWorld(entity::World* pWorld);
	entity::World* getWorld();

protected:
	Arkanoid* getApp() const { return m_pArkanoid; }

private:
	virtual void onUpdate(float fDT) {}
	Arkanoid* m_pArkanoid;

	shared_ptr<entity::World> m_spWorld;
};
