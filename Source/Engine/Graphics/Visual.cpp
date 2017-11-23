#include "Visual.h"

#include <iostream>

#include <Engine/Graphics/VisualSystem.h>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace graphics {

	Visual::Visual(VisualSystem* pVisualSystem)
		: m_pVisualSystem(pVisualSystem)
	{
	}

	Visual::~Visual()
	{
	}

	void Visual::update(float fDT)
	{
	}
	
}