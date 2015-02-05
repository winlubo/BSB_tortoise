#pragma once
#include "includes.h"

/*
* Class:		Tactics	
* Descriprion:	Class holding and executing different strategies
* Public: 
* * executeRule,
* Private:
* * rules, 
* * rule00, 
* * rule01,
* * bounceOfWalls,
* * friendRule
*/
class Tactics
{
public:
	Tactics(void);
	void executeRule(int ruleNumber);
private:
	void rules(void);
	void rule00(void);
	void rule01(void);
	void bounceOfWalls(void);
	void friendRule(int friendNumber);
};