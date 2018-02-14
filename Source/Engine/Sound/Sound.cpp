#include "Sound.h"

#include <iostream>

using namespace std;

namespace sound {

	Sound::Sound(SoundSystem* pSoundSystem)
		: m_pSoundSystem(pSoundSystem)
		, m_uSound(~0)
	{
	}

	Sound::~Sound()
	{
	}

	void Sound::loadSound(const std::string & sFilename)
	{
		// TODO:
		//m_pSoundSystem->createSoundBuffer()
		//m_pSoundSystem->createSoundPlayer()
	}

	void Sound::update(float fDT)
	{
	}

}