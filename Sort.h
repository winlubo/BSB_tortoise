#pragma once
#include "includes.h"

/*
*
*/
class Sort // : public Global
{
public:
	Sort(void);
	void fastSort();
	float getDist(int shipN);

private:
	void swapAllAttr(bool up, int i);
	void swapShips(float *ship1, float *ship2);
	void swapShips(infoType attrToChange, int ship1, int ship2);
	void findAllDist(void);
};

