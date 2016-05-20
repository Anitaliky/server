#include "Winsock2Funcs.h"

#define DEFAULT_PORT "8820"
void printException(Exception e);

void main()
{
	Winsock2Funcs winsock;

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	struct addrinfo* result;
	struct addrinfo hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

	SOCKET ListenSocket;
	try
	{
		ListenSocket = winsock.Socket();
		winsock.Bind(ListenSocket, result);
		freeaddrinfo(result);
		winsock.Listen(ListenSocket);
	}
	catch (Exception e)
	{
		printException(e);
	}
	
	while (true)
	{
		SOCKET ClientSocket;
		try
		{
			ClientSocket = winsock.Accept(ListenSocket);
		}
		catch (Exception e)
		{
			printException(e);
		}
		std::cout << "Client connected!" << std::endl;
	}
	try
	{
		winsock.Closesocket(ListenSocket);
	}
	catch (Exception e)
	{
		printException(e);
	}
	WSACleanup();
	system("pause");
}

//this function is called in 'catch' in the try-catch block
void printException(Exception e)
{
	std::cout << e.what() << std::endl;
	WSACleanup();
	system("pause");
}