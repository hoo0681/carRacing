#pragma once
#include "BaseObject.h"
class CarBase : public BaseObject
{
protected:
	unsigned int HP;
	float* Color; //����
	double* Coord; //��ġ
	double Spd;      //��ǥ �ӵ� (�浹� ���� ������ ��� ��ǥġ���� �ٽ� ������ ����X)
	double angle;	 //�̵�����
	double mass;	//����
	double Rcet = 24.0;   //����ũ��
public:
	virtual void move() = 0;
	virtual void checkCondition() = 0;
	virtual void draw() = 0;
	
	virtual void collision(CarBase& a) = 0;//�浹�� ���º�ȭ ���
	

	unsigned int getHP()
	{
		return HP;
	}
};
