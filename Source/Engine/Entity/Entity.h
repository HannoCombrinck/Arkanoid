#pragma once
#include <memory>
#include <Engine/Core/Math/Math.h>

class EngineSystems;

namespace entity
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void init(EngineSystems& engine);

		void update(float fDT);

	private:
		virtual void onInit(EngineSystems& engine) {}
		virtual void onUpdate(float fDT) {}

	};
}