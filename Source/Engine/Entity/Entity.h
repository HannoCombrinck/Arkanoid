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

		void update(float fDT);

	protected:
		EngineSystems& engine();

	private:
		virtual void onInit() {}
		virtual void onUpdate(float fDT) {}

		EngineSystems* m_pEngine;
	};
}