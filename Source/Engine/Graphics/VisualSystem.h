#pragma once
#include <memory>
#include <vector>

#include <Engine/Core/ComponentHandler.h>
#include <Engine/Core/GlobalTypes.h>
#include <Engine/Graphics/Visual.h>
#include <Engine/Graphics/VisualText.h>

namespace sf
{
	class RenderWindow;
	class Sprite;
}

class EngineSystems;
class AppBase;

namespace graphics
{
	class VisualSystem
	{
	public:
		VisualSystem(sf::RenderWindow *pWindow);
		~VisualSystem();

		ADD_COMPONENT(Visual)
		ADD_COMPONENT(VisualText)

	private:
		// EngineSystems interface
		// {
		friend class ::EngineSystems;
		friend class ::AppBase;
		void update(float fDT);
		void render();
		void resize(int iWidth, int iHeight);
		void toggleFullscreen();
		void toggleVSync();
		// }

		// VisualSystem internals
		// {
		//std::vector<std::unique_ptr<Visual>> m_aupVisuals;
		bool m_bVSync;
		bool m_bFullscreen;
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;
		// }

		struct SFMLMembers;
		SFMLMembers* m_pSFML;
	};
}
