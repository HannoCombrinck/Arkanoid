#include "Socket.h"

#include <iostream>

using namespace std;

namespace network {

	Socket::Socket()
	{

	}

	Socket::~Socket()
	{
	}

	bool Socket::open(ushort uPort)
	{
		return false;
	}

	void Socket::close()
	{
	}

	bool Socket::isOpen() const
	{
		return false;
	}

	bool Socket::send(const Address & destination, const void * pData, int iSize)
	{
		return false;
	}

	int Socket::receive(const Address & sender, void * pData, int iSize)
	{
		return 0;
	}

}
