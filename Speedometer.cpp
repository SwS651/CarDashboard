#include "Speedometer.h"

Speedometer::Speedometer(){}
Speedometer::~Speedometer(){}
void Speedometer::setBackgroundColor(GLfloat r,GLfloat g,GLfloat b){
	this->BG_R = r;
	this->BG_G = g;
	this->BG_B = b;
}

void Speedometer::setPosition(GLint px,GLint py){
	this->cx = px;
	this->cy = py;
}

void Speedometer::drawSpeedometer(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	glPushMatrix(); 
		//left Circle progress bar
		//background of circle
		glColor3f(0.894f, 0.894f, 0.894f); //color: grey white
		drawSolidCircle(130,cx,cy,1);
		glLoadIdentity();
		
		//progress bar and middle area of circle	
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(0.5608f, 0.9294f, 0.9373f);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(240, cx,cy);
		drawRingedCircle(135,cx,cy, 2, 0.53f, 115);
		glLoadIdentity();
		
		//Pointer (Arrow) 
		glColor3f(0.80f,0.80f,0.80f);
		rotate(-20, cx,cy+20);
		drawRect(cx,cy+20,8,80);
		glLoadIdentity();
		
		//Pointer tip (triangle)
		glColor3f(0.80f,0.80f,0.80f);
		rotate(-20,cx+33,cy+98);
		drawTriangle(cx+33,cy+98,5);
		glLoadIdentity();
		
		//Arrow border Line (white)
		glColor3f(1,1,1);
		rotate(-20,cx+29,cy+96);
		drawLine(cx+29,cy,cx+29,cy+96,3);
		glLoadIdentity();
		
		//Arrow border Line (grey)
		glColor3f(0.5f,0.5f,0.5f);
		rotate(-20,cx+34,cy+95);
		drawLine(cx+36,cy,cx+36,cy+95,3);
		glLoadIdentity();

		//Center circle:  light gray.
		glColor3f(0.80f,0.80f,0.80f);
		drawSolidCircle(33,cx,cy,1);
		glLoadIdentity();
		
		//Center circle: white (border line)
		glColor3f(1,1,1);
		drawCircle(33,cx,cy,2);
		glLoadIdentity();
		
		//Center circle: White circle
		glColor3f(1,1,1);
		drawSolidCircle(23,cx,cy,1);
		glLoadIdentity();
		
		//Center circle: Red circle
		glColor3f(1,0,0);
		drawSolidCircle(20,cx,cy,1);
		glLoadIdentity();
		
		//Center circle: core
		glColor3f(0.9090f,0.9090f,0.9090f);
		drawSolidCircle(15,cx,cy,1);
		glLoadIdentity();
		
		
		//Pointer: transparent circle and filled circle
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glColor4f(0.4f,1.0f,1.0f,0.53f);
		drawSolidCircle(22,cx+40,cy+116,1);
		glLoadIdentity();
		
		glColor3f(1.0f,1.0f,1.0f);
		drawSolidCircle(12,cx+40,cy+116,1);
		glLoadIdentity();
	glPopMatrix();
	//glLoadIdentity();
}

void Speedometer::draw(){
	drawSpeedometer();
}
