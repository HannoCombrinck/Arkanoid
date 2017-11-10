#include "SoundSystem.h"

#include <iostream>

#include <SFML\Audio.hpp>

using namespace std;
using namespace sf;
using namespace core;

namespace sound {

	SoundSystem::SoundSystem()
		: m_fGlobalVolume(100.0f)
	{
		m_BeepSoundBuffer = make_unique<SoundBuffer>();
		m_BeepSound = make_unique<Sound>();
		m_Music = make_unique<Music>();

		if (!m_BeepSoundBuffer->loadFromFile("../Data/Sounds/beep.wav"))
			std::cout << "Couldn't load beep.wav\n";

		m_BeepSound->setBuffer(*m_BeepSoundBuffer);

		if (!m_Music->openFromFile("../Data/Sounds/ambient.ogg"))
			std::cout << "Couldn't load ambient.ogg";

		m_Music->setLoop(true);
		m_Music->play();
	}

	SoundSystem::~SoundSystem()
	{
	}

	void SoundSystem::update(float fDT)
	{

	}

}