#include "sockets.h"

class SocketTCP: public Sockets{
	public:
		SocketTCP();
		SocketTCP(int domain, int type, int protocol, unsigned short int port);
		void workServer();
		void start();
	private:
		std::thread thread_;
};

class SocketUDP: public Sockets{
	public:
		SocketUDP();
		SocketUDP(int domain, int type, int protocol, unsigned short int port);
		void workServer();
		void start();
	private:
		std::thread thread_;
};
