#pragma once

#include <memory>
#include <vector>
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

namespace sound
{
	class SoundSystem
	{
	public:
		SoundSystem();
		~SoundSystem();

		uint createSound();
		Sound& modifySound(uint uSound);
		void removeSound(uint uSound);

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		void update(float fDT);
		// }

		// SoundSystem internals
		// {
		std::vector<boost::shared_ptr<Sound>> m_aspSounds;

		core::Vec3 m_vListenerPosition;
		core::Vec3 m_vListenerDirection;
		float m_fGlobalVolume; 
		// }

		// TEMP
		std::unique_ptr<sf::Sound> m_BeepSound;
		std::unique_ptr<sf::SoundBuffer> m_BeepSoundBuffer;
		std::unique_ptr<sf::Music> m_Music;
	};
}