#include "stdafx.h"
#include "Global.h"

int number_of_ships;
int shipNumber;

int shipX[MAX_SHIPS];
int shipY[MAX_SHIPS];
int shipHealth[MAX_SHIPS];
int shipFlag[MAX_SHIPS];

Global::Global(void)
{
}

/*
* Name:			setShipInfo
* Parameters:	
* * infoType infoType {X, Y, HEALTH, FLAG}, 
* * int infoValue, 
* * int shipNumber - range (0, number_of_ships),
* Returns:		void
* Calls:		Onthology::setMyInfo(infoType infoType, int infoValue);
* Descriprion:	sets information about ships, including values: X, Y, HEALTH and FLAG.
*/
void Global::setShipInfo(infoType infoType, int infoValue, int shipNumber)
{
	Onthology myself;
	if (shipNumber >= 0 && shipNumber <= number_of_ships)
	switch (infoType)
	{
	case X:
		shipNumber == 0 ? myself.setMyInfo(X, infoValue) :  false; 
		shipX[shipNumber] = infoValue;
		break;
	case Y:
		shipNumber == 0 ? myself.setMyInfo(Y, infoValue) :  false; 
		shipY[shipNumber] = infoValue;
		break;
	case HEALTH:
		shipNumber == 0 ? myself.setMyInfo(HEALTH, infoValue) :  false; 
		shipHealth[shipNumber] = infoValue;
		break;
	case FLAG:
		shipNumber == 0 ? myself.setMyInfo(FLAG, infoValue) :  false; 
		shipFlag[shipNumber] = infoValue;
		break;
	default:
		printf_s("out of scope");
		break;
	}
}

/*
* Name:			getShipInfo
* Parameters:	
* * infoType infoType {X, Y, HEALTH, FLAG}, 
* * int shipNumber - range (0, number_of_ships),
* Returns:		int {shipX, shipY, shipHealth, shipFlag}
* Calls:		n/a
* Descriprion:	gets information about ships, including values: X, Y, HEALTH and FLAG.
*/
int Global::getShipInfo(infoType infoType, int shipNumber)
{
	switch (infoType)
	{
	case X:
		return shipX[shipNumber];
	case Y:
		return shipY[shipNumber];
	case HEALTH:
		return shipHealth[shipNumber];
	case FLAG:
		return shipFlag[shipNumber];
	default:
		printf_s("out of scope");
		return -1000;
	}
}

/*
* Name:			setNumberOfShips
* Parameters:	
* * int nShips - range (0, MAX_SHIPS),
* Returns:		void
* Calls:		n/a
* Descriprion:	sets number of ships
*/
void Global::setNumberOfShips(int nShips)
{
	if (nShips >= 0)
	{
		number_of_ships = nShips;
	}
}

/*
* Name:			getNumberOfShips
* Parameters:	void
* Returns:		int number_of_ships
* Calls:		n/a
* Descriprion:	sets number of ships
*/
int Global::getNumberOfShips()
{
	return number_of_ships;
}
