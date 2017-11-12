#pragma once

#include <memory>
#include <string>
#include <Engine/AppBase.h>
#include <boost/shared_ptr.hpp>

class ArkanoidState;
class StatePlaying;
class StateMenu;

class Arkanoid : public AppBase
{
public:
	Arkanoid();
	virtual ~Arkanoid();

	void startNewGame();
	void stopGame();
	void loadGame(const std::string& sFilename);

	void setState(ArkanoidState* p) { m_pState = p; }
	ArkanoidState* getState() const { return m_pState; }

private:
	// AppBase overrides
	// {
	void onInit() override;
	void onUpdate(float fDT) override;
	// }

	void onStateChanged();

	ArkanoidState* m_pState;
	boost::shared_ptr<StatePlaying> m_spStatePlaying;
	boost::shared_ptr<StateMenu> m_spStateMenu;
};
