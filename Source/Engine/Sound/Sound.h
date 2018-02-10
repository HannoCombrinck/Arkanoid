#pragma once
#include <memory>

namespace sound
{
	class SoundSystem;
}

namespace sound
{
	class Sound
	{
	public:
		Sound();
		~Sound();

	private:
		// SoundSystem interface
		// {
		friend class SoundSystem;
		void update(float fDT);
		// }

	};
}