#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>

namespace sound
{
	class SoundSystem;
}

namespace sound
{
	class Sound
	{
	public:
		Sound(SoundSystem* pSoundSystem);
		~Sound();

	private:
		// SoundSystem interface
		// {
		friend class SoundSystem;
		void loadSound(const std::string& sFilename);
		void update(float fDT);
		// }

		SoundSystem* m_pSoundSystem;
		uint m_uSound;
	};
}