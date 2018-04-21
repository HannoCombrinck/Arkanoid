#include <iostream>
#include <Arkanoid/Arkanoid.h>

#include <Engine/Network/Socket.h>
#include <Engine/Network/Address.h>
using namespace network;

using namespace std;

void testSocket()
{
	Socket socket;
	auto iRes = socket.open(3001);
	if (!iRes)
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

int main(int argc, char** argv)
{
	testSocket();

	Arkanoid arkanoid;
	arkanoid.start();

	return 0;
}

