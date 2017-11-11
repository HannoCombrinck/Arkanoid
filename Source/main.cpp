#include <assert.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>

#pragma warning (push) 
#pragma warning (disable : 4244) // Disable benign boost warning generated by VS2010 when including these 2 headers
#include <boost/archive/binary_oarchive.hpp> 
#include <boost/archive/binary_iarchive.hpp> 
#pragma warning (pop) 

#include <boost/enable_shared_from_this.hpp>
#include <boost/move/unique_ptr.hpp>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

#include <Engine/Core/Math/MathHelpers.h>

#include <Engine/AppBase.h>
#include <Engine/Input/InputSystem.h>
#include <Arkanoid/Arkanoid.h>

using namespace sf;
using namespace std;
using namespace core;
using namespace input;

namespace game
{
	class Component 
	{
	public: 
		Component() {}
		~Component() {}

	private:

	};

	class GameObject
	{
	public:
		GameObject() {}
		~GameObject() {}
		
		void init() { onInit(); }

	private:
		virtual void onInit() {}

		friend class boost::serialization::access;
		template <class Archive>
		void serialize(Archive& a, const unsigned int uVersion)
		{
		}
	};

	class GameWorld
	{
	public:
		GameWorld() {}
		~GameWorld() {}


	private:
	};
}
BOOST_SERIALIZATION_SHARED_PTR(game::GameObject)
BOOST_CLASS_EXPORT(game::GameObject)

class SystemsManager;
class VisualSystem;
class PhysicsSystem;
class InputSystem;
class SoundSystem;

class PowerUp : public game::GameObject
{
public: 
	PowerUp() {}
	virtual ~PowerUp() {}

private:
	
};

class Paddle : public game::GameObject
{
public:
	Paddle() {}
	~Paddle() {}

	Paddle& setPosition(const Vec3& v) { m_vPos = v; return *this; }
	Vec3 getPosition() const { return m_vPos; }

	Paddle& setMoveSpeed(float f) { m_fMoveSpeed = f; return *this; }
	float getMoveSpeed() const { return m_fMoveSpeed; }

	string getType() const { return "Paddle"; }

private:
	Vec3 m_vPos;
	float m_fMoveSpeed;


	void moveLeft()
	{
		m_vPos.x -= m_fMoveSpeed;
	}

	void moveRight()
	{
		m_vPos.x -= m_fMoveSpeed;
	}

	void updateVisuals()
	{
		//m_spVisModel->setPosition(m_vPos);
	}

	void createVisualComponents(VisualSystem& VS)
	{
		//m_spPaddleVisual = VS.createStaticVisual("data/models/paddle.fbx");
		//m_spPaddleNode = m_spPaddleVisual->getNode("paddle");
	}

	void createPhysicsComponents(PhysicsSystem& PS)
	{
		//m_spRigidBody = CreateComponent<RigidBodyComponent>(physics::BOX, 50, 10);
	}

	//void createInputComponents(InputSystem& IS)
	//{
		// m_spKeyboardInput = IS.createKeyboardComponent();
		// Use m_spKeyboardInput bind callbacks for key presses

		// m_spMouseInput = IS.createMouseComponent();
		// Use m_spMouseInput to bind callbacks for mouse button presses and mouse movements
	//}
	
	void createSoundComponents(SoundSystem& SS)
	{
		// m_spTestSound = SS.createSound("../Data/Sounds/test.wav");
	}

	virtual void onInit(SystemsManager& SM) 
	{
		//createVisualComponents(SM.spVisualSystem);
		//createPhysicsComponents(SM.spPhysicsSystem);
		//createInputComponents(SM.spInputSystem);
		//createSoundComponents(SM.spSoundSystem);
	}

	// Latest inputs available but physics engine hasn't stepped yet
	void onPrePhysicsUpdate(double ddT)
	{
		//const auto& rInputs = GetInputState();
		//if (rInputs.isDown(m_cLeft))
		//	moveLeft();
		//if (rInputs.isDown(m_cRight))
		//	moveRight();
	}

	// Latest inputs available and right after physics engine step i.e. latest rigid body transforms available
	void onPostPhysicsUpdate(double ddT)
	{
		updateVisuals();
	}

	void onPreRenderUpdate(double ddT)
	{
	}

	void onPostRenderUpdate(double ddT)
	{
	}

	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& a, const unsigned int uVersion)
	{
		a & boost::serialization::base_object<GameObject>(*this);
		a & m_vPos.x;
		a & m_vPos.y;
		a & m_vPos.z;
		a & m_fMoveSpeed;
	}
};
BOOST_SERIALIZATION_SHARED_PTR(Paddle)
BOOST_CLASS_EXPORT(Paddle)


class Node : public boost::enable_shared_from_this<Node>
{
public:
	Node() {}
	Node(const string& s) : m_sName(s) {}
	virtual ~Node() {}

	void setName(const string& s) { m_sName = s; }
	string getName() const { return m_sName; }

	void addChild(const boost::shared_ptr<Node>& spChild)
	{
		m_aspChildren.push_back(spChild);
	}

	virtual void traverse(const function<void(const boost::shared_ptr<Node>& spNode)>& f)
	{
		f(shared_from_this());
		for (auto i = m_aspChildren.begin(); i != m_aspChildren.end(); ++i)
		{
			(*i)->traverse(f);
		}
	}

private:
	string m_sName;
	vector<boost::shared_ptr<Node>> m_aspChildren;

	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& a, const unsigned int uVersion)
	{
		a & m_sName;
		a & m_aspChildren;
	}
};
BOOST_SERIALIZATION_SHARED_PTR(Node)


class Geometry : public Node
{
public:
	Geometry() {}
	Geometry(const string& s) : Node(s) {}
	virtual ~Geometry() {}

	const vector<char>& getBuffer() const { return m_Buffer; }
	vector<char>& modifyBuffer() { return m_Buffer; }

private:
	vector<char> m_Buffer;

	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive& a, const unsigned int uVersion)
	{
		a & boost::serialization::base_object<Node>(*this);
		a & m_Buffer;
	}
};
BOOST_SERIALIZATION_SHARED_PTR(Geometry)
BOOST_CLASS_EXPORT(Geometry)

boost::shared_ptr<Node> buildGraph() 
{
	auto spRoot = boost::shared_ptr<Node>(new Node("root"));
	auto n1 = boost::shared_ptr<Node>(new Node("n1"));
	auto n2 = boost::shared_ptr<Node>(new Node("n2"));
	auto n3 = boost::shared_ptr<Node>(new Node("n3"));
	auto n4 = boost::shared_ptr<Node>(new Node("n4"));
	auto n5 = boost::shared_ptr<Node>(new Node("n5"));

	auto g1 = boost::shared_ptr<Node>(new Geometry("g1"));
	auto g2 = boost::shared_ptr<Node>(new Geometry("g2"));
	auto g3 = boost::shared_ptr<Node>(new Geometry("g3"));

	n4->addChild(n5);
	n4->addChild(g3);
	n3->addChild(g3);
	n2->addChild(g2);
	n1->addChild(n2);
	n1->addChild(g1);
	spRoot->addChild(n1);
	spRoot->addChild(n3);
	spRoot->addChild(n4);

	return spRoot;
}

bool saveGraph(const boost::shared_ptr<Node>& spRoot, const string& sFile)
{
	ofstream OutFile(sFile.c_str(), ios::binary);
	if (!OutFile.is_open())
		return false;

	boost::archive::binary_oarchive OutArchive(OutFile);
	OutArchive << spRoot;

	OutFile.close();
	return true;
}

boost::shared_ptr<Node> loadGraph(const string& sFile)
{
	ifstream InFile(sFile.c_str(), ios::binary);
	if (!InFile.is_open())
		return boost::shared_ptr<Node>();

	boost::archive::binary_iarchive InArchive(InFile);
	
	auto spRoot = boost::shared_ptr<Node>(new Node);
	InArchive >> spRoot;

	InFile.close();
	return spRoot;
}

/*
World
	Paddle
	Bricks
		SmallBricks
		...
		BigBricks
		...
	Ball1
	Ball2
*/
namespace engine
{
	namespace core
	{
		namespace graphics
		{
			class Renderer;
			class VertexBuffer;
			class StaticGeometry;
			class Texture;
			class Image;
		}

		namespace physics
		{
			class BulletDynamicsWorld;
		}
		
		namespace sound
		{
			class OpenALHelpers;
		}
	}

	namespace graphics
	{
		class VisualSystem;

		class StaticModel;
		class AnimatedModel;
		class SkeletalModel;
	}

	namespace physics
	{
		class PhysicsSystem;

		class RigidBody;
	}

	namespace sound
	{
		class SoundSystem;

		class SoundSource;
		class Sound;
		class SoundListener;
	}

	namespace entity
	{
		class EntitySystem;

		class Entity;
	}
}

int main(int argc, char** argv)
{
	/*auto spRoot = buildGraph();
	saveGraph(spRoot, "../Data/graph.dat");
	auto spNewRoot = loadGraph("../Data/graph.dat");*/

	Arkanoid arkanoid;
	arkanoid.start();

	return 0;
}

