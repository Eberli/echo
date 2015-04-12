#include "echoClient.h"

int main(void){
	string proto = "";
	ClientTCP c1(PF_INET, SOCK_STREAM, IPPROTO_TCP, 2504, "127.0.0.1");
	ClientUDP c2(PF_INET, SOCK_DGRAM, IPPROTO_UDP, 7654, "127.0.0.1");
	cout << "Каким протоколом будем пользоваться tcp или udp?" << endl;
	cin >> proto;
	if (proto == "tcp") 
					c1.workClientTCP();
	else if (proto == "udp") 
					c2.workClientUDP();
	else {
		cout << "Данные введены неверно!" << endl;
	}
	return 0;
}
