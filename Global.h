#pragma once
#include "includes.h"
#include <math.h>

/*
* Class:		Global	
* Descriprion:	holding general information about ships
* Public: 
* * setShipInfo, 
* * getShipInfo, 
* * setNumberOfShips, 
* * getNumberOfShips
*/
class Global
{
public:
	Global(void);
	
	void setShipInfo(infoType infoType, int infoValue, int shipNumber);
	int getShipInfo(infoType infoType, int shipNumber);
	void setNumberOfShips(int nShips);
	int getNumberOfShips(void);
protected: 
	int number_of_ships;
	int shipNumber;
	float shipDistance[MAX_SHIPS];
	int shipX[MAX_SHIPS];
	int shipY[MAX_SHIPS];
	int shipHealth[MAX_SHIPS];
	int shipFlag[MAX_SHIPS];
};
