#include "CustomFont.h"
#include <algorithm>
CustomFont::CustomFont(){}
CustomFont::~CustomFont(){}

void CustomFont::setBackground(GLfloat r,GLfloat g,GLfloat b){
	this->BG_R = r;
	this->BG_G = g;
	this->BG_B = b;
}


void CustomFont::setPosition(GLfloat px,GLfloat py){
	this->cx = px;
	this->cy = py;
}

void CustomFont::setFontText(GLfloat px,GLfloat py, string text){
	this->cx = px;
	this->cy = py;
	
	for (int i = 0; i < text.length(); i++) 
	{
		char c = text[i];
		
		switch(c){
			case '0':
				draw0(px,py);
			break;
			
			case '1':
				px-=13;
				draw1(px,py);
				//px-=12;
			break;
			
			case '2':
				draw2(px,py);
			break;
			
			case '3':
				draw3(px,py);
			break;
			case '4':
				draw4(px,py);
			break;
			
			case '5':
				draw5(px,py);
			break;
			
			case '6':
				draw6(px,py);
			break;
			
			case '7':
				draw7(px,py);
			break;
			
			case '8':
				draw8(px,py);
			break;
			
			case '9':
				draw9(px,py);
			break;
		}
		
		px +=35;
	}
	
}
void CustomFont::setFontColor(GLfloat r,GLfloat g,GLfloat b){
	this->r = r;
	this->g = g;
	this->b = b;
}
void CustomFont::draw0(GLfloat px,GLfloat py){
	//Zero
	//glColor3f(1,0,0);
//	drawEllipse(cx,cy+17, 13.5f, 19.0f);
//	glColor3f(0.01569f,0.14902f,0.30196f);
//	drawEllipse(cx,cy+17, 7.5f, 14.0f);
	glPushMatrix();
		glColor3f(1,0,0);
		drawEllipse(px+15,py+18, 13.5f, 20.0f);
		glColor3f(0.01569f,0.14902f,0.30196f);
		drawEllipse(px+15,py+18, 7.5f, 15.0f);
	glPopMatrix();
}

void CustomFont::draw1(GLfloat px,GLfloat py){
	glPushMatrix();
		glColor3f(1,1,0);		
		drawRect(px+13,py+26,10,6);
		drawRect(px+23,py,7,37);
	glPopMatrix();
}

void CustomFont::draw2(GLfloat px,GLfloat py){
	//2
	glPushMatrix();
		setBorderColor(0.01569f,0.14902f,0.30196f);
		setFilledColor(1,1,1);
		setUnfilledColor(0.01569f,0.14902f,0.30196f);
		rotate(180, px+14,py+24);
		drawRingedCircle(16,px+14,py+24, 2, 0.5f, 8);
		glLoadIdentity();
		
		glColor3f(1,1,1);
		rotate(43,px+4,py);
		drawRect(px+4,py,33,6);
		glLoadIdentity();
		drawRect(px,py,30,6);
		glLoadIdentity();
	glPopMatrix();
}

void CustomFont::draw3(GLfloat px,GLfloat py){
	glPushMatrix();
			//setBorderColor(1,1,0);
			setFilledColor(1,0,0);
			setUnfilledColor(0.01569f,0.14902f,0.30196f);
			rotate(80, px+16,py+13);
			drawRingedCircle(16,px+16,py+13, 2, 0.3f, 7);
			glLoadIdentity();
			
			
			glColor3f(0.01569f,0.14902f,0.30196f);
			//drawRect(px-5,py+6,10,12);
			
			glColor3f(1,0,0);
			drawRect(px+5, py+31, 25, 7);
			
			drawRect(px+12, py+18, 6, 8);
			rotate(-45,px+9,py+22);
			drawRect(px+9,py+22,7,19);
			glLoadIdentity();
			
			glColor3f(0.01569f,0.14902f,0.30196f);
			drawSolidCircle(8,px+15, py+14, 1);
			
		glLoadIdentity();
	glPopMatrix();
	
	
}

void CustomFont::draw4(GLfloat px,GLfloat py){
	//4
	glPushMatrix();

		glColor3f(0.9f,0.9f,0.9f);
		rotate(52,px+4,py+9);
		drawRect(px+4,py+9,32,7);
		glLoadIdentity();

		drawRect(px,py+9,30,6);
		drawRect(px+19,py,6,37);
		glLoadIdentity();
	glPopMatrix();
}

void CustomFont::draw5(GLfloat px,GLfloat py){
	
		glPushMatrix();
			glColor3f(1,0,0);
			drawRect(px, py+32, 28, 6);
			
			//setBorderColor(1,1,0);
			setFilledColor(1,0,0);
			setUnfilledColor(0.01569f,0.14902f,0.30196f);
			rotate(90, px+15,py+12.5f);
			drawRingedCircle(14.7f,px+15,py+12.5f, 2, 0.5f, 7);
			glLoadIdentity();
			
			glColor3f(1,0,0);
			drawRect(px,py+18,6,12);
			drawRect(px+5,py+18,14,7);
			drawRect(px,py,17,6);


		glLoadIdentity();
		glPopMatrix(); 

}

void CustomFont::draw6(GLfloat px,GLfloat py){
		glPushMatrix();
			glColor3f(1,0,0);
			rotate(50,px+6,py+14.5f);
			drawRect(px+6, py+14.5f, 27, 7);
			glLoadIdentity();
			
			drawSolidCircle(14,px+15,py+12,1);	
			
			glColor3f(0.01569f,0.14902f,0.30196f);
			drawSolidCircle(7,px+15,py+12,1);
			
		glLoadIdentity();
		glPopMatrix(); 
}

void CustomFont::draw7(GLfloat px,GLfloat py){
		glPushMatrix();
			glColor3f(1,0,0);
			
			drawRect(px, py+31, 30, 7);
			
			rotate(55,px+6,cy);
			drawRect(px+6, py, 36, 6);
			
		glLoadIdentity();
		glPopMatrix(); 
}
void CustomFont::draw8(GLfloat px,GLfloat py){
	glPushMatrix();
		glColor3f(1,0,0);
		
		drawSolidCircle(11,px+15,py+26,1);
		drawSolidCircle(13,px+15,py+13,1);
		
		glColor3f(0.01569f,0.14902f,0.30196f);
		drawSolidCircle(7.5f,px+15,py+12,1);
		drawSolidCircle(5.5f,px+15,py+27,1);
				
	glLoadIdentity();
	glPopMatrix(); 
}
void CustomFont::draw9(GLfloat px,GLfloat py){
	
	glPushMatrix();
		glColor3f(1,0,0);
		//rotate(62,cx+12,cy);
		drawRect(px+21, py, 6, 38);
		glLoadIdentity();
		
		
		drawSolidCircle(12,px+13,py+25,1);	
		glColor3f(0.01569f,0.14902f,0.30196f);
		drawSolidCircle(6,px+13,py+25,1);
		
	glLoadIdentity();
	glPopMatrix(); 
}


