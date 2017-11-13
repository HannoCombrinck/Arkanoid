#pragma once
#include <memory>
#include <Engine/Core/Math/Math.h>

namespace sf
{
	class Sound;
	class SoundBuffer;
	class Music;
}

namespace sound
{
	class SoundSystem
	{
	public:
		SoundSystem();
		~SoundSystem();

	private:
		// EngineSystems interface
		// {
		friend class EngineSystems;
		void update(float fDT);
		// }

		// SoundSystem internals
		// {
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