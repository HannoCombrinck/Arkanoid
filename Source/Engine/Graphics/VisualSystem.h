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

		uint createVisual(const std::string& sFilename);
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
		std::vector<std::unique_ptr<Visual>> m_aupVisuals;
		bool m_bVSync;
		bool m_bFullscreen;
		float m_fDeltaTime;
		float m_fDeltaTimeSmoothed;
		// }

		struct SFMLMembers;
		SFMLMembers* m_pSFML;
	};
}

/*
template<typename T, int SIZE>
class ResourceManager
{
T data[SIZE];
int indices[SIZE];
int back;

ResourceManager() : back(0)
{
for(int i=0; i<SIZE; i++)
indices[i] = i;
}

int Reserve()
{ return indices[back++]; }

void Release(int handle)
{
for(int i=0; i<back; i++)
{
if(indices[i] == handle)
{
back--;
std::swap(indices[i], indices[back]);
return;
}
}
}

T GetData(int handle)
{ return data[handle]; }
};
*/