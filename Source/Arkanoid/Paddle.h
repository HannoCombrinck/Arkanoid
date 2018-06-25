#pragma once

#include <vector>

#include <Engine/Core/GlobalTypes.h>
#include <Engine/Math/Math.h>
#include <Engine/Entity/Entity.h>

#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>


using namespace math;
using namespace entity;

struct EntityData
{
	virtual const std::string getEntityType() const = 0;

	template <class Archive>
	void serialize(Archive& a, const unsigned int uVersion)
	{
	}
};

struct PaddleData : public EntityData
{
	Vec2 vPos;
	float fSpeed;

	const std::string getEntityType() const { return "Paddle"; }

	template <class Archive>
	void serialize(Archive& a, const unsigned int uVersion)
	{
		a & boost::serialization::base_object<EntityData>(*this);
		a & vPos.x;
		a & vPos.y;
		a & fSpeed;
	}
};


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
