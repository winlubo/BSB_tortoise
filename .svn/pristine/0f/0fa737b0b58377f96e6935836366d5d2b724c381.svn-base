#include "stdafx.h"
#include "Actions.h"

bool fire = false;
int fireX;
int fireY; 
int friendlyShip = 4;

/*
* Name:			isFiring
* Parameters:	void
* Returns:		bool fire
* Calls:		n/a
* Descriprion:	gets true/false state of fire variable.
*/
bool Actions::isFiring()
{
	return fire;
}

/*
* Name:			setFiring
* Parameters:	
* * bool fireBool
* Returns:		void
* Calls:		n/a
* Descriprion:	sets true/false state of fire variable.
*/
void Actions::setFiring(bool fireBool)
{
	fire = fireBool;
}

/*
* Name:			fireAtShip
* Parameters:	
* * int X, 
* * int Y
* Returns:		void
* Calls:		n/a
* Descriprion:	sets coordinates for to fire at and sets fire to true.
*/
void Actions::fireAtShip(int X, int Y)
{
	fire = true;
	fireX = X;
	fireY = Y;
}

/*
* Name:			getFireInfo
* Parameters:	
* * infoType iType {X, Y} 
* Returns:		int {fireX, fireY}
* Calls:		n/a
* Descriprion:	sets coordinates for to fire at and sets fire to true.
*/
int Actions::getFireInfo(infoType iType)
{
	switch (iType)
	{
	case X:
		return fireX;
	case Y:
		return fireY;
	default:
		return -1;
	}
}

/*
* Name:			isAFriend
* Parameters:	
* * int index - index number of the ship to check 
* Returns:		bool - true if friendly
* Calls:		Global::getShipInfo(FLAG, index);
* Descriprion:	Checks ships flag to decide friendliness of the ship
*/
bool Actions::isAFriend(int index)
{
	bool rc;

	rc = false;
	Global universe;
	if (universe.getShipInfo(FLAG, index)  == friendlyShip)
	{
		rc = true;  
	}

	return rc;
}

/*
* Name:			setAllyFlag
* Parameters:	
* * int flag - alliance flag
* Returns:		void
* Calls:		n/a
* Descriprion:	Sets friendlyShip flag.
*/
void Actions::setAllyFlag(int flag)
{
	friendlyShip = flag;
}

bool Actions::headingTowardsShip(int destX, int destY)
{
	Onthology myself;
	Global others;
	Movement destination;
	return true;
}