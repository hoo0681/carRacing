#include "BaseCar.h"
#include <iostream>





BaseCar::~BaseCar()
{
}
//계속 게임이 가능한지 상태확인
bool BaseCar::checkCondition()
{     
	int HP = getHP();
	if (HP <= 0)
	{
		setEnabled(false);
		return false;
	}
	
	return true;
}

void BaseCar::draw()
{
	//std::cout << Coord[0] <<Coord[1]<< Coord[2];
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //조명색
	GLfloat mat_shininess[] = { 127.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
	GLfloat light_position[] = { -0.5f, 0.5f, 0.5f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Color);//물질의재질
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
	glEnable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING); //조명을 켜는것
	glPushMatrix();//현재(기준) 위치 저장
	glTranslatef(Coord[0],Coord[1], Coord[2]);
	glutSolidSphere(Rect, 24, 24);//구 그리기
	glPopMatrix();//기준위치로 돌아옴
}

void BaseCar::collisionWith(collable* a)
{
	HP--;
	std::cout << this << " collide with " << a<<std::endl;
}
