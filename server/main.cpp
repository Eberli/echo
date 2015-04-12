#include "echoServer.h"

using namespace std;
 
void tr1()
{
	while(1){
     		cout << "tr1!" << endl;
		sleep(1);
	}
}

void tr2()
{
     while(1){
		sleep(1);	
		cout << "tr2!" << endl;
	}
}

int main()
{
	SocketTCP s1;
	SocketUDP s2(PF_INET, SOCK_DGRAM, IPPROTO_UDP, 7654);
     	//std::thread thr1(tr1);
	//std::thread thr2(tr2);
     	//thr1.join();
	//thr2.join();
	s1.start();
	s2.start();
     	return 0;
}
