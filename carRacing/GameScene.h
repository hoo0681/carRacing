#pragma once
#include "MoveAbleObst.h"
#include "Immovable.h"
#include "EnemyCar.h"
#include "playerCar.h"
#include <vector>
#include <iostream>
class GameScene
{
public:
	GameScene();
	~GameScene();
	void init();
	void Render();
	void frameMove();
	void coll();
	void keyin(unsigned char key, int x, int y);
private:
	std::vector<BaseObject*> Objs;
	std::vector<collable*> Colls;
	playerCar* tmp_p_p;
};

