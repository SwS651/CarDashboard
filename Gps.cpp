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


void Gps::drawGPS(){
	//GPS
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	
	glPushMatrix();
		glColor3f(0.8157f,0.8078f,0.8078f);
		drawRect(cx-60,cy-100,9,200);
	glPopMatrix();
	glLoadIdentity();

	//Horizontal road
	glPushMatrix();
		glColor3f(0.8157f,0.8078f,0.8078f);
		drawRect(cx-60,cy+20,160,9);
		
	glPopMatrix();
	glLoadIdentity();
	
	glPushMatrix();
		////
		glColor3f(0.8157f,0.8078f,0.8078f);
		rotate(50, cx,cy);
		drawRect(cx,cy,6,35);
		glLoadIdentity();
	glPopMatrix();
	
	glPushMatrix();
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
	
	glPushMatrix();
		//Center road
		glColor3f(0.8157f,0.8078f,0.8078f);
		drawRect(cx,cy-100,10,200);
		glLoadIdentity();
	glPopMatrix();	
		
	
	
}

void Gps::drawNavigation(){
	glPushMatrix();
		//center road cyan
		glColor3f(0.5608f, 0.9294f, 0.9373f);
		drawRect(cx-1,(cy-80)+20,12,160);
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
		
		
	//////glColor3f(1.0f, 1.0f, 1.0f);
		//text = "7 KM";
		//drawText("7 KM", text.size(), cx+45,cy-75, GLUT_BITMAP_HELVETICA_18,3.0f);
		//glLoadIdentity();
	glPopMatrix();
}
void Gps::draw(){
	drawGPS();
}
