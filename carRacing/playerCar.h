#pragma once
#include "BaseCar.h"
class playerCar :
	public BaseCar
{


public:
	playerCar(int _HP, float _Color[3], double _Spd, double pos[3], double rect) :BaseCar(_HP, _Color, _Spd, pos, rect)
	{};
	~playerCar();
	
	void start() override;
	void update() override;
	bool check() override;

	void move() override;
	bool checkCondition() override;
	void moveDelta(double a[3]);
};

