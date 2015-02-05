#include "stdafx.h"
#include "Sort.h"


float shipDistance[MAX_SHIPS];

Sort::Sort(void)
{
}

/*
* Name:			fastSort
* Parameters:	array of ship distances in double
* Returns:		void
* Calls:		swapAllAttr(bool up, int i)
* Descriprion:	Fast sorting algorithm that sorts all in a single itteration 
*/
void Sort::fastSort()    ///need a pointer rather then a copy
{
	Global universe;
	int nShips = universe.getNumberOfShips();
	findAllDist();
	if(nShips != 0)
	{
		printf_s("Number of ships is: %d\n", nShips - 1);
		for (int i = 1; i < nShips; i++)
		{
			if (shipDistance[i] > shipDistance[i + 1])
			{
					swapAllAttr(true, i);
				if (shipDistance[i] < shipDistance[i -1])
				{
					swapAllAttr(false, i);
					i = i -2;
				}
			}
			else if (shipDistance[i] < shipDistance[i -1])
			{
					swapAllAttr(false, i);
					i = i -2;
			}
		}
	}
	for(int i = 1; i < nShips; i++)
	{
		if(shipDistance[i] == 0.0)
			continue;
		printf_s("Ship %d is %f units away.\n", i, shipDistance[i]);
	}
}

/*
* Name:			
* Parameters:	
* Returns:		
* Calls:		swapShips(float *ship1, float *ship2), swapShips(infoType attrToChange, int ship1, int ship2)
* Descriprion:	
*/
void Sort::swapAllAttr(bool up, int i)
{
	Global universe;
	swapShips(&shipDistance[i], &shipDistance[up ? (i + 1) : (i - 1)]);
	swapShips(infoType::X, universe.getShipInfo(X, i), universe.getShipInfo(X, (up ? (i + 1) : (i - 1)) ));
	swapShips(infoType::Y, universe.getShipInfo(Y, i), universe.getShipInfo(Y, (up ? (i + 1) : (i - 1)) ));
	swapShips(infoType::HEALTH, universe.getShipInfo(HEALTH, i), universe.getShipInfo(HEALTH, (up ? (i + 1) : (i - 1)) ));
	swapShips(infoType::FLAG, universe.getShipInfo(FLAG, i), universe.getShipInfo(FLAG, (up ? (i + 1) : (i - 1)) ));
}


void Sort::swapShips(float *ship1, float *ship2)
{
	float tempShip;

	// need to change all attributes not just distance
	if (*ship1 >= 0.0 && *ship2 >= 0.0)
	{
		tempShip = *ship1;
		*ship1 = *ship2;
		*ship2 = tempShip;
	}
}

void Sort::swapShips(infoType attrToChange, int ship1, int ship2)
{
	int tempShip;
	Global universe;

	// need to change all attributes not just distance
	if (ship1 >= 0 && ship2 >= 0)
	{
		switch (attrToChange)
		{
		case X:
			tempShip = universe.getShipInfo(X, ship1);
			universe.setShipInfo(X, universe.getShipInfo(X, ship2), ship1);
			universe.setShipInfo(X, tempShip, ship2);
			break;
		case Y:
			tempShip = universe.getShipInfo(Y, ship1);
			universe.setShipInfo(Y, universe.getShipInfo(Y, ship2), ship1);
			universe.setShipInfo(Y, tempShip, ship2);
			break;
		case HEALTH:
			tempShip = universe.getShipInfo(HEALTH, ship1);
			universe.setShipInfo(HEALTH, universe.getShipInfo(HEALTH, ship2), ship1);
			universe.setShipInfo(HEALTH, tempShip, ship2);
			break;
		case FLAG:
			tempShip = universe.getShipInfo(FLAG, ship1);
			universe.setShipInfo(FLAG, universe.getShipInfo(FLAG, ship2), ship1);
			universe.setShipInfo(FLAG, tempShip, ship2);
			break;
		default:
			break;
		}
	}
}

void Sort::findAllDist()
{
	Global universe;
	int nos = universe.getNumberOfShips();

	Onthology myself;
	for (int shipCount = 1; shipCount <= nos; shipCount++)
	{
		shipDistance[shipCount] = pow(	pow(((float)universe.getShipInfo(X, shipCount) - (float)myself.geMyInfo(X)), 2) + 
										pow(((float)universe.getShipInfo(Y, shipCount) - (float)myself.geMyInfo(Y)),2), 
										(float)0.5);
	}
}

float Sort::getDist(int shipN)
{
	if (shipN > 0)
		return shipDistance[shipN];
	else
		return 0;
}