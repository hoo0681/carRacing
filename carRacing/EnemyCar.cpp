#include "EnemyCar.h"





EnemyCar::~EnemyCar()
{
}



void EnemyCar::move()
{
	this->Coord[1] += Spd;
}


void EnemyCar::start()
{
}

void EnemyCar::update()
{
	this->move();
}

bool EnemyCar::check()
{
	return this->checkCondition();
}
