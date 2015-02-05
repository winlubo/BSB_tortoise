#pragma once
#include "includes.h"

enum infoType;

/*
* Class:		Actions	
* Descriprion:	sets off, and gets information about, action type of actions, e.g. fire, setNewFlags etc
* Public: 
* * fireAtShip, 
* * setNewFlag, 
* * isAFriend, 
* * setFiring,
* * getFireInfo
*/
class Actions
{
public:
	static void fireAtShip(int X, int Y);
	static void setNewFlag(int newFlag);
	bool isAFriend(int index);
	bool isFiring(void);
	void setFiring(bool fireBool);
	void setAllyFlag(int flag);
	int getFireInfo(infoType iType);
	bool headingTowardsShip(int destX, int destY);
};

