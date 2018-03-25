#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <Engine/Core/Math/Math.h>
#include <Engine/Core/GlobalTypes.h>
#include <boost/shared_ptr.hpp>

namespace sf
{
	class Sound;
	class SoundBuffer;
	class Music;
}
namespace sound
{
	class Sound;
}

class EngineSystems;

namespace sound
{
	class SoundSystem
	{
	public:
		SoundSystem();
		~SoundSystem();

		uint createSound(const std::string& sFilename);
		Sound& modifySound(uint uSound);
		void removeSound(uint uSound);

	private:
		// EngineSystems interface
		// {
		friend class ::EngineSystems;
		void update(float fDT);
		// }

		// SoundSystem internals
		// {
		std::vector<std::unique_ptr<Sound>> m_aupSounds;

		core::Vec3 m_vListenerPosition;
		core::Vec3 m_vListenerDirection;
		float m_fGlobalVolume;
		// }


		std::unordered_map<std::string, uint> m_SoundPlayerMap;
		std::unordered_map<std::string, uint> m_SoundBufferMap;

		std::vector<std::unique_ptr<sf::Sound>> m_aSoundPlayers;
		std::vector<std::unique_ptr<sf::SoundBuffer>> m_aSoundBuffers;

		// TEMP
		std::unique_ptr<sf::Sound> m_BeepSound;
		std::unique_ptr<sf::SoundBuffer> m_BeepSoundBuffer;
		std::unique_ptr<sf::Music> m_Music;
	};
}
