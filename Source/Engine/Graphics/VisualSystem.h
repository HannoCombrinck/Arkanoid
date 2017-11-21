#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>

namespace sf
{
	class RenderWindow;
}

namespace graphics
{
	class VisualSystem
	{
	public:
		VisualSystem(sf::RenderWindow *pWindow);
		~VisualSystem();

		uint createVisual();

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		friend class AppBase;
		void update(float fDT);
		void render();
		void resize(int iWidth, int iHeight);
		void toggleFullscreen();
		// }

		// VisualSystem internals
		// {
		bool m_bVSync;
		bool m_bFullscreen;
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;
		// }

		struct SFMLMembers;
		SFMLMembers* m_pSFML;
	};
}