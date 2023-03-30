#include "Accelerometer.h"
Accelerometer::Accelerometer(){}
Accelerometer::~Accelerometer(){}


void Accelerometer::setBackgroundColor(GLfloat r,GLfloat g,GLfloat b){
	this->BG_R = r;
	this->BG_G = g;
	this->BG_B = b;
}

void Accelerometer::setPosition(GLint px,GLint py){
	this->cx = px;
	this->cy = py;
}

void Accelerometer::drawAccelerometer(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;


	glPushMatrix();
	//progress bar (cyan color)	
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(0.5608f, 0.9294f, 0.9373f);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(8, cx,cy); //small number, progress bar increase
		drawRingedCircle(105,cx,cy, 1, 0.5f, 88);
	glPopMatrix();
	glLoadIdentity();
	
	
	//Draw top and bottom of progress bar line (white)
	glPushMatrix();
		glColor3f(1,1,1);
		rotate(11,cx,cy);
		drawLine(cx,cy+105,cx,cy,3);
		glLoadIdentity();
		
		glColor3f(1,1,1);
		rotate(139,cx,cy);
		drawLine(cx,cy+105,cx,cy,3);
		glLoadIdentity();
	glPopMatrix();
	
	//Draw progress bar line
	glPushMatrix();
		glColor3f(1,1,1);
		drawCircle(88,cx,cy,2);
		glLoadIdentity();
	glPopMatrix();
	
	glPushMatrix();
		//overlapping (coverage area)
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(100, cx,cy);
		drawRingedCircle(105,cx,cy, 1, 0.5f, 0);
		glLoadIdentity();
	
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(50, cx,cy);
		drawRingedCircle(105,cx,cy, 1, 0.5f, 0);
		glLoadIdentity();
	glPopMatrix();
	
	//Outline circle
	glPushMatrix();
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		drawSolidCircle(88,cx,cy,1);
	
		glColor3f(1,1,1);
		drawCircle(106,cx,cy,4);
	glPopMatrix();
	glLoadIdentity();
	
	//Fuel
	glPushMatrix();
		setBorderColor(0.8510f,0.8510f,0.8510f);
		setFilledColor(0.85f,0.85f,0.85f);
		rotate(-30,cx,cy);
		drawSector(101,cx,cy, 0.0f, 47.0f);
	glPopMatrix();
	glLoadIdentity();
	
	//fuel outline white color 
	glPushMatrix();
		setBorderColor(1,1,1);
		rotate(-30,cx,cy);
		drawSector(80,cx,cy, 0.0f, 65.0f);
	glPopMatrix();
	glLoadIdentity();
	
	//Top and bottom line (fuel)
	glPushMatrix();
		glColor3f(1,1,1);
		rotate(35,cx+62,cy+50);
		drawLine(cx+62,cy+45,cx+88,cy+45,3);
		glLoadIdentity();
		
		glColor3f(1,1,1);
		rotate(-33,cx+62,cy-35);
		drawLine(cx+62,cy-35,cx+95,cy-35,3);
		glLoadIdentity();
		
		drawLine(cx+116,cy+8,cx+116,cy+12,2);
		drawLine(cx+116,cy+12,cx+118,cy+18,2);
		drawLine(cx+118,cy+18,cx+131,cy+18,2);
		drawLine(cx+131,cy+18,cx+134,cy+12,2);
		drawLine(cx+134,cy+12,cx+134,cy+8,2);
		drawRect(cx+115,cy-15,20,25);
		glLoadIdentity();
	glPopMatrix();
	
	//red progress bar
	glPushMatrix();
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(1,0,0);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(-120,cx,cy);
		drawRingedCircle(48,cx,cy,3,0.5f,34);
		glLoadIdentity();
	glPopMatrix();
	
	//overlapping 50 % left red progress bar (top)
	glPushMatrix();
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(120,cx,cy);
		drawRingedCircle(83,cx,cy,3,0.5f,0);
		glLoadIdentity();

		//overlapping 50% left red progress bar (bottom)

		rotate(50,cx,cy);
		drawRingedCircle(48,cx,cy,3,0.5f,0);
		glLoadIdentity();
	glPopMatrix();
	
	
	//circle line (red)
	glPushMatrix();
		glColor3f(1,0,0);
		drawCircle(40,cx,cy,3);
	glPopMatrix();	
	glLoadIdentity();

		//accelerator pointer
	glPushMatrix();
		glColor3f(1,0,0);
		drawLine(cx-45,cy-5,cx-85,cy-15,3);
		drawLine(cx+40,cy+10,cx+99,cy+29,3);
	glPopMatrix(); 
	glLoadIdentity();
	
}

void Accelerometer::drawCoolantBar(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	

	glPushMatrix();
		setBorderColor(1,1,1);
		setFilledColor(1,1,1);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(-100, cx,cy);
		drawRingedCircle(135,cx,cy, 1, 0.5f, 122);
		glLoadIdentity();
	glPopMatrix();
	
	
	
	glPushMatrix();
		//coolant top outline
		glColor3f(1,1,1);
		drawCircle(133,cx,cy,3);
	
		//coolant bottom outline
		glColor3f(1,1,1);
		drawCircle(122,cx,cy,3);
	glPopMatrix();
	glLoadIdentity();
	
	//Overlay circle for water-cooled progress bar (Left)
	glPushMatrix();
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(-70, cx,cy);
		drawRingedCircle(137,cx,cy, 1, 0.5f, 0);
		glPopMatrix();
		glLoadIdentity();
		
		//Overlay circle for water-cooled progress bar (right)
		glPushMatrix();
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(67, cx,cy);
		drawRingedCircle(137,cx,cy, 1, 0.5f, 0);
		glLoadIdentity();
	glPopMatrix();
	
	//Coolant close Line
	glPushMatrix();
		glColor3f(1,1,1);
		rotate(-23,cx,cy);
		drawLine(cx,cy+120,cx,cy+136,3);
		glLoadIdentity();
	glPopMatrix();

	
	
}

void Accelerometer::drawGearText(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	
	//Output: D4
	//D
	glPushMatrix();
		setBorderColor(this->BG_R,this->BG_G,this->BG_B);
		setFilledColor(0.95f,0.95f,0.95f);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(110,cx-13,cy);
		drawRingedCircle(15,cx-13,cy,1,0.4f,8);
		glLoadIdentity();
		
		glColor3f(0.95f,0.95f,0.95f);
		drawRect(cx-24,cy-14,7,28);
	glPopMatrix();
	
	//4
	glPushMatrix();

		glColor3f(0.9f,0.9f,0.9f);
		rotate(50,cx+5,cy-8);
		drawRect(cx+5,cy-8,25,4);
		glLoadIdentity();

		drawRect(cx+3,cy-9,25,5);
		drawRect(cx+18,cy-15,5,28);
		
	glPopMatrix();
}

void Accelerometer::draw(){
	drawCoolantBar();
	drawAccelerometer();
	drawGearText();
	
}
