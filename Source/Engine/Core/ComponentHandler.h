#pragma once

#include <Engine/Core/GlobalTypes.h>

#define ADD_COMPONENT(SystemName, ComponentName) \
public: \
	ComponentName& create##ComponentName(uint& uHandle) { uHandle = m_up##ComponentName##Handler->create(); return modify##ComponentName(uHandle); } \
	ComponentName& modify##ComponentName(uint uHandle) { return m_up##ComponentName##Handler->modify(uHandle); } \
	void remove##ComponentName(uint uHandle) { m_up##ComponentName##Handler->remove(uHandle); } \
private: \
	typedef ComponentHandler<ComponentName, SystemName>  ComponentName##_handler_type; \
	ComponentName##_handler_type& ComponentName##Handler() { return *m_up##ComponentName##Handler; } \
	std::unique_ptr<ComponentName##_handler_type> m_up##ComponentName##Handler; \
public:

#define CREATE_COMPONENT_HANDLER(ComponentName, InitialComponentCount) \
m_up##ComponentName##Handler = std::unique_ptr<ComponentName##_handler_type>(new ComponentName##_handler_type(this, InitialComponentCount));


template <typename COMPONENT_TYPE, typename SYSTEM_TYPE>
class ComponentHandler
{
public:
	ComponentHandler(SYSTEM_TYPE* pSystem, uint uInitialSize)
		: m_pSystem(pSystem)
		, m_uSize(uInitialSize)
		, m_uNext(0U)
	{
		m_aComponents.resize(m_uSize);
		for (uint i = 0U; i < m_uSize; ++i)
			m_aIndices.push_back(i);
	}

	~ComponentHandler() {}

	uint create()
	{
		if (m_uNext >= m_uSize)
			std::cout << "Too many components created - this handler has a max of: " << m_uSize << std::endl;

		assert(m_uNext < m_uSize);
		auto uIndex = m_aIndices[m_uNext++];
        m_aComponents[uIndex].init();
		return uIndex;
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
				m_aComponents[uHandle].destroy();
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
			if (m_aComponents[i].isAlive())
				f(m_aComponents[i]);
		}
	}

	void printLists()
	{
		std::cout << "Component names:\n";
		for (auto& r : m_aComponents)
		{
			if (r.isAlive())
				r.printName();
		}

		std::cout << "Index list:\n";
		uint uIndex = 0U;
		for (auto i = 0U; i < m_aIndices.size(); ++i)
		{
			uIndex = m_aIndices[i];
			if (m_aComponents[uIndex].isAlive())
				std::cout << i << ") " << uIndex << std::endl;
		}
	}

private:
	SYSTEM_TYPE* m_pSystem; // TODO: Is this necessary?
	std::vector<COMPONENT_TYPE> m_aComponents;
	std::vector<uint> m_aIndices;
	uint m_uNext;
	uint m_uSize;
};
