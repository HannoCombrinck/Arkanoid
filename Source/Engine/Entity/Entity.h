#pragma once
#include <memory>

class EngineSystems;

namespace entity
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void init(EngineSystems& rEngine);

		// TODO: Add several entitysystem updates (prePhysics, postPhysics, preVisuals, postVisuals etc.)
		void update(float fDT);

	protected:
		EngineSystems& engine();

	private:
		virtual void onInit() {}
		// TODO: Add several entitysystem onUpdates (onPrePhysics, onPostPhysics, onPreVisuals, onPostVisuals etc.)
		virtual void onUpdate(float fDT) {}

		EngineSystems* m_pEngine;
	};
}