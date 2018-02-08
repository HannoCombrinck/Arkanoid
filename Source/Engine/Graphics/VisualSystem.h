#pragma once
#include <memory>
#include <vector>

#include <Engine/Core/GlobalTypes.h>

namespace sf
{
	class RenderWindow;
	class Sprite;
}
namespace graphics
{
	class Visual;
}

namespace graphics
{
	class VisualSystem
	{
	public:
		VisualSystem(sf::RenderWindow *pWindow);
		~VisualSystem();

		uint createVisual();
		Visual& modifyVisual(uint uVisual);
		void removeVisual(uint uVisual);

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

		// Visual interface
		// {
		friend class Visual;
		uint createSprite(const std::string& sTextureFilename);
		void removeSprite(uint uHandle);
		sf::Sprite& modifySprite(uint uHandle);
		// }

		// VisualSystem internals
		// {
		std::vector<boost::shared_ptr<Visual>> m_aspVisuals;
		bool m_bVSync;
		bool m_bFullscreen;
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;
		// }

		struct SFMLMembers;
		SFMLMembers* m_pSFML;
	};
}