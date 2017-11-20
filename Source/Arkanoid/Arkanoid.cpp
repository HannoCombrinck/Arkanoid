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

	LevelGenerator levelGen;
	auto spLevel = levelGen.generate(*m_upFactory);
	spLevel->init(engine());
	m_spWorld = boost::shared_ptr<World>(spLevel);

	m_eState = RUNNING;
}

void Arkanoid::stopGame()
{
	if (m_eState == STOPPED)
		return;

	cout << "Stopping game\n";
	m_spWorld.reset();

	m_eState = STOPPED;
}

void Arkanoid::loadGame(const string& sFilename)
{
	auto spLevel = World::load(sFilename);
	m_spWorld = boost::shared_ptr<World>(spLevel);

	m_eState = RUNNING;
}

void Arkanoid::onInit()
{
}

void Arkanoid::onUpdate(float fDT)
{
	if (engine().inputs().isKeyPressed(KEY_N) && m_eState == STOPPED)
		startNewGame();

	if (engine().inputs().isKeyPressed(KEY_Num1) && m_eState == RUNNING)
		stopGame();

	// Update world and all of its entities
	if (m_spWorld)
		m_spWorld->update(fDT);
}
