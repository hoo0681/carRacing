#include "MoveAbleObst.h"





MoveAbleObst::~MoveAbleObst()
{

}

void MoveAbleObst::move()
{
	Coord[0] += heading * Spd;
}

void MoveAbleObst::start()
{

}

void MoveAbleObst::update()
{
	this->move();
}

bool MoveAbleObst::check()
{
	if (Coord[0] <= Rect + 1 || Coord[0] >= 600/*width*/ - Rect - 1) {		//왼쪽 or 오른쪽 충돌
		return false;
	}
	else return true;
}
