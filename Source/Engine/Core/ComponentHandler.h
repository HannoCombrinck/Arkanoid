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
		m_aComponents.resize(m_uSize);
		for (uint i = 0U; i < m_uSize; ++i)
		{
			m_aComponents[i].init(pSystem);
			m_aIndices.push_back(i);
		}
	}

	~ComponentHandler() {}

	uint create()
	{
		assert(m_uNext < m_uSize);
		return m_aIndices[m_uNext++];
	}

	COMPONENT_TYPE& modify(uint uHandle)
	{
		assert(uHandle < m_uSize);
		return m_aComponents[uHandle];
	}

	void remove(uint uHandle)
	{
		for (uint i = 0U; i < m_uNext; ++i)
		{
			if (m_aIndices[i] == uHandle)
			{
				m_uNext--;
				m_aComponents[uHandle].clean();
				std::swap(m_aIndices[i], m_aIndices[m_uNext]);
				return;
			}
		}
	}

	uint getSize() const
	{
		return m_uNext;
	}

	std::vector<COMPONENT_TYPE>& getData()
	{
		return m_aComponents;
	}

	void foreach(const std::function<void(COMPONENT_TYPE&)> f)
	{
		for (uint i = 0U; i < m_uNext; ++i)
		{
			if (m_aComponents[i].alive())
				f(m_aComponents[i]);
		}
	}

private:
	std::vector<COMPONENT_TYPE> m_aComponents;
	std::vector<uint> m_aIndices;
	uint m_uNext;
	uint m_uSize;
};
