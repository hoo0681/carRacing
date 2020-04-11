#pragma once
#include "obstacle.h"
class Immovable :
	public obstacle
{
public:
	Immovable(float _Color[3], double pos[3], double rect) :obstacle(_Color, pos, rect)
	{};
	~Immovable();
	void start() override;
	void update() override;
	

};

