#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;

class Sockets{
	public:
		Sockets();
		Sockets(int domain, int type, int protocol, unsigned short int port, char *);
		virtual ~Sockets(){
			close(sockFD_);
		}
		int createSocket();
		int bindSocket();
		int listenSocket();
		int acceptSocket();
		int connectSocket();
		int shutdownSocket(int fd);		

		int getDomain();
		int getType();
		int getProtocol();
		unsigned short int getPort();
		int getSockFD();
		int getConnFD();
		char * getData();
		const struct sockaddr_in * getSAddr();
		int getBytesRec();

		int dataReceive(int fd, string mark);
		int dataSend(int fd, char* data);
		int procOfData(char *buf, int length);
	private:
		int domain_;
		int type_;
		int protocol_;
		unsigned short int port_;
		int sockFD_;
		struct sockaddr_in sAddr_;
		int connFD_;
		int bytesRec_;
		char data_[1024];
};

