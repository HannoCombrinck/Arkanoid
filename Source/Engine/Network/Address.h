#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>

namespace network
{
	class Address
	{
	public:
		Address();
		Address(uchar a, uchar b, uchar c, uchar d, ushort uPort);
		Address(uint uAddress, ushort uPort);
		~Address();

		uint getAddress() const;
		uchar getA() const;
		uchar getB() const;
		uchar getC() const;
		uchar getD() const;
		ushort getPort() const;

	private:
		uint m_uAddress;
		ushort m_uPort;

	};
}
