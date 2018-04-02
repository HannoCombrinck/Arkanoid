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
		m_BeepSoundBuffer = unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer);
		m_BeepSound = unique_ptr<sf::Sound>(new sf::Sound);
		m_Music = unique_ptr<sf::Music>(new sf::Music);

		if (!m_BeepSoundBuffer->loadFromFile("../Data/Sounds/beep.wav"))
			std::cout << "Couldn't load beep.wav\n";

		m_BeepSound->setBuffer(*m_BeepSoundBuffer);

		if (!m_Music->openFromFile("../Data/Sounds/ambient.ogg"))
			std::cout << "Couldn't load ambient.ogg";

		m_Music->setLoop(true);
		//m_Music->play();
	}

	SoundSystem::~SoundSystem()
	{
	}

	uint SoundSystem::createSound(const std::string& sFilename)
	{
		auto upSound = unique_ptr<Sound>(new Sound(this));
		upSound->loadSound(sFilename);
		m_aupSounds.push_back(std::move(upSound));
		return m_aupSounds.size() - 1;
	}

	Sound & SoundSystem::modifySound(uint uSound)
	{
		assert(uSound < m_aupSounds.size());
		return *(m_aupSounds[uSound]);
	}

	void SoundSystem::removeSound(uint uSound)
	{
		m_aupSounds.erase(m_aupSounds.begin() + uSound);
	}

	void SoundSystem::update(float fDT)
	{
		for (auto& s : m_aupSounds)
			s->update(fDT);
	}

}
