#include "gl/glaux.h"
#include "gl/glut.h"
#include <cmath>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "GameScene.h"
#define HEIGHT 1000
#define	WIDTH 600

///초기화///
void init();
///opengl세팅///
void opglinit();
///그리기///
void drawDisp();
///입력함수///
void keyin(unsigned char key, int x, int y);
///map로더///
void mapLoader();
///장애물 생성기///
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
	glutCreateWindow("당구");		//윈도우 이름
	glMatrixMode(GL_PROJECTION);	// 투영 행렬 변환
	glLoadIdentity();	// 단위행렬 초기화
	glViewport(0, 0, WIDTH, HEIGHT);		//뷰포트 사이즈
	glOrtho(0.0, WIDTH, 0.0, HEIGHT, -100.0, 100.0);		//뷰포트에 대한 좌표적용 1000,600으로 해줌
}



void drawDisp()
{
	glClearColor(0.50, 0.3, 0.0, 0.12);	// 바닥색
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
	//for() 오브젝트 이동함수
	tmp.coll();
	tmp.frameMove();
	//오브젝트 충돌 확인등 상태 확인
	hurdle_gen(); //장애물 생성
	glutPostRedisplay();//glutDisplayFunc에 등록된 함수가 실행된다.
	glutTimerFunc(1, loop_, 1);
}