#include "echoServer.h"

SocketTCP::SocketTCP() : Sockets(PF_INET, SOCK_STREAM, IPPROTO_TCP, 2504, "0"), thread_( &SocketTCP::workServer, this){}

SocketTCP::SocketTCP(int domain, int type, int protocol, unsigned short int port) : Sockets(domain, type, protocol, port, "0"), thread_( &SocketTCP::workServer, this){}

void SocketTCP::start(){
	thread_.join();
}


void SocketTCP::workServer(){
	createSocket();
	bindSocket();
	listenSocket();
	cout << "TCP listen..." << endl;
	while(1){
		acceptSocket();
		dataReceive(getConnFD(), "TCP");
		procOfData(getData(), getBytesRec());
		dataSend(getConnFD(), getData());
		shutdownSocket(getConnFD());
	}
}

SocketUDP::SocketUDP() : Sockets(PF_INET, SOCK_DGRAM, IPPROTO_UDP, 7654, "0"), thread_( &SocketUDP::workServer, this){}
SocketUDP::SocketUDP(int domain, int type, int protocol, unsigned short int port) : Sockets(domain, type, protocol, port, "0"), thread_( &SocketUDP::workServer, this){}

void SocketUDP::start(){
	thread_.join();
}

void SocketUDP::workServer(){
	createSocket();
	bindSocket();
	cout << "UDP listen..." << endl;
	while(1){
		dataReceive(getSockFD(), "UDP");
		procOfData(getData(), getBytesRec());
		dataSend(getSockFD(), getData());
	}
}
