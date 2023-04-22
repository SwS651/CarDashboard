#include "Symbol.h"
Symbol::Symbol(){}
Symbol::~Symbol(){}
void Symbol::setTheme(GLfloat r,GLfloat g,GLfloat b){
	this->THEME_R = r;
	this->THEME_G = g;
	this->THEME_B = b;
}
void Symbol::drawABSAlert(GLfloat px,GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;
	Object absSym = Object();
	
	glPushMatrix();
		glColor3ub(240,80,68);
		absSym.drawCircle(15,cx,cy,3);
	glPopMatrix();
	glLoadIdentity();
}

void Symbol::drawBatterySymbol(GLfloat px,GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;

	
	glPushMatrix();
		glColor3f(1,0,0);
		drawRect(cx+10,cy+20,5,5);
		drawRect(cx+30,cy+20,5,5);
		
		drawRect(cx,cy,45,20);	
		glColor3f(this->THEME_R,this->THEME_G,this->THEME_B);
		drawRect(cx+2.5f,cy+2.5f,40,15);	
	glPopMatrix();
	glLoadIdentity();
}

void Symbol::drawBreakAlert(GLfloat px, GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;
	
	glColor3ub(240,80,68);
	drawCircle(15,cx,cy,3);
	glLoadIdentity();
}

void Symbol::drawCoolantSymbol(GLfloat px,GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;
	//Icon
	glPushMatrix();
		drawRect(cx-12.5f,cy+6,25,4);
		drawRect(cx-15,cy,30,4);
		drawRect(cx-2.5f,cy+6,5,18);
		drawRect(cx,cy+12,6,3);
		drawRect(cx,cy+16,6,3);
	glPopMatrix();
	glLoadIdentity();
}

void Symbol::drawEngineAlert(GLfloat px,GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;
	
	glPushMatrix();
		//top
		glColor3f(1,0.7529f,0);
		drawRect(cx,cy+22,28,4);
		drawPoint(cx+14,cy+19.5f,4);
		
		//Tail
		drawRect(cx-6,cy,4,18);
		
		//Body
		drawRect(cx,cy,35,18);
		
		glColor3f(this->THEME_R,this->THEME_G,this->THEME_B);
		drawRightTriangle(cx+4,cy+4,4);
		rotate(180,cx+17.5,cy+9);
		drawRightTriangle(cx+4,cy+4,4);
		glLoadIdentity();
		
		//head
		glColor3f(1,0.7529f,0);
		drawRect(cx+36,cy+6,5,5);
		drawRect(cx+42,cy,5,18);
	glPopMatrix();
	glLoadIdentity();
}

void Symbol::drawOilPresureAlert(GLfloat px,GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;
	
	glPushMatrix();
		glColor3f(1,0.7529f,0);
		
		//tail
		rotate(-45,cx-10,cy+23);
		drawRect(cx-10,cy+23,10,5);
		glLoadIdentity();
		
		//top
		drawRect(cx+8,cy+24,20,3);
		drawPoint(cx+17.5f,cy+21,4);
		
		//body
		drawRect(cx,cy,35,18);
		
		//head
		glScalef(1.0f,-1.0f,1.0f);
		drawRightTriangle(cx+42,-(cy+10),6);
		glLoadIdentity();
		
		rotate(-55,cx+46,cy+10);
		drawRect(cx+46,cy+10,7,4);
		glLoadIdentity();
	
	glPopMatrix();
	glLoadIdentity();
}
void Symbol::drawLeftSignal(GLfloat px, GLfloat py){
	glPushMatrix();
		glColor3f(0.2f,1,0.4f);
		drawRect(px-145,py+165,22,10);

		rotate(90,px-152,py+170);
		drawTriangle(px-152,py+170,8);
		
	glPopMatrix();
	glLoadIdentity();
}
void Symbol::drawRightSignal(GLfloat px, GLfloat py){

	

	glPushMatrix();
		glColor3f(0.2f,1,0.4f); //To make sure the signal color is green (the signal become red if without it)
		rotate(180,px,py+170);
		drawRect(px-145,py+165,22,10);
		rotate(90,px-152,py+170);
		drawTriangle(px-152,py+170,8);
	glPopMatrix();
	glLoadIdentity();
	
}


