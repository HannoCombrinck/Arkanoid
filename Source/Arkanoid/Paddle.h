#pragma once

#include <vector>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Math/Math.h>
#include <Engine/Entity/Entity.h>

using namespace math;
using namespace entity;

struct EntityData
{
	virtual const std::string getEntityType() const = 0;
};

/*
Paddle
{
	Vec2 vPos
}
*/

struct PaddleData : public EntityData
{
	Vec2 vPos;
	float fSpeed;

	const std::string getEntityType() const { return "Paddle"; }
};
/*

	template <class Archive>
	void serialize(Archive& a, const unsigned int uVersion)
	{
		a & boost::serialization::base_object<EntityData>(*this);
		a & vPos;
	}
};
BOOST_SERIALIZATION_SHARED_PTR(PaddleData)
BOOST_CLASS_EXPORT(PaddleData)
*/

namespace
{
	void loadEntities()
	{
		std::vector<boost::shared_ptr<EntityData>> aspEntities;
		for (auto sp : aspEntities)
		{
			auto sEntityType = sp->getEntityType();
			//auto pEntity = factory.create(sEntityType);
			//pEntity->initFrom(sp);
			//pWorld->add(pEntity);
		}
	}
}

class Paddle : public Entity
{
public:
	Paddle();
	virtual ~Paddle();

	void initFrom(EntityData* rData)
	{
		auto pPaddleData = reinterpret_cast<PaddleData*>(rData);
	}

private:
	// Entity callbacks
	// {
	virtual void onInit() override;
	virtual void onUpdate(float fDT) override;
	// }

	void getInputs();
	void handleTextInput();
	void processCommand();
	void updateState();
	void applyState();

	PaddleData m_Data;
	bool m_bLeft;
	bool m_bRight;
	bool m_bAction;

	uint m_uPaddleVis;

	// Test
	uint m_uSound;
	uint m_uVisualText;
	bool m_bInputMode;
	std::string m_sCommand;
	uint m_uTextBuffer;
};
