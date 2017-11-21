#pragma once
#include <memory>

#include <Engine/Core/Math/Math.h>
#include <Engine/Core/GlobalTypes.h>

using namespace core;

namespace sf
{
	class RenderWindow;
}

namespace graphics
{
	class Visual
	{
	public:
		Visual();
		~Visual();

	private:
		friend class VisualSystem;
		Vec2 m_vPos;

	};
}