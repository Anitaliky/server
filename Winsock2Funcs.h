#ifndef WIN_SOCK2_H
#define WIN_SOCK2_H
#pragma comment (lib,"ws2_32.lib")
#include<WinSock2.h>
#include<Windows.h>
#include<ws2tcpip.h>
#include<iostream>
#include<thread>
#include<exception>
#include<string>

#define DEFAULT_PORT "8820"

class Winsock2Funcs
{
public:
	SOCKET Socket() throw(...);
	void Bind(SOCKET, struct addrinfo*) throw(...);
	void Listen(SOCKET) throw(...);
	SOCKET Accept(SOCKET) throw(...);
	void Closesocket(SOCKET) throw(...);

	SOCKET getListenSocket();
	SOCKET getClientSocket();

};

#endif