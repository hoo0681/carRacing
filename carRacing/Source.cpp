#include "gl/glaux.h"
#include "gl/glut.h"
#include <cmath>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "GameScene.h"
#define HEIGHT 1000
#define	WIDTH 600

///�ʱ�ȭ///
void init();
///opengl����///
void opglinit();
///�׸���///
void drawDisp();
///�Է��Լ�///
void keyin(unsigned char key, int x, int y);
///map�δ�///
void mapLoader();
///��ֹ� ������///
void hurdle_gen();
///loop///
void loop_(int value);
///saver///
void saver();
///loader///
void hisloader();
GameScene tmp;
int main(int argc, char** argv)
{
	
	tmp.init();
	glutInit(&argc, argv);
	init();
	opglinit();
	glutKeyboardFunc(keyin);
	glutDisplayFunc(drawDisp);
	glutTimerFunc(1, loop_, 1);
	glutMainLoop();
	return 0;
}

void init()
{
}

void opglinit()
{	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("�籸");		//������ �̸�
	glMatrixMode(GL_PROJECTION);	// ���� ��� ��ȯ
	glLoadIdentity();	// ������� �ʱ�ȭ
	glViewport(0, 0, WIDTH, HEIGHT);		//����Ʈ ������
	glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);		//����Ʈ�� ���� ��ǥ���� 1000,600���� ����
}



void drawDisp()
{
	glClearColor(0.50, 0.3, 0.0, 0.12);	// �ٴڻ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	tmp.Render();
	
	glutSwapBuffers();
}

void keyin(unsigned char key, int x, int y)
{
	tmp.keyin(key, x, y);
}


void hurdle_gen()
{

}

void loop_(int value)
{
	//for() ������Ʈ �̵��Լ�
	tmp.coll();
	tmp.frameMove();
	//������Ʈ �浹 Ȯ�ε� ���� Ȯ��
	hurdle_gen(); //��ֹ� ����
	glutPostRedisplay();//glutDisplayFunc�� ��ϵ� �Լ��� ����ȴ�.
	glutTimerFunc(1, loop_, 1);
}