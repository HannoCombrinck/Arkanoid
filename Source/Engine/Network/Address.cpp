#include "Address.h"

#include <iostream>

using namespace std;

namespace network {

	Address::Address()
		: m_uAddress((127 << 24) | uchar(1))
		, m_uPort(3000)
	{
	}

	Address::Address(uchar a, uchar b, uchar c, uchar d, ushort uPort)
		: m_uAddress((a << 24) | (b << 16) | (c << 8) | d)
		, m_uPort(uPort)
	{
	}

	Address::Address(uint uAddress, ushort uPort)
		: m_uAddress(uAddress)
		, m_uPort(uPort)
	{
	}

	Address::~Address()
	{
	}

	uint Address::getAddress() const
	{
		return m_uAddress;
	}

	uchar Address::getA() const
	{
		return (m_uAddress >> 24) & 0xff;
	}

	uchar Address::getB() const
	{
		return (m_uAddress >> 16) & 0xff;
	}

	uchar Address::getC() const
	{
		return (m_uAddress >> 8) & 0xff;
	}

	uchar Address::getD() const
	{
		return m_uAddress & 0xff;
	}

	ushort Address::getPort() const
	{
		return m_uPort;
	}

}
