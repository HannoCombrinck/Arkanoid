#include "Arkanoid.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>
#include <Arkanoid/StateMenu.h>
#include <Arkanoid/StatePlaying.h>
#include <boost/make_shared.hpp>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;

Arkanoid::Arkanoid()
{
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::startNewGame()
{
	m_pState = m_spStatePlaying.get();
	InputSys()->setListener(m_spStatePlaying);
}

void Arkanoid::stopGame()
{
	m_pState = m_spStateMenu.get();
	InputSys()->setListener(m_spStateMenu);
}

void Arkanoid::load(const string & sFile)
{
}

void Arkanoid::onInit()
{
	m_spStatePlaying = boost::make_shared<StatePlaying>(this);
	m_spStateMenu = boost::make_shared<StateMenu>(this);
	m_pState = m_spStateMenu.get();
	InputSys()->setListener(m_spStateMenu);
}

void Arkanoid::onUpdate(float fDT)
{
	m_pState->update(fDT);
}

void Arkanoid::onStateChanged()
{
}
