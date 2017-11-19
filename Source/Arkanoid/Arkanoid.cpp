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

	//auto spLevel1 = World::load("../Data/Levels/1.dat");
	//m_spWorld = boost::shared_ptr<World>(spLevel1);

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
}

void Arkanoid::onInit()
{
	OnTrue(engine().inputs().getKeyState(KEY_N), bind(&Arkanoid::startNewGame, this));
	OnTrue(engine().inputs().getKeyState(KEY_Num1), bind(&Arkanoid::stopGame, this));

	//auto spMainMenu = World::load("../Data/Menus/main.dat");
}


void Arkanoid::onUpdate(float fDT)
{
	// Execute conditional actions 
	for (auto& action : m_aActions)
		action();

	// Update world and all of its entities
	if (m_spWorld)
		m_spWorld->update(fDT);
}

void Arkanoid::OnTrue(bool& bCondition, function<void()> fnAction)
{
	m_aActions.emplace_back(TrueEdgeAction(bCondition, fnAction));
}

/*void Arkanoid::onKeyPressed(KeyboardKey eKey)
{
	switch (eKey)
	{
	case KEY_N:
		startNewGame();
		return;
		break;
	case KEY_Num1:
		stopGame();
		return;
		break;
	}

	cout << "Key pressed: " << eKey << endl;
}*/
