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
		auto spSound = boost::shared_ptr<Sound>(new Sound());
		m_aspSounds.push_back(spSound);
		return m_aspSounds.size() - 1;
	}

	Sound & SoundSystem::modifySound(uint uSound)
	{
		assert(uSound < m_aspSounds.size());
		return *(m_aspSounds[uSound]);
	}

	void SoundSystem::removeSound(uint uSound)
	{
		m_aspSounds.erase(m_aspSounds.begin() + uSound);
	}

	void SoundSystem::update(float fDT)
	{
		for (auto& s : m_aspSounds)
			s->update(fDT);
	}

}