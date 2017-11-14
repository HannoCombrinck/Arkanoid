#include "SoundSystem.h"

#include <iostream>

#include <SFML/Audio.hpp>

#include <Engine/Sound/Sound.h>

using namespace std;
using namespace core;

namespace sound {

	SoundSystem::SoundSystem()
		: m_fGlobalVolume(100.0f)
	{
		m_BeepSoundBuffer = make_unique<sf::SoundBuffer>();
		m_BeepSound = make_unique<sf::Sound>();
		m_Music = make_unique<sf::Music>();

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

	uint SoundSystem::createSound()
	{
		return 0U;
	}

	void SoundSystem::update(float fDT)
	{

	}

}