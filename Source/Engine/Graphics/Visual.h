#pragma once
#include <memory>

#include <Engine/Core/Math/Math.h>
#include <Engine/Core/GlobalTypes.h>

using namespace core;

namespace graphics
{
	class VisualSystem;
}

namespace graphics
{
	class Visual
	{
	public:
		Visual(VisualSystem* pVisualSystem);
		~Visual();

		void update(float fDT);

		void setPosition(const Vec2& vPos);

	private:
		VisualSystem* m_pVisualSystem;
		uint m_uSprite;
		Vec2 m_vPos;

	};
}