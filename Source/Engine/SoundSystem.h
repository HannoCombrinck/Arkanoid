#pragma once
#include <memory>
#include <Engine\Core\Math\Math.h>

namespace sf
{
	class Sound;
	class SoundBuffer;
	class Music;
}

namespace engine
{
	class SoundSystem
	{
	public:
		SoundSystem();
		~SoundSystem();

	private:
		// AppBase interface
		// {
		friend class AppBase;
		void update(float fDT);
		// }

		// TEMP
		std::unique_ptr<sf::Sound> m_BeepSound;
		std::unique_ptr<sf::SoundBuffer> m_BeepSoundBuffer;
		std::unique_ptr<sf::Music> m_Music;
	};
}