#include "Winsock2Funcs.h"

SOCKET Winsock2Funcs::Socket()
{
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
		throw exception("socket failed");
	return s;
}

void Winsock2Funcs::Bind(SOCKET s, struct addrinfo* a)
{
	if (bind(s, a->ai_addr, (int)a->ai_addrlen) == SOCKET_ERROR)
		throw exception("socket binding failed");
}

void Winsock2Funcs::Listen(SOCKET s)
{
	if (listen(s, SOMAXCONN) == SOCKET_ERROR)
		throw exception("socket listening failed");
}

SOCKET Winsock2Funcs::Accept(SOCKET listenSocket)
{
	SOCKADDR_IN sockServ;
	int sockServLen = sizeof(sockServ);
	SOCKET clientSocket = accept(listenSocket, (SOCKADDR*)&sockServ, &sockServLen);
	if (clientSocket == INVALID_SOCKET)
	{
		Closesocket(clientSocket);
		throw exception("socket accept failed");
	}
	return clientSocket;
}

void Winsock2Funcs::Closesocket(SOCKET soc)
{
	if (closesocket(soc) == SOCKET_ERROR)
		throw exception("close socket failed");
}