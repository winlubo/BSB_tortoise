// BattleshipBot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <winsock2.h>

#include "Tactics.h"
#include "ServerCom.h"

#pragma comment(lib, "wsock32.lib")


int _tmain(int argc, _TCHAR* argv[])
{	char chr = '\0';

	printf("\n");
	printf("Battleship Bots\n");
	printf("UWE Computer and Network Systems Assignment 2 (2014-15)\n");
	printf("\n");

	if (WSAStartup(MAKEWORD(2, 2), &data) != 0) return(0);

	ServerCom *comm = new ServerCom();

	closesocket(sock_send);
	closesocket(sock_recv);
	WSACleanup();

	while (chr != '\n')
	{
		chr = getchar();
	}

	return 0;
}

