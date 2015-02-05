#include "stdafx.h"
#include "Movement.h"

bool moveShip = false;
int moveX, moveY;
int destX, destY;

Movement::Movement(void)
{
}

void Movement::moveInDirection(int X, int Y)
{
	if (X < -2) X = -2;
	if (X >  2) X =  2;
	if (Y < -2) Y = -2;
	if (Y >  2) Y =  2;

	moveShip = true;
	moveX = X;
	moveY = Y;
}

bool Movement::getMovementStatus()
{
	return moveShip;
}

void Movement::setMovementStatus(bool moveBool)
{
	moveShip = moveBool;
}

int Movement::getMovementInfo(infoType infoType)
{
	switch (infoType)
	{
	case X:
		return moveX;
	case Y:
		return moveY;
	default:
		break;
	}
}

void Movement::runAway(int enemyShip)
{
	Onthology myself;
	Global universe;

	destX = universe.getShipInfo(X, enemyShip) / myself.geMyInfo(X);
	destY = universe.getShipInfo(Y, enemyShip) / myself.geMyInfo(Y);

	destX = (destX < 1 ? destX * 100 : destX);
	destY = (destY < 1 ? destY * 100 : destY);

	moveInDirection(destX, destY);
}