#pragma once
#include "collable.h"
class obstacle :
	public collable
{
protected:
	float Color[3];
	

public:
	obstacle(float _Color[3],double pos[3], double rect) :collable(pos, rect)
	{
		memcpy(Color, _Color, sizeof(float) * 3);
	};
	virtual ~obstacle();
	bool check() override;
	virtual void draw();

};

