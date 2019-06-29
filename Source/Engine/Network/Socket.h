#pragma once
#include <memory>

#include <Engine/Core/GlobalTypes.h>

namespace network
{
	class Address;
}

namespace network
{
	/*
	// Example usage
	void testSocket()
	{
		Socket socket(3001);
		if (!socket.isOpen())
		{
			cout << "Failed to open socket\n";
			return;
		}

		const char aData[] = "Test packet!";

		// Send packet to self
		socket.send(Address(3001), aData, sizeof(aData));

		// Receive packet from self
		Address senderAddress;
		const auto uMaxPacketSize = 256U;
		uchar aBuffer[uMaxPacketSize];
		int iBytes = 1;
		while (iBytes > 0)
		{
			iBytes = socket.receive(senderAddress, aBuffer, uMaxPacketSize);

			if (iBytes > 0)
			{
				cout << "Packet data:\n";
				for (auto i = 0; i < iBytes; ++i)
					cout << aBuffer[i];
				cout << endl;
			}
		}
	}
	*/

	class Socket
	{
	public:
		Socket(ushort uPort);
		~Socket();

		bool isOpen() const;

		bool send(const Address& destination, const void* pData, int iSize);
		int receive(Address& sender, void* pData, int iSize);

	private:
		int m_iHandle;

	};
}
