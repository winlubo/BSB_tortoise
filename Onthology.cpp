#include "stdafx.h"
#include "Onthology.h"

int myX;
int myY;
int myHealth;
int myFlag;

bool setFlag = true;
int new_flag = 4;

/*
*
*
*/
int Onthology::geMyInfo(infoType infoType)
{
	switch (infoType)
	{
	case X:
		return myX;
	case Y:
		return myY;
	case HEALTH:
		return myHealth;
	case FLAG:
		return myFlag;
	case NEW_FLAG:
		return new_flag;
	default:
		printf_s("This information does not exist in ");
		return -1;
	}
}

bool Onthology::getSetFlagStatus()
{
	return setFlag;
}

void Onthology::setSetFlagStatus(bool status)
{
	setFlag = status;
}

void Onthology::setMyInfo(infoType infoType, int toSet)
{
	switch (infoType)
	{
	case X:
		myX = toSet;
		break;
	case Y:
		myY = toSet;
		break;
	case HEALTH:
		myHealth = toSet;
		break;
	case FLAG:
		setFlag = true;
		new_flag = toSet;
		break;
	case NEW_FLAG:
		new_flag = toSet;
		break;
	default:
		printf_s("This information does not exist in ");
		break;
	}
}
