#include "Arkanoid.h"

#include <iostream>
#include <functional>

#include <Engine/SystemsInclude.h>
#include <Engine/EngineSystems.h>
#include <Engine/Entity/World.h>
#include <Arkanoid/LevelGenerator.h>
#include <boost/make_shared.hpp>

using namespace std;
using namespace input;
using namespace graphics;
using namespace sound;
using namespace entity;

Arkanoid::Arkanoid()
	: m_spWorld(nullPtr)
	, m_eState(STOPPED)
{
	m_upFactory = make_unique<ArkanoidFactory>();
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::startNewGame()
{
	if (m_eState == RUNNING)
		return;

	cout << "Starting new game\n";

	m_spWorld = boost::make_shared<World>();

	LevelGenerator levelGen;
	levelGen.generate(m_spWorld, *m_upFactory);

	m_spWorld->init(engine());
	engine().entities().setActiveWorld(m_spWorld);

	m_eState = RUNNING;
}

void Arkanoid::stopGame()
{
	if (m_eState == STOPPED)
		return;

	cout << "Stopping game\n";
	m_spWorld.reset();
	engine().entities().setActiveWorld(nullPtr);

	m_eState = STOPPED;
}

void Arkanoid::loadGame(const string& sFilename)
{
	auto spLevel = World::load(sFilename);
	m_spWorld = boost::shared_ptr<World>(spLevel);
	engine().entities().setActiveWorld(m_spWorld);

	m_eState = RUNNING;
}

void Arkanoid::onInit()
{
}

void Arkanoid::onUpdate(float fDT)
{
}

void Arkanoid::onKeyPressed(KeyboardKey eKey)
{
	switch (eKey)
	{
	case KEY_N:
		if (m_eState == STOPPED)
			startNewGame();
		break;
	case KEY_Num1:
		if (m_eState == RUNNING)
			stopGame();
		break;
	case KEY_Escape:
		if (m_eState == STOPPED)
			closeApplication();
		break;
	case KEY_F2:
		toggleFullscreen();
		break;
	case KEY_F3:
		toggleMouseLock();
		break;
	case KEY_F4:
		toggleVSync();
		break;
	default:
		break;
	}
}
