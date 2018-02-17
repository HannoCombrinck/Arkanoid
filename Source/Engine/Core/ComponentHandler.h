#pragma once

#include <Engine/Core/GlobalTypes.h>

template <typename COMPONENT_TYPE, typename SYSTEM_TYPE>
class ComponentHandler
{
public:
	ComponentHandler(SYSTEM_TYPE* pSystem, uint uInitialSize)
		: m_uSize(uInitialSize)
		, m_uNext(0U)
	{
		for (uint i = 0U; i < m_uSize; ++i)
		{
			m_aComponents.emplace_back(COMPONENT_TYPE(pSystem));
			m_aIndices.push_back(i);
		}
	}

	~ComponentHandler() {}

	uint create()
	{
		return m_aIndices[m_uNext++];
	}

	COMPONENT_TYPE& modify(uint uIndex)
	{
		assert(uIndex < m_uNext);
		return m_aComponents[m_aIndices[uIndex]];
	}

	void remove(uint uHandle)
	{
		assert(uIndex < m_uNext);
		for (uint i = 0U; i < m_uNext; ++i)
		{
			if (m_aIndices[i] = m_aIndices[uHandle])
			{
				m_uNext--;
				//m_aComponents[m_aIndices[i]].clean(); // TODO: De-allocate resources here?
				std::swap(m_aIndices[i], m_aIndices[m_uNext]);
				return;
			}
		}
	}

	void update(float fDT)
	{
		for (uint i = 0U; i < m_uNext; ++i)
			m_aComponents[i].update(fDT);
	}

private:
	std::vector<COMPONENT_TYPE> m_aComponents;
	std::vector<uint> m_aIndices;
	uint m_uNext;
	uint m_uSize;
};
