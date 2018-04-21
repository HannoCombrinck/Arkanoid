#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>

namespace network
{
	class Address;
}

namespace network
{
	class Socket
	{
	public:
		Socket();
		~Socket();

		bool open(ushort uPort);
		void close();
		bool isOpen() const;
		bool send(const Address& destination, const void* pData, int iSize);
		int receive(Address& sender, void* pData, int iSize);

	private:
		int m_iHandle;

	};
}
