#include "Dashboard.h"
Dashboard::Dashboard(){}
Dashboard::~Dashboard(){} 
void Dashboard::setColor(GLfloat r,GLfloat g,GLfloat b,GLfloat alpha){
	this->r = r;
	this->g = g;
	this->b = b;
	this->alpha = alpha;
}

void Dashboard::setPosition(GLint px,GLint py){
	this->cx = px;
	this->cy = py;
}

void Dashboard::drawDashboard(GLfloat cx, GLfloat cy){
	


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(this->r,this->g,this->b,this->alpha);
    glBegin(GL_TRIANGLE_STRIP);

	    // Draw the vertices
	    glVertex2f(cx,cy);
	    glVertex2f(50,cy); 
	    glVertex2f(50,cy+73);
	    
	    glVertex2f(cx,cy);
	    glVertex2f(200,cy+170);
	    glVertex2f(cx,cy+170);
	    
	    glVertex2f(cx,cy);
	    glVertex2f((cx*2)-200,cy+170);
	    glVertex2f((cx*2)-50,cy+73);
	    
	    glVertex2f(cx,cy);
	    glVertex2f((cx*2)-50,cy);
    
    glEnd();

	

}

void Dashboard::draw(){
	GLfloat cx = this->cx;
	GLfloat cy = this->cy+20;
	
	glPushMatrix();
		drawDashboard(cx,cy);
	glPopMatrix();
	glLoadIdentity();
	
	glPushMatrix();
		glTranslated(cx,cy,0);
		glRotatef(180,0.0f,0.0f,1.0f);
		glTranslated(-(cx),-(cy),0);
		drawDashboard(cx,cy);
	glPopMatrix();
	glLoadIdentity();
}
