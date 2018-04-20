#include <iostream>
#include <Arkanoid/Arkanoid.h>

#include <Engine/Network/Address.h>
#include <Engine/Network/Socket.h>

using namespace std;
using namespace network;

int main(int argc, char** argv)
{
	Address a1;
	cout << a1.getA() << "." << a1.getB() << "." << a1.getC() << "." << a1.getD() << ":" << a1.getPort() << endl;
	Address a2(28374, 5);
	cout << a2.getA() << "." << a2.getB() << "." << a2.getC() << "." << a2.getD() << ":" << a2.getPort() << endl;
	Address a3(127, 0, 0, 1, 3500);
	cout << a3.getA() << "." << a3.getB() << "." << a3.getC() << "." << a3.getD() << ":" << a3.getPort() << endl;

	Arkanoid arkanoid;
	arkanoid.start();

	return 0;
}

