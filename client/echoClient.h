#include "sockets.h"

class ClientTCP: public Sockets {
	public:
		ClientTCP();
		ClientTCP(int domain, int type, int protocol, unsigned short int port, char* s_addr);
		int workClientTCP();
};
class ClientUDP: public Sockets {
	public:
		ClientUDP();
		ClientUDP(int domain, int type, int protocol, unsigned short int port, char* s_addr);
		int workClientUDP();
};
