#include "playerCar.h"


playerCar::~playerCar()
{
}

void playerCar::start()
{
}

void playerCar::update()
{
	this->move();
}

bool playerCar::check()
{
	return this->checkCondition();
}
//
void playerCar::move()
{
}

bool playerCar::checkCondition()
{
	int HP = getHP();
	if (HP <= 0)
	{
		setEnabled(false);
		return false;
	}
	else if ((Coord[0] <= Rect + 1 || Coord[0] >= 600/*width*/ - Rect - 1)) {		//왼쪽 or 오른쪽 충돌
		return false;
	}
	else return true;
}


void playerCar::moveDelta(double a[3])
{
	for (int t = 0; t < 3; t++) {
		this->Coord[t] += a[t]*Spd;
	}
	
}
