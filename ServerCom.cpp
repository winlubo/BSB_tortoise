#include "stdafx.h"
#include "ServerCom.h"
#include <winsock2.h>

char buffer[4096];
int  len = sizeof(SOCKADDR);
char chr;
bool finished;
int  i, j;
int  rc;
char* p;

/*
* Name:			
* Parameters:	
* Returns:		
* Calls:		
* Descriprion:	 
*/
ServerCom::ServerCom(void)
{
	//sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  // Here we create our socket, which will be a UDP socket (SOCK_DGRAM).
	//if (!sock)
	//{	
	//	printf("Socket creation failed!\n"); 
	//}

	sock_send = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  // Here we create our socket, which will be a UDP socket (SOCK_DGRAM).
	if (!sock_send)
	{	
		printf("Socket creation failed!\n"); 
	}

	sock_recv = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  // Here we create our socket, which will be a UDP socket (SOCK_DGRAM).
	if (!sock_recv)
	{	
		printf("Socket creation failed!\n"); 
	}
	memset(&sendto_addr, 0, sizeof(SOCKADDR_IN));
	sendto_addr.sin_family = AF_INET;
	sendto_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS_SERVER);
	sendto_addr.sin_port = htons(PORT_SEND);

	memset(&receive_addr, 0, sizeof(SOCKADDR_IN));
	receive_addr.sin_family = AF_INET;
	//	receive_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS_SERVER);
	receive_addr.sin_addr.s_addr = INADDR_ANY;
	receive_addr.sin_port = htons(PORT_RECEIVE);

	int ret = bind(sock_recv, (SOCKADDR *)&receive_addr, sizeof(SOCKADDR));
	//	int ret = bind(sock_send, (SOCKADDR *)&receive_addr, sizeof(SOCKADDR));
	if (ret)
	{
		printf("Bind failed! %d\n", WSAGetLastError());  
	}

	sprintf_s(buffer, "Register  %s,%s,%s", STUDENT_NUMBER, STUDENT_FIRSTNAME, STUDENT_FAMILYNAME);
	sendto(sock_send, buffer, strlen(buffer), 0, (SOCKADDR *)&sendto_addr, sizeof(SOCKADDR));
	
	while (true)
	{
		if (recvfrom(sock_recv, buffer, sizeof(buffer)-1, 0, (SOCKADDR *)&receive_addr, &len) != SOCKET_ERROR)
		{
			p = ::inet_ntoa(receive_addr.sin_addr);

			if ((strcmp(IP_ADDRESS_SERVER, "127.0.0.1") == 0) || (strcmp(IP_ADDRESS_SERVER, p) == 0))
			{
				i = 0;
				j = 0;
				finished = false;
				Global universe;
				universe.setNumberOfShips(0);

				while ((!finished) && (i < 4096))
				{
					chr = buffer[i];

					switch (chr)
					{
					case '|':
						InputBuffer[j] = '\0';
						j = 0;
						retrieveShips();
						break;

					case '\0':
						InputBuffer[j] = '\0';
						retrieveShips();
						finished = true;
						break;

					default:
						InputBuffer[j] = chr;
						j++;
						break;
					}
					i++;
				}

				Tactics tac;
				tac.executeRule(1);
				Actions act;
				Movement mov;
				Onthology myself;

				if (act.isFiring())
				{
					sprintf_s(buffer, "Fire %s,%d,%d", STUDENT_NUMBER, act.getFireInfo(infoType::X), act.getFireInfo(infoType::Y));
					sendto(sock_send, buffer, strlen(buffer), 0, (SOCKADDR *)&sendto_addr, sizeof(SOCKADDR));
					act.setFiring(false);
				}

				if (mov.getMovementStatus())
				{
					sprintf_s(buffer, "Move %s,%d,%d", STUDENT_NUMBER, mov.getMovementInfo(X), mov.getMovementInfo(infoType::Y));
					rc = sendto(sock_send, buffer, strlen(buffer), 0, (SOCKADDR *)&sendto_addr, sizeof(SOCKADDR));
					mov.setMovementStatus(false);
				}

				if (myself.getSetFlagStatus())
				{
					sprintf_s(buffer, "Flag %s,%d", STUDENT_NUMBER, myself.geMyInfo(infoType::NEW_FLAG));
					sendto(sock_send, buffer, strlen(buffer), 0, (SOCKADDR *)&sendto_addr, sizeof(SOCKADDR));
					myself.setSetFlagStatus(false);
				}

			}
		}
		else
		{
			printf_s("recvfrom error = %d\n", WSAGetLastError());
		}
	}

	printf_s("Student %s\n", STUDENT_NUMBER);
}

/*
*Name:			
*Parameters:	
*Returns:		
*Calls:		
*Descriprion:	 
*/
void ServerCom::retrieveShips()
{
	Global universe;
	int shipX, shipY, shipHealth/*, shipFlag*/;
	sscanf_s(InputBuffer,"%d,%d,%d/*,%d*/", &shipX, 
										&shipY, 
										&shipHealth/*, 
										&shipFlag*/);
	universe.setShipInfo(infoType::X, shipX, universe.getNumberOfShips());
	universe.setShipInfo(infoType::Y, shipY, universe.getNumberOfShips());
	universe.setShipInfo(infoType::HEALTH, shipHealth, universe.getNumberOfShips());
	/*universe.setShipInfo(infoType::FLAG, shipFlag, universe.getNumberOfShips());*/

	universe.setNumberOfShips(universe.getNumberOfShips() + 1);
}
