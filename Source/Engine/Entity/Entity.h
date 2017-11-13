#pragma once
#include <memory>
#include <Engine/Core/Math/Math.h>

namespace entity
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void update(float fDT);

	private:
		virtual void onUpdate(float fDT) {}

	};
}