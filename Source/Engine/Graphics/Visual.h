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

		void setPosition(const Vec2& vPos);
		void setSize(const Vec2& vSize);

	private:
		// VisualSystem interface
		// {
		friend class VisualSystem;
		void update(float fDT);
		// }

		VisualSystem* m_pVisualSystem;
		uint m_uSprite;
		Vec2 m_vPos;
		bool m_bPosChanged;
		Vec2 m_vSize;
		bool m_bSizeChanged;

	};
}