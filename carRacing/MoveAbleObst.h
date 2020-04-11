#pragma once
#include "obstacle.h"
class MoveAbleObst :
	public obstacle
{
protected: 
	double Spd;
	int heading;//-1 or 1 аб/©Л
public:
	MoveAbleObst(double _Spd,int _heading,float _Color[3], double pos[3], double rect) \
		: obstacle(_Color, pos, rect)
	{
		Spd = _Spd;
		heading = _heading;
	};
	~MoveAbleObst();

	virtual void move();

	void start() override;
	void update() override;
	bool check() override;
};

