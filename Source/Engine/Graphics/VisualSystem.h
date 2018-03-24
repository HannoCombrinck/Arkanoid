#pragma once
#include <memory>
#include <vector>

#include <Engine/Core/ComponentHandler.h>
#include <Engine/Core/GlobalTypes.h>
#include <Engine/Graphics/Visual.h>

namespace sf
{
	class RenderWindow;
	class Sprite;
}
namespace graphics
{
	class VisualText;
}

namespace graphics
{
	class VisualSystem
	{
	public:
		VisualSystem(sf::RenderWindow *pWindow);
		~VisualSystem();

		ADD_COMPONENT(Visual)
		/*uint createVisual(const std::string& sFilename);
		Visual& modifyVisual(uint uHandle);
		void removeVisual(uint uHandle);*/

		uint createVisualText(const std::string& sText);
		VisualText& modifyVisualText(uint uHandle);
		void removeVisualText(uint uHandle);

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		friend class AppBase;
		void update(float fDT);
		void render();
		void resize(int iWidth, int iHeight);
		void toggleFullscreen();
		void toggleVSync();
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
		//std::vector<std::unique_ptr<Visual>> m_aupVisuals;
		bool m_bVSync;
		bool m_bFullscreen;
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;
		// }

		// TEMP handle functionality test
		// {
		/*typedef ComponentHandler<Visual, VisualSystem> visual_handler_type;
		std::unique_ptr<visual_handler_type> m_upVisualHandler;*/

		typedef ComponentHandler<VisualText, VisualSystem> visual_text_handler_type;
		std::unique_ptr<visual_text_handler_type> m_upVisualTextHandler;
		// }

		struct SFMLMembers;
		SFMLMembers* m_pSFML;
	};
}
