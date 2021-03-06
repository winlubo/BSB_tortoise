#pragma once

#include <winsock2.h>
#include <vector>

#ifndef __DEFINITIONS_SET__
#define __DEFINITIONS_SET__


#define STUDENT_NUMBER		"    /|\n  /_|\n___|___\n\\__|__/"
#define STUDENT_FIRSTNAME	"Juraj"
#define STUDENT_FAMILYNAME	"Piar"

#define IP_ADDRESS_SERVER	"127.0.0.1"
//#define IP_ADDRESS_SERVER "164.11.80.27"
//#define IP_ADDRESS_SERVER "164.11.174.44"

#define PORT_SEND	 1924 // We define a port that we are going to use.
#define PORT_RECEIVE 1925 // We define a port that we are going to use.


#define MAX_BUFFER_SIZE	500
#define MAX_SHIPS		200

#define FIRING_RANGE	100

#define MOVE_LEFT		-1
#define MOVE_RIGHT		 1
#define MOVE_UP			 1
#define MOVE_DOWN		-1
#define MOVE_FAST		 2
#define MOVE_SLOW		 1

static char InputBuffer [MAX_BUFFER_SIZE];

static SOCKADDR_IN sendto_addr;
static SOCKADDR_IN receive_addr;

static SOCKET sock_send;  // This is our socket, it is the handle to the IO address to read/write packets
static SOCKET sock_recv;  // This is our socket, it is the handle to the IO address to read/write packets

static WSADATA data;

typedef enum infoType
{
	X, Y, HEALTH, FLAG, NEW_FLAG, NUMBER_OF_SHIPS, DISTANCE
} infoType;

typedef enum orientation
{
	S, SW, W, NW, N, NE, E, SE
} orientation;
#endif