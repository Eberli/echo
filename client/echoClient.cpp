#include "echoClient.h"

ClientTCP::ClientTCP() : Sockets(){}

ClientTCP::ClientTCP(int domain, int type, int protocol, unsigned short int port, char * s_addr) : Sockets(domain, type, protocol, port, s_addr){}

int ClientTCP::workClientTCP(){
	string check = "";
	bool flag = true;
	while(flag){
		createSocket();
		connectSocket();
		string data = "";
		cout << "Введите данные, для завершения ввода введите '$': ";
		getline(cin, data, '$');
		char* buffer = new char[data.length()];
    		strcpy(buffer, data.c_str());dataSend(getSockFD(), buffer);
		dataReceive(getSockFD(), "TCP");
		cout << "Продолжить отправку сообщений? (yes/no): " << endl;
		cin >> check;
		if (check == "no") {
			flag = false;
			delete [] buffer;
			shutdownSocket(getSockFD());
			close(getSockFD());
		}
	}
	return 0;
}

ClientUDP::ClientUDP() : Sockets(){}

ClientUDP::ClientUDP(int domain, int type, int protocol, unsigned short int port, char * s_addr) : Sockets(domain, type, protocol, port, s_addr){}

int ClientUDP::workClientUDP(){
	createSocket();
	string check = "";
	bool flag = true;
	while(flag){
		string data = "";
		cout << "Введите данные, для завершения ввода введите '$': ";
		getline(cin, data, '$');
		char* buffer = new char[data.length()];
    		strcpy(buffer, data.c_str());
		dataSend(getSockFD(), buffer);
		dataReceive(getSockFD(), "UDP");
		cout << "Продолжить отправку сообщений? (yes/no): " << endl;
		cin >> check;
		if (check == "no") {
			delete [] buffer;
			flag = false;
		}
	}
	return 0;
}
