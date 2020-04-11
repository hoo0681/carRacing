#pragma once
#include "BaseObject.h"
class collable :
	public BaseObject
{
public:
	double Coord[3];
	double Rect = 24.0;
public:
	collable(double pos[3], double rect) : BaseObject()
	{
		memcpy(this->Coord, pos, sizeof(double)*3);
		Rect = rect;
	}
	virtual ~collable() {};
	virtual void collisionWith(collable* a) = 0;
};

