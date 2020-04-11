#pragma once
#include "collable.h"
class BaseCar :
	public collable
{
protected:
	int HP;
	float Color[3];
	double Spd; //0>spd =>down , 0<spd =>up
	//double angle;
	//double mass;
	//double Fric;
public:

	BaseCar(int _HP, float _Color[3], double _Spd, double pos[3], double rect) :collable(pos, rect)
	{
		HP = _HP;
		memcpy(Color, _Color, sizeof(double) * 3);
		Spd = _Spd;
	};
	virtual ~BaseCar();
	
	virtual bool checkCondition();
	virtual void move() = 0;
	virtual void draw();

	void collisionWith(collable* a) override;

	int getHP() {
		return HP;
	}
};

