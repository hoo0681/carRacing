#include "GameScene.h"
#define COLLCK(X,Y,XR,YR) (((((X[0])-(Y[0]))*((X[0])-(Y[0])))+(((X[1])-(Y[1]))*((X[1])-(Y[1]))))<=(((XR)+(YR))*((XR)+(YR))))


GameScene::GameScene()
{
}


GameScene::~GameScene()
{
	std::vector<BaseObject*>::iterator Objiter = Objs.begin();
	std::vector<collable*>::iterator Colliter = Colls.begin();
	for (; Objiter != Objs.end(); ++Objiter)
	{
		delete(*Objiter);
	}
	for (; Colliter != Colls.end(); ++Colliter)
	{
		delete(*Colliter);
	}
	Objs.clear();
	Colls.clear();
	delete(tmp_p_p);
	std::cout << Objs.capacity()<<std::endl;
	std::cout << Colls.capacity() << std::endl;
}

void GameScene::init()
{
	double ball1[3] = { 350.0f,300.0f,0.0f };
	double ball2[3] = { 300.0f,330.0f,0.0f };
	double ball3[3] = { 300.0f,270.0f,0.0f };
	double ball4[3] = { 250.0f,350.0f,0.0f };
	double ball5[3] = { 250.0f,300.0f,0.0f };
	double ball6[3] = { 250.0f,250.0f,0.0f };
	double ball7[3] = { 300.0f,650.0f,0.0f };
	float cball1[3] = { 1.0f,0.0f,0.0f };
	float cball2[3] = { 0.0f,1.0f,0.0f };
	float cball3[3] = { 0.0f,0.0f,1.0f };
	float cball4[3] = { 1.0f,0.5f,0.0f };
	float cball5[3] = { 1.0f,1.0f,0.0f };
	float cball6[3] = { 1.0f,0.0f,1.0f };
	float cball7[3] = { 1.0f,1.0f,1.0f };
	tmp_p_p = new playerCar(10, cball7, 10, ball7, 24.0);
	Objs.push_back(tmp_p_p);
	Colls.push_back(tmp_p_p);
	EnemyCar* tmp_p_E = new EnemyCar(1, cball1, 1, ball1, 20.0);
	Objs.push_back(tmp_p_E);
	Colls.push_back(tmp_p_E);
}

void GameScene::Render()
{
	for (int i = 0; i < this->Objs.size(); i++) {
		if (this->Objs[i]->getEnabled())
		{
			this->Objs[i]->draw();
		}
	}
}

void GameScene::frameMove()
{
	coll();
	for (int i = 0; i < this->Objs.size(); i++) {
		if (!(this->Objs[i]->check()))
		{
			std::cout << "false" << std::endl;
			//Objs.erase(Objs.begin()+i);
		}
	}
	for (int i = 0; i < this->Objs.size(); i++) {
		if (this->Objs[i]->getEnabled())
		{
			this->Objs[i]->update();
		}
		
	}
}

void GameScene::coll()
{
	
	for (int i = 0; i < this->Colls.size(); i++)
	{
		if (!this->Colls[i]->getEnabled())continue;
		for (int j = 0; j < this->Colls.size(); j++)
		{
			if (j == i)continue;
			if (!this->Colls[j]->getEnabled())continue;
			if (COLLCK(this->Colls[i]->Coord, this->Colls[j]->Coord, this->Colls[i]->Rect, this->Colls[j]->Rect))
			{
				this->Colls[i]->collisionWith(this->Colls[j]);
			}
		}
	}
}

void GameScene::keyin(unsigned char key, int x, int y)
{
	double delat[3] = { 0.0,0.0,0.0 };
	switch (key)
	{
	case 'w':
		delat[1] = 1.0;
		break;
	case 's':
		delat[1] = -1.0;
		break;
	case 'a':
		delat[0] = -1.0;
		break;
	case 'd':
		delat[0] = 1.0;

		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	tmp_p_p->moveDelta(delat);
}
