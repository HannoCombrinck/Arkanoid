#include "Socket.h"

#include <Engine/Network/Address.h>

#if PLATFORM == PLATFORM_WINDOWS
	#include <winsock2.h>
#elif PLATFORM == PLATFORM_UNIX
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <fcntl.h>
#endif

#include <iostream>

using namespace std;

namespace network {

	Socket::Socket()
		: m_iHandle(-1)
	{
		#if PLATFORM == PLATFORM_WINDOWS
			WSADATA WsaData;
			auto iStartupResult = WSAStartup(MAKEWORD(2, 2), &WsaData);
			if (iStartupResult != NO_ERROR)
				cout << "Failed to initialize sockets library, error: " << iStartupResult << endl;
		#endif
	}

	Socket::~Socket()
	{
		#if PLATFORM == PLATFORM_WINDOWS
			WSACleanup();
		#endif
	}

	bool Socket::open(ushort uPort)
	{
		// Create socket
		m_iHandle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (m_iHandle <= 0)
		{
			cout << "Failed to create socket\n";
			return false;
		}
		
		// Bind socket to provided port number
		sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(uPort);

		auto iBindResult = ::bind(m_iHandle, reinterpret_cast<const sockaddr*>(&address), sizeof(sockaddr_in));
		if (iBindResult < 0)
		{
			cout << "Failed to bind socket\n";
			return false;
		}

		// Put socket in non-blocking mode
		#if PLATFORM == PLATFORM_WINDOWS
			DWORD wNonBlocking = 1;
			auto iSetIOModeResult = ioctlsocket(m_iHandle, FIONBIO, &wNonBlocking);
			if (iSetIOModeResult != 0)
			{
				cout << "Failed to set socket to non-blocking mode\n";
				return false;
			}
		#elif PLATFORM == PLATFORM_UNIX
			int iNonBlocking = 1;
			auto iSetIOModeResult = fcntl(m_iHandle, F_SETFL, O_NONBLOCK, iNonBlocking);
			if (iSetIOModeResult < 0)
			{
				cout << "Failed to set socket to non-blocking mode\n";
				return false;
			}
		#endif

		return true;
	}

	void Socket::close()
	{
		#if PLATFORM == PLATFORM_WINDOWS
			closesocket(m_iHandle);
		#elif PLATFORM == PLATFORM_UNIX
			close(m_iHandle);
		#endif
		m_iHandle = -1;
	}

	bool Socket::isOpen() const
	{
		return m_iHandle > 0;
	}

	bool Socket::send(const Address& destination, const void* pData, int iSize)
	{
		sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = htonl(destination.getAddress());
		address.sin_port = htons(destination.getPort());

		auto iSentBytes = sendto(m_iHandle, reinterpret_cast<const char*>(pData), iSize, 0, reinterpret_cast<sockaddr*>(&address), sizeof(sockaddr_in));
		if (iSentBytes != iSize)
		{
			cout << "Failed to send packet\n";
			return false;
		}

		return true;
	}

	int Socket::receive(Address& sender, void* pData, int iSize)
	{
		#if PLATFORM == PLATFORM_WINDOWS
			typedef int socklen_t;
		#endif

		sockaddr_in senderAddress;
		socklen_t iSenderAddressSize = sizeof(senderAddress);
		auto iBytes = recvfrom(m_iHandle, reinterpret_cast<char*>(pData), iSize, 0, reinterpret_cast<sockaddr*>(&senderAddress), &iSenderAddressSize);
		
		if (iBytes < -1)
			cout << "Receive error: " << strerror(errno) << endl;

		sender = Address(ntohl(senderAddress.sin_addr.s_addr), ntohs(senderAddress.sin_port));
		return iBytes;
	}

}
