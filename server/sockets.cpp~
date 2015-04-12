#include "sockets.h"

bool isNotDigit(char symbol){
	int dig = static_cast<int>(symbol) - 48;
	return (dig < 0 || dig > 9);
}

bool comp(int a, int b){
	return (a > b) ? true : false;
}

Sockets::Sockets(): domain_(PF_INET), type_(SOCK_STREAM), protocol_(IPPROTO_TCP), port_(2504), sockFD_(-1), bytesRec_(0){
	memset(&sAddr_, 0, sizeof(sAddr_));
	sAddr_.sin_family = domain_;
	sAddr_.sin_port = htons(port_);
	sAddr_.sin_addr.s_addr = inet_addr("0");
}

Sockets::Sockets(int domain, int type, int protocol, unsigned short int port, char * s_addr): domain_(domain), type_(type), protocol_(protocol), port_(port), sockFD_(-1), bytesRec_(0){
	memset(&sAddr_, 0, sizeof(sAddr_));
	sAddr_.sin_family = domain_;
	sAddr_.sin_port = htons(port_);
	sAddr_.sin_addr.s_addr = inet_addr(s_addr);
}

int Sockets::createSocket(){
	sockFD_ = socket(domain_, type_, protocol_);
	if (-1 == sockFD_){
		perror("I can\'t create a socket!");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Sockets::bindSocket(){
	//связывание сокета с адресом.
	if (-1 == bind(sockFD_, (struct sockaddr *) &sAddr_, sizeof(sAddr_))){
		perror("I can\'t bind a socket!");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Sockets::listenSocket(){
	if (-1 == listen(sockFD_, 10)){
		perror("I can\'t listen a socket!");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Sockets::acceptSocket(){
	connFD_ = accept(sockFD_, NULL, NULL);
	if(-1 == connFD_){
		perror("I can\'t accept a socket!");
		exit(EXIT_FAILURE);
	}
	return 0;	
}

int Sockets::connectSocket(){
	if (-1 == connect(sockFD_, (struct sockaddr *) &sAddr_, sizeof(sAddr_))){
		perror("I can\'t connect a socket!");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Sockets::shutdownSocket(int fd){
	if(-1 == shutdown(fd, SHUT_RDWR)){
		perror("I can\'t shutdown a socket!");
		close(connFD_);
		exit(EXIT_FAILURE);
	}
	close(connFD_);
	return 0;
}

int Sockets::getType(){
	return type_;
}

int Sockets::getProtocol(){
	return protocol_;
}

unsigned short int Sockets::getPort(){
	return port_;
}

int Sockets::getSockFD(){
	return sockFD_;
}

int Sockets::getConnFD(){
	return connFD_;
}

const struct sockaddr_in * Sockets::getSAddr(){
	return &sAddr_;
}

char * Sockets::getData(){
	return data_;
}

int Sockets::getBytesRec(){
	return bytesRec_;
}

int Sockets::dataReceive(int fd, string mark){
	memset(data_, NULL, sizeof(data_));
	socklen_t fromlen = sizeof(*getSAddr()); 
	
	bytesRec_ = recvfrom(fd, (void *) data_, sizeof(data_), 0, (struct sockaddr *) getSAddr(), &fromlen);
	if (bytesRec_ < 0){
		printf("I\'m here!");
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	cout << "//////////////////////////////////" << endl;
	cout << mark << ": " << endl;
	cout << "bytesRec: " << bytesRec_ << endl;
	sleep(1);
	cout << "datagram: " << data_ << endl;
	return 0;
}

int Sockets::dataSend(int fd, char * data){
	int bytesSent = sendto(fd, data, strlen(data), 0, (struct sockaddr *) getSAddr(), sizeof(*getSAddr())); 
	if (bytesSent < 0) {
		printf("Error sending packet: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return 0;
}

int Sockets::procOfData(char* buf, int length){
	vector<char> v;
	//запишем принятые данные в вектор символов.
	for (int i = 0; i < length; i++){
		v.push_back(buf[i]);
	}
	//выберем только цифры.	
	v.erase(remove_if(v.begin(), v.end(), isNotDigit), v.end());
	//преобразуем в числа.
	vector<int> digit;
	for(int i = 0; i < v.size(); i++){
		digit.push_back(static_cast<int>(v[i]) - 48);
	}
	//Найдём сумму.
	int summa = accumulate(digit.begin(), digit.end(), 0);
	cout << "Сумма цифр: " << summa << endl;
	//вывод в порядке убывания.
	sort(digit.begin(), digit.end(), comp);
	cout << "Цифры по убыванию: ";
	for (int i = 0; i < digit.size(); i++){
		cout<< digit[i];
	}
	cout << endl;
	//максимальное значение.
	vector<int>::iterator iter;
	iter = max_element(digit.begin(), digit.end());
	cout << "Максимальное значение: " << *iter << endl;
	//минимальное значение.
	iter = min_element(digit.begin(), digit.end());
	cout << "Минимальное значение: " << *iter << endl;	
}

