#include "stdafx.h"
#include "Tactics.h"

int up_down = MOVE_LEFT*MOVE_SLOW;
int left_right = MOVE_UP*MOVE_FAST;

int shipDistance[MAX_SHIPS];

int number_of_friends;
int friendX[MAX_SHIPS];
int friendY[MAX_SHIPS];
int friendHealth[MAX_SHIPS];
int friendFlag[MAX_SHIPS];
int friendDistance[MAX_SHIPS];

int number_of_enemies;
int enemyX[MAX_SHIPS];
int enemyY[MAX_SHIPS];
int enemyHealth[MAX_SHIPS];
int enemyFlag[MAX_SHIPS];
int enemyDistance[MAX_SHIPS];


/*
* Name:			
* Parameters:	
* Returns:		
* Calls:		
* Descriprion:	 
*/
Tactics::Tactics(void)
{
}

/*
* Name:			rules
* Parameters:	void
* Returns:		void
* Calls:		n/a
* Descriprion:	gets true/false state of fire variable.
*/
void Tactics::rules(void)
{
}

/*
* Name:			executeRule
* Parameters:	
* * int ruleNumber
* Returns:		void
* Calls:		ruleXX(), where XX is rule number 
* Descriprion:	executes the rule given
*/
void Tactics::executeRule(int ruleNumber)
{
	switch (ruleNumber)
	{
	case 01:
		rule01();
		break;
	default:
		rule00();
		break;
	}
}

/*
* Name:			
* Parameters:	
* Returns:		
* Calls:		
* Descriprion:	 
*/
void Tactics::rule00(void)
{
	Global universealInfo;
	Actions action;

	bounceOfWalls();
	if (universealInfo.getNumberOfShips() > 1)
	{
		for (int i = 1; i < universealInfo.getNumberOfShips(); i++)
		{
			number_of_friends = 0;
			number_of_enemies = 0;

			if (action.isAFriend(i))
			{
				friendX[number_of_friends] =  universealInfo.getShipInfo(infoType::X, i);
				friendY[number_of_friends] = universealInfo.getShipInfo(infoType::Y, i);
				friendHealth[number_of_friends] = universealInfo.getShipInfo(infoType::HEALTH, i);
				friendFlag[number_of_friends] = universealInfo.getShipInfo(infoType::FLAG, i);
				friendDistance[number_of_friends] = shipDistance[i];		
				number_of_friends++;
			}
			else
			{
				enemyX[number_of_enemies] = universealInfo.getShipInfo(infoType::X, i);
				enemyY[number_of_enemies] = universealInfo.getShipInfo(infoType::Y, i);
				enemyHealth[number_of_enemies] = universealInfo.getShipInfo(infoType::HEALTH, i);
				enemyFlag[number_of_enemies] = universealInfo.getShipInfo(infoType::FLAG, i);
				enemyDistance[number_of_enemies] = shipDistance[i];		
				number_of_enemies++;
			}
		}

		if (number_of_enemies > 0)
		{
			Actions::fireAtShip(enemyX[0], enemyY[0]);
		}
	}

	Movement::moveInDirection(left_right, up_down);
 

	//if (number_of_ships > 1)
	//{
	//	fireAtShip(shipX[1], shipY[1]);
	//}
}

/*
* Name:			
* Parameters:	
* Returns:		
* Calls:		
* Descriprion:	 
*/
void Tactics::rule01(void)
{
	Sort sort;
	Global universe;
	Onthology myself;
	Movement move;
	int nShips = universe.getNumberOfShips();
	sort.fastSort();
	
	if (nShips > 0)
	{
		//First ship in sight:
		//if ( universe.getShipInfo(FLAG, 1) != myself.geMyInfo(FLAG)) //if an enemy
		printf_s("Enemy flag: %d and mine: \n", universe.getShipInfo(FLAG, 1));
			if (sort.getDist(1) <= 101) 
			{
				if (universe.getShipInfo(HEALTH, 1) > 5  && myself.geMyInfo(HEALTH) <= 5) // if enemy healthier then me => runaway & shoot
				{
					
					move.runAway(1);
					Actions::fireAtShip(universe.getShipInfo(X, 1), universe.getShipInfo(Y, 1));
				}
				else //shoot & approach
				{
					Actions::fireAtShip(universe.getShipInfo(X, 1), universe.getShipInfo(Y, 1));
					Movement::moveInDirection(universe.getShipInfo(X, 1), universe.getShipInfo(Y, 1));
				}
			}/*
			else if
			{

			}
		else
		{

		}*/
	}
}

/*
* Name:			
* Parameters:	
* Returns:		
* Calls:		
* Descriprion:	 
*/
void Tactics::bounceOfWalls()
{
	Onthology myself;
	if (myself.geMyInfo(infoType::Y) > 900) 
	{
		up_down = MOVE_DOWN*MOVE_SLOW;
	}

	if (myself.geMyInfo(infoType::X) < 200)
	{
		left_right = MOVE_RIGHT*MOVE_FAST;
	}

	if (myself.geMyInfo(infoType::Y) < 100)
	{
		up_down = MOVE_UP*MOVE_FAST;
	}

	if (myself.geMyInfo(infoType::X) > 800)
	{
		left_right = MOVE_LEFT*MOVE_SLOW;
	}
}

/*
* Name:			friendRule
* Parameters:	Order number of the ally in friend list (as in friendDistance)
* Returns:		void
* Calls:		n/a
* Descriprion:	Creates a rule to prevent false ally/betraeyal. 
*/
void Tactics::friendRule(int friendNumber)
{
	if (friendDistance[friendNumber] <= 102 && friendDistance[friendNumber] >= 100)
	{

	}
}