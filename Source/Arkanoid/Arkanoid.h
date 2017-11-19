#pragma once

#include <memory>
#include <string>
#include <Engine/AppBase.h>
#include <Arkanoid/ArkanoidFactory.h>
#include <boost/shared_ptr.hpp>

namespace entity
{
	class World;
}

class Arkanoid : public AppBase
{
public:
	enum GameState
	{
		STOPPED,
		RUNNING,
		PAUSED,
	};

	Arkanoid();
	virtual ~Arkanoid();

	void startNewGame();
	void stopGame();
	void loadGame(const std::string& sFilename);

private:
	// AppBase overrides
	// {
	void onInit() override;
	void onUpdate(float fDT) override;
	// }

	// Conditional actions
	// {
	struct TrueEdgeAction
	{
		TrueEdgeAction(bool& _bCondition, function<void()> _fnAction)
			: bCondition(_bCondition)
			, fnAction(_fnAction)
			, bPrev(false)
		{}

		void operator()() 
		{
			if (bCondition && !bPrev)
				fnAction();

			bPrev = bCondition;
		}

		function<void()> fnAction;
		bool& bCondition;
		bool bPrev;
	};
	std::vector<TrueEdgeAction> m_aActions;
	void OnTrue(bool& bCondition, function<void()> fnAction);
	// }

	unique_ptr<ArkanoidFactory> m_upFactory;

	boost::shared_ptr<entity::World> m_spWorld;

	GameState m_eState;
};
