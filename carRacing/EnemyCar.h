#pragma once
#include "BaseCar.h"
class EnemyCar :
	public BaseCar
{
public:
	EnemyCar(int _HP, float _Color[3], double _Spd, double pos[3], double rect) :BaseCar(_HP, _Color, _Spd, pos, rect)
	{};
	~EnemyCar();

	
	void move() override;
	void start() override;
	void update() override;
	bool check() override;
};

