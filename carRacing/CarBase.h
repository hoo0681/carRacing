#pragma once
#include "BaseObject.h"
class CarBase : public BaseObject
{
protected:
	unsigned int HP;
	float* Color; //색깔
	double* Coord; //위치
	double Spd;      //목표 속도 (충돌등에 의해 감소할 경우 목표치까지 다시 가속함 구현X)
	double angle;	 //이동각도
	double mass;	//무게
	double Rcet = 24.0;   //구슬크기
public:
	virtual void move() = 0;
	virtual void checkCondition() = 0;
	virtual void draw() = 0;
	
	virtual void collision(CarBase& a) = 0;//충돌시 상태변화 계산
	

	unsigned int getHP()
	{
		return HP;
	}
};
