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

void Accelerometer::drawAccelerometerprogressBar(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	/*	
		Number	= rotation angle 
		0		= 45 or 47 or 48
		1	 	= 35 or 38
		2		= 25
		3		= 10
		4 		= -5
		5		= -25
		6		= -40
		7		= -60
		8		=  -72 or -78 (Full)
	*/
	
	/*Rotation Angle  //Pointer
		0  	= 0
		1 	= -12
		2 	= -26
		3	= -40
		4	= -55
		5	= -70
		6	= -88
		7	= -105
		8	= -122 and above
	*/
	
	
	glPushMatrix();
		rotate(50,cx,cy);
		rotate(180,cx,cy);
		setBorderColor(0.5608f, 0.9294f, 0.9373f);
		setFilledColor(0.5608f, 0.9294f, 0.9373f);
		drawSector(105,cx,cy,0,accProgress);
	glPopMatrix();
	glLoadIdentity();
	

	
	
} 
void Accelerometer::drawAccelerometerPointer(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	/*Rotation Angle
		0  	= 0
		1 	= -12
		2 	= -26
		3	= -40
		4	= -55
		5	= -70
		6	= -88
		7	= -105
		8	= -122 and above
	*/
	
	//accelerator pointer
	glPushMatrix();
		rotate(accProgress,cx,cy);    //Interact with the variable in main
		//rotate(0,cx,cy);
		glColor3f(1,0,0);
		//Left side
		drawLine(cx-25,cy-30,cx-55,cy-65,3);
	glPopMatrix(); 
	glLoadIdentity();
} 

void Accelerometer::drawFuel(){
	
	if(this->status){
		//Fuel
		glPushMatrix();
			setBorderColor(0.8510f,0.8510f,0.8510f);
			setFilledColor(0.85f,0.85f,0.85f);
			rotate(-30,cx,cy);
			
			//sweepAngle increase then fuel increase, otherwise decrease (47.0f)
			drawSector(101,cx,cy, 0.0f, 47.0f);
		glPopMatrix();
		glLoadIdentity();
	}
	
	
	////fuel outline white color, BG empty circle and filled circle
	glPushMatrix();
		setBorderColor(1,1,1);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
		rotate(-30, cx,cy); //small number, progress bar increase
		drawRingedCircle(80,cx,cy, 3, 0.18f, 78);
	glPopMatrix();
	glLoadIdentity();
	
	//Top and bottom line (fuel)
	glPushMatrix();
		glColor3f(1,1,1);
		rotate(35,cx+63,cy+50);
		drawLine(cx+63,cy+45,cx+88,cy+45,3);
		glLoadIdentity();
		
		glColor3f(1,1,1);
		rotate(-29,cx+69,cy-35);
		drawLine(cx+69,cy-38,cx+95,cy-38,3);
		glLoadIdentity();
		
		drawLine(cx+116,cy+8,cx+116,cy+12,2);
		drawLine(cx+116,cy+12,cx+118,cy+18,2);
		drawLine(cx+118,cy+18,cx+131,cy+18,2);
		drawLine(cx+131,cy+18,cx+134,cy+12,2);
		drawLine(cx+134,cy+12,cx+134,cy+8,2);
		drawRect(cx+115,cy-15,20,25);
		glLoadIdentity();
	glPopMatrix();
}

void Accelerometer::drawAccelerometer(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;

	//Draw top and bottom of progress bar line (white)
	glPushMatrix();
		glColor3f(1,1,1);
		rotate(11,cx,cy);
		drawLine(cx,cy+105,cx,cy+88,3);
		glLoadIdentity();
		
		glColor3f(1,1,1);
		rotate(139,cx,cy);
		drawLine(cx,cy+105,cx,cy+88,3);
		glLoadIdentity();
	glPopMatrix();
	
	
	//Outline accelerometer circle (White)
	glPushMatrix();
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		//Inside
		drawSolidCircle(88,cx,cy,1);
	
		//outside
		glColor3f(1,1,1);
		drawCircle(107,cx,cy,4);
	glPopMatrix();
	glLoadIdentity();
	
	
	//Coverage
	glPushMatrix();
	rotate(100,cx,cy);
		setFilledColor(this->BG_R,this->BG_G,this->BG_B);
		setBorderColor(1,1,1);
		drawRingedCircle(87,cx,cy,3,0.36f,0);
	glPopMatrix();
	glLoadIdentity();
	
}

void Accelerometer::drawMiddleRedAreaRing(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;

	//red progress bar
	glPushMatrix();
		setBorderColor(1,0,0);
		setFilledColor(1,0,0);
		rotate(102,cx,cy);
		drawSector(45,cx,cy,0,128);
		glLoadIdentity();
	glPopMatrix();

	//outline circle (red)
	glPushMatrix();
		glColor3f(1,0,0);
		drawCircle(41,cx,cy,3);
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		drawSolidCircle(35,cx,cy,0.1f);
	glPopMatrix();	
	glLoadIdentity();

	
	glPushMatrix();
		//Right side accelerator pointer
		glColor3f(1,0,0);
		if(this->status)
			drawLine(cx+40,cy+10,cx+99,cy+29,3);
		else{
			rotate(-45,cx,cy);
			drawLine(cx+40,cy+10,cx+99,cy+29,3);
		}
			
	glPopMatrix(); 
	glLoadIdentity();
} 

void Accelerometer::drawCoolantBar(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	

	if(this->status){
		glPushMatrix();
			setBorderColor(1,1,1);
			setFilledColor(1,1,1);
			setUnfilledColor(this->BG_R,this->BG_G,this->BG_B);
			rotate(-100, cx,cy);
			drawRingedCircle(135,cx,cy, 1, 0.5f, 122);
			glLoadIdentity();
		glPopMatrix();	
	}
	
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
		
		glColor3f(1,1,1);
		rotate(20,cx,cy);
		drawLine(cx,cy+120,cx,cy+136,3);
		glLoadIdentity();
	glPopMatrix();

	
	
}

void Accelerometer::displayGear(string gear = ""){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy;
	
	
	if(gear=="D4"){
		//Output: D
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
		
		//Output:4
		glPushMatrix();
	
			glColor3f(0.9f,0.9f,0.9f);
			rotate(50,cx+5,cy-8);
			drawRect(cx+5,cy-8,25,4);
			glLoadIdentity();
	
			drawRect(cx+3,cy-9,25,5);
			drawRect(cx+18,cy-15,5,28);
			glLoadIdentity();
		glPopMatrix();
	}
	if(gear == "R"){
		glPushMatrix();
			glColor3f(0.9f,0.9f,0.9f);
			drawRect(cx-8,cy+15,14,8);
			
			drawSolidCircle(14,cx+4,cy+9,1);
			
			glColor3f(this->BG_R,this->BG_G,this->BG_B);
			drawSolidCircle(8,cx+2,cy+9,1);
			
			glColor3f(0.9f,0.9f,0.9f);
			drawRect(cx-8,cy-6,15,7);
			
			drawRect(cx-13,cy-25,8,48);
			rotate(20,cx+11,cy-24);
			drawRect(cx+11,cy-24,7,20);
			glLoadIdentity();
		glPopMatrix();
		
	}
	if(gear =="N"){
		glPushMatrix();
			glColor3f(0.9f,0.9f,0.9f);
			drawRect(cx-15,cy-19,7,38); 
			
			rotate(-55,cx-15,cy+15);
			drawRect(cx-15,cy+15,40,7); 
			glLoadIdentity();
			drawRect(cx+9,cy-19,7,38); 
			glLoadIdentity();
		glPopMatrix();
	}
}


void Accelerometer::display(){
	
	drawCoolantBar();

	if(this->status)
		drawAccelerometerprogressBar();
		
	drawAccelerometer();
	drawFuel();
	drawMiddleRedAreaRing();
	drawAccelerometerPointer();
	
	
}

