#include "Gps.h"
Gps::Gps(){}
Gps::~Gps(){} 
void Gps::setRoadColor(GLfloat r,GLfloat g,GLfloat b){
	this->RD_R = r;
	this->RD_G = g;
	this->RD_B = b;
}

void Gps::setPosition(GLint px,GLint py){
	this->cx = px;
	this->cy = py;
}
void Gps::drawCrossRoad(GLfloat yVel){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy + yVel;
	
	//Horizontal road + Vertical road
	glPushMatrix();
		glColor3f(0.8157f,0.8078f,0.8078f);
//		glColor3f(1,0,0);
		drawRect(cx-60,cy+20,160,9);
		drawRect(cx,cy,9,52);
	glPopMatrix();
	glLoadIdentity();
	
	glPushMatrix();

		glColor3f(0.8157f,0.8078f,0.8078f);
		rotate(50, cx,cy);
		drawRect(cx,cy,6,35);
		glLoadIdentity();

		glColor3f(0.8157f,0.8078f,0.8078f);
		rotate(-50, cx+5,cy+5);
		drawRect(cx+5,cy+5,6,35);
		glLoadIdentity();
		
		glColor3f(0.8157f,0.8078f,0.8078f);
		rotate(50, cx+30,cy+23);
		drawRect(cx+30,cy+23,6,35);
		glLoadIdentity();
		
		glColor3f(0.8157f,0.8078f,0.8078f);
		rotate(-50, cx-23,cy+30);
		drawRect(cx-23,cy+30,6,35);
		glLoadIdentity();
	glPopMatrix();
}

void Gps::drawGPS(){
	//GPS
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	
	//Left side straight road
	glPushMatrix();
		glColor3f(0.8157f,0.8078f,0.8078f);
		drawRect(cx-60,cy-100,9,200);
	glPopMatrix();
	glLoadIdentity();

	
	//Center straight road
	glPushMatrix();
		
		glColor3f(0.8157f,0.8078f,0.8078f);
		drawRect(cx,cy-100,10,200);
		glLoadIdentity();
	glPopMatrix();	
		
	
	
}
//x 600 y 160
void Gps::drawNavigation(GLfloat navline){
	glPushMatrix();
		//center road cyan
		glColor3f(0.5608f, 0.9294f, 0.9373f);
		drawRect(cx-1,(cy-80)+20,12,navline);  //160
		glLoadIdentity();
		
		//glColor3f(1,1,0);
		//drawRect(cx,(cy-80)+20,10,navline);//220 
		
		glColor3f(1,0,0);				
		drawPoint(cx,cy+155,10);
		glLoadIdentity();
	glPopMatrix();
	
	glPushMatrix();
		//Transparent circle around car
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glColor4f(0.7418f,0.8431f,0.9333f,0.43f);
		drawSolidCircle(20,cx+5,(cy-90)+20,1);
		glLoadIdentity();
		
		//Car
		glColor3f(1,1,0);
		drawPoint(cx+5,(cy-90)+20,20);
		glLoadIdentity();
	glPopMatrix();
	
	glPushMatrix();
		//Arrow Direction
		glColor3f(1,1,1);
		drawTriangle(cx+65,cy-10,12);
		glLoadIdentity();
		glColor3f(1,1,1);
		drawRect(cx+59,(cy-10)-40,12,30);
		glLoadIdentity();
	glPopMatrix();
}
void Gps::draw(){
	drawGPS();
}
