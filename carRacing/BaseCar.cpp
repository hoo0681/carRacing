#include "BaseCar.h"
#include <iostream>





BaseCar::~BaseCar()
{
}
//��� ������ �������� ����Ȯ��
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
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //�����
	GLfloat mat_shininess[] = { 127.0 }; // �ݻ�Ǿ� ��ġ�� ���� ���ݻ����� ������� ����, ���õ��ö�ƽ��
	GLfloat light_position[] = { -0.5f, 0.5f, 0.5f, 0.0f }; // �������� 0.0�� ������ǥ��(2�̸� 1.0 1.0 1.0�� ���� 0.5���ȴ�)
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //����������
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//����������
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Color);//����������
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);//������ Ư�� GL_LIGHT0�� 0���� 7���� ��밡��
	glEnable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING); //������ �Ѵ°�
	glPushMatrix();//����(����) ��ġ ����
	glTranslatef(Coord[0],Coord[1], Coord[2]);
	glutSolidSphere(Rect, 24, 24);//�� �׸���
	glPopMatrix();//������ġ�� ���ƿ�
}

void BaseCar::collisionWith(collable* a)
{
	HP--;
	std::cout << this << " collide with " << a<<std::endl;
}
