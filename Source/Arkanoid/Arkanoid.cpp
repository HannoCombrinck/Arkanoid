#include "Arkanoid.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>
#include <Engine/Graphics/VisualSystem.h>
#include <Engine/Sound/SoundSystem.h>
#include <Engine/EngineSystems.h>
#include <Engine/Entity/World.h>
#include <Arkanoid/StateMenu.h>
#include <Arkanoid/StatePlaying.h>
#include <boost/make_shared.hpp>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;
using namespace entity;

Arkanoid::Arkanoid()
{
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::startNewGame()
{
	m_pState = m_spStatePlaying.get();
	engine().inputs().setListener(m_spStatePlaying);

	auto spLevel1 = World::load("../Data/Levels/1.dat");
	m_spStatePlaying->setWorld(spLevel1);
}

void Arkanoid::stopGame()
{
	m_pState = m_spStateMenu.get();
	engine().inputs().setListener(m_spStateMenu);
}

void Arkanoid::loadGame(const string & sFilename)
{
	auto spLevel = World::load(sFilename);
	m_spStatePlaying->setWorld(spLevel);
}

void Arkanoid::onInit()
{
	m_spStatePlaying = boost::make_shared<StatePlaying>(this);
	m_spStateMenu = boost::make_shared<StateMenu>(this);
	m_pState = m_spStateMenu.get();
	engine().inputs().setListener(m_spStateMenu);

	//auto spMainMenu = World::load("../Data/Menus/main.dat");
	//m_spStateMenu->setWorld(spMainMenu);
}

void Arkanoid::onUpdate(float fDT)
{
	m_pState->update(fDT);
}

void Arkanoid::onStateChanged()
{
}
