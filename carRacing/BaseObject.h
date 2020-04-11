#pragma once
#include "gl/glaux.h"
#include "gl/glut.h"
#include <cmath>
#define _USE_MATH_DEFINES
class BaseObject
{
protected:
	bool enable;
	
public:
	BaseObject();
	void setEnabled(bool set) { enable = set; }
	bool getEnabled() { return enable; }
	virtual ~BaseObject() {};
	virtual void start() = 0;
	virtual void update() = 0;
	//계속 존재 가능한지 여부반환
	virtual bool check() = 0; 
	virtual void draw() = 0;
};