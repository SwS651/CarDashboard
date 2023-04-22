#include "BottomBar.h"
#include "CustomFont.h"
 
#include<sstream>  
BottomBar::BottomBar(){}
BottomBar::~BottomBar(){}
void BottomBar::setBackgroundColor(GLfloat r,GLfloat g,GLfloat b){
	this->BG_R = r;
	this->BG_G = g;
	this->BG_B = b;
}

void BottomBar::setPosition(GLint px,GLint py){
	this->cx = px;
	this->cy = py;
}

void BottomBar::drawBottomBar(){
	GLfloat px = this->cx;
	GLfloat py = this->cy;
	
	//BorderLine
	glPushMatrix();
		
		//hidden place for GPS
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		drawRect(cx-60,cy+120,160,70);//Top
		drawRect(cx-60,cy-107,160,26);//Bottom
		
		glColor3f(1,1,1);
		drawLine(px-400,py-149,px-328,py-49,5);
		drawLine(px-328,py-49,px-230,py-49,5);
		drawLine(px-230,py-49,px-168,py-109,5);
		drawLine(px-168,py-109,(px*2)-140,py-109,4);
		drawLine((px*2)-140,py-109,(px*2)-198,py-149,4);
		drawLine((px*2)-198,py-149,px-400,py-149,3);
	glPopMatrix();
	glLoadIdentity();
	
	//Bottom bar
	glPushMatrix();
	glBegin(GL_POLYGON);
		glColor3f(this->BG_R,this->BG_G,this->BG_B);
		glVertex3f(px-400,py-149,0);
		glVertex3f(px-328,py-49,0);
		glVertex3f(px-230,py-49,0);
		glVertex3f(px-168,py-109,0);
		glVertex3f((px*2)-140,py-109,0);
		glVertex3f((px*2)-198,py-149,0);
		glVertex3f(px-400,py-149,0);
	glEnd();
	glPopMatrix();
	glLoadIdentity();
}

void BottomBar::drawSpeedText(int n){
	ostringstream num;
	num<<n;
	
	
	GLint cx = this->cx-280;
	

	cx -=(30*(num.str()).length()/2);
	

		
	GLint cy = this->cy-112;
	glColor3f(1,1,1);
	glPushMatrix();
	
	CustomFont* number = new CustomFont();
	number->setFontColor(1,1,1);
	number->setPosition(cx,cy);
	number->setFontText(cx,cy,num.str());
	
		
		
	
	glPopMatrix();
	glLoadIdentity();
	delete number;
}
void BottomBar::draw(){
	drawBottomBar();
	//drawSpeedText(number);
}
