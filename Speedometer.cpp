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

void Speedometer::outerCircle(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	glPushMatrix(); 
			
		glColor3f(0.5608f, 0.9294f, 0.9373f);
		drawSolidCircle(137,cx,cy,0.0f);
		glLoadIdentity();
		
		setBorderColor(0.894f, 0.894f, 0.894f);
		setFilledColor(0.894f, 0.894f, 0.894f);
		rotate(-131,cx,cy);
		
		
		/* This is progress bar, 
			Speed		  degree
			
		   full speed	= 90.0f ( full Cyan color),
		   	220 kmh		= 84
		   	215 kmh		= 90.25
		   	210 kmh		= 96.5
		   	205 kmh		= 102.75
		   	200 kmh		= 109
		   	180 kmh		= 134
		   	160 kmh		= 159
		   	140 kmh		= 184
		   	120 kmh		= 209
		   	100 kmh		= 234
		   	80 kmh		= 259
		   	60 kmh		= 284
		   	40kmh		= 309		(20kmh - 25)
			30 kmh		= 321.5,	(20kmh - 12.5)
			20 kmh		= 334		(360-25)
		   	10 kmh		= 346.5		(360-12.5)
		   0kmh 		= 360 359 358 (full grey color )
		   
		   (25)
		*/
		drawSector(135,cx,cy, 0.0f, this->circlePrgs); 
		//drawSector(135,cx,cy, 0.0f, 90.25);  
		glLoadIdentity();
		
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		drawSolidCircle(118,cx,cy,1);
		
		
		
	glPopMatrix();
	
	//glLoadIdentity();
}
void Speedometer::coreCircle(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	glPushMatrix();
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
	glPopMatrix();
}

void Speedometer::pointer(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	GLfloat progress = 359;//this->circlePrgs;  //this is used to increment or decrement the progress bar
	glPushMatrix();	
		
		rotate(this->circlePrgs,this->cx,this->cy);
		//rotate(90,this->cx,this->cy);  
		
		//Pointer (Arrow) 
		glColor3f(0.80f,0.80f,0.80f);
		rotate(-42, cx,cy);   //start from left side
		drawRect(cx-4,cy-105,8,80);
		glLoadIdentity();
		
		rotate(this->circlePrgs,this->cx,this->cy);
		//Pointer tip (triangle)
		glColor3f(0.80f,0.80f,0.80f);
		rotate(-42,cx,cy);
		rotate(180,cx,cy-110);
		drawTriangle(cx,cy-110,5);
		glLoadIdentity();
		
		rotate(this->circlePrgs,this->cx,this->cy);
		//Arrow border Line (white)
		glColor3f(1,1,1);
		rotate(-42,cx,cy);   // start from -42 == 0 kmH
		drawLine(cx-2,cy,cx-4,cy-105,3);
		glLoadIdentity();
		
		rotate(this->circlePrgs,this->cx,this->cy);
		//Arrow border Line (grey)
		glColor3f(0.5f,0.5f,0.5f);
		rotate(-42,cx,cy);
		drawLine(cx+4,cy,cx+4,cy-105,3);
		glLoadIdentity();
	glPopMatrix();
	
	

}


void Speedometer::circlePoint(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	//GLfloat cx = px;
//	GLfloat cy = py;
	glPushMatrix();	
		rotate(this->circlePrgs,this->cx,this->cy);
		//Pointer: transparent circle and filled circle
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glColor4f(0.4f,1.0f,1.0f,0.53f);
		drawSolidCircle(22,cx-85,cy-95,1);  //->
		glLoadIdentity();
		
		rotate(this->circlePrgs,this->cx,this->cy);
		//rotate(rotateAngle,this->cx,this->cy);
		glColor3f(1.0f,1.0f,1.0f);
		drawSolidCircle(12,cx-85,cy-95,1); //->
		glLoadIdentity();
		
		
		////Pointer: transparent circle and filled circle
//		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//		glEnable(GL_BLEND);
//		glColor4f(0.4f,1.0f,1.0f,0.53f);
//		drawSolidCircle(22,cx+40,cy+116,1);  //->
//		glLoadIdentity();
//		
//		glColor3f(1.0f,1.0f,1.0f);
//		drawSolidCircle(12,cx+40,cy+116,1); //->
//		glLoadIdentity();
	glPopMatrix();

}



void Speedometer::draw(){

	
	
}
