#include "Object.h"
Object::Object(){}
Object::~Object(){}
void Object::setBorderColor( GLfloat borderR,GLfloat borderG,GLfloat borderB){
	this->borderR = borderR;
	this->borderG = borderG;
	this->borderB = borderB;
}
void Object::setFilledColor(GLfloat filledR,GLfloat filledG,GLfloat filledB){
	this->filledR = filledR;
	this->filledG = filledG;
	this->filledB = filledB;
}
void Object::setUnfilledColor(GLfloat unfilledR,GLfloat unfilledG,GLfloat unfilledB)
{
	this->unfilledR = unfilledR;
	this->unfilledG = unfilledG;
	this->unfilledB = unfilledB;
}

//Rotate the object
void Object::rotate(GLfloat t,GLfloat pX, GLfloat pY){
	glTranslated(pX,pY,0);
	glRotatef(t,0.0f,0.0f,1.0f);
	glTranslated(-pX,-pY,0);	
}

void Object::orbit(GLfloat px,GLfloat py, GLfloat radius, GLfloat& angle,GLfloat torque){

	//this->x = px + radius*cos(angle*3.14159265/180);
//	this->y = py + radius*sin(angle*3.14159265/180);
//	
	if(angle<360){
		angle+=torque; //Rotational movements.
	}else
		angle = 0.0;
}

void Object::drawPoint(GLfloat x, GLfloat y, GLfloat size){
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glPopMatrix();	
}

void Object::drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness){
	glPushMatrix();
	glLineWidth(thickness);
	glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	glEnd();
	glPopMatrix();		
}

//Draw a circle (outline only)
void Object::drawCircle(GLfloat radius, GLfloat px, GLfloat py,GLfloat thickness){
	glLineWidth(thickness);
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	    for (int i = 0; i < 360; i++) {
	        float angle = i * (M_PI / 180.0f);
	        float x = px + radius * cos(angle);
	        float y = py + radius * sin(angle);
	        glVertex2f(x, y);
	    }
    glEnd();
    glPopMatrix();
}

//Draw Filled circle
void Object::drawSolidCircle(GLfloat r,GLfloat px, GLfloat py,GLfloat thickness){
	

	//glLineWidth(thickness);
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float angle = i * (M_PI / 180.0f);
        float x = px + r * cos(angle);
        float y = py + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

/*

*/
void Object::drawRingedCircle(GLfloat radius,GLfloat cx,GLfloat cy, GLfloat thickness, GLfloat progress, GLfloat emptyRadius){
    glPushMatrix();
    
	//the thickness of the ring
    glColor3f(this->borderR,this->borderG, this->borderB);
	glLineWidth(thickness);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= progress * 360; i++) {
        float angle = i * (M_PI / 180.0f);
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    
    //the progress of the ring (in degrees)
    glColor3f(this->filledR,this->filledG, this->filledB);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = progress * 360; i <= 360; i++) {
        float angle = i * (M_PI / 180.0f);
        float x = cx + (radius - thickness) * cos(angle);
        float y = cy + (radius - thickness) * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    
    
    //Draw empty space inside the ring.
    glColor3f(this->unfilledR,this->unfilledG, this->unfilledB);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= 360; i++){
    
        float angle = i * (M_PI / 180.0f);
        float x = cx + emptyRadius * cos(angle);
        float y = cy + emptyRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
	glPopMatrix();
}

void Object::drawEllipse(GLfloat pX, GLfloat pY, GLfloat radiusW, GLfloat radiusH){
	
	//To define a set of connected triangles that form a closed shape.
	//The angle theta is calculated using the formula 2 * PI * i / 32, where i is the current iteration.
	glBegin(GL_TRIANGLE_FAN);
	//I is Number of segments
    for (int i = 0; i < 32; i++) {
        float theta = 2.0f * M_PI * float(i) / 32;
        float x = radiusW * cosf(theta);
        float y = radiusH * sinf(theta);
        glVertex2f(x + pX, y + pY);
    }
    glEnd();
}

void Object::drawRect(GLfloat x,GLfloat y, GLfloat width, GLfloat height){
	glPushMatrix();
	glBegin(GL_QUADS);
    	glVertex2f(x, y);
    	glVertex2f(x + width, y);
    	glVertex2f(x + width, y + height);
    	glVertex2f(x, y + height);
    glEnd();
    glPopMatrix();
}

void Object::drawTriangle(GLfloat cx,GLfloat cy,GLfloat size){
	glPushMatrix();
	glBegin(GL_TRIANGLES);
		glVertex2i(cx -size, cy-size);
		glVertex2i(cx +size, cy-size);
		glVertex2i(cx, cy+size);
	glEnd();
	glPopMatrix();	
}

void Object::drawCustomRightTriangle(GLfloat cx, GLfloat cy, GLfloat width, GLfloat height){
    glPushMatrix();
    glBegin(GL_TRIANGLES);
        glVertex2i(cx, cy);
        glVertex2i(cx,cy+ height);
        glVertex2i(cx+width, cy);
    glEnd();
    glPopMatrix();
} 


//Draw a right triangle by setting the center point
void Object::drawRightTriangle(GLfloat cx, GLfloat cy, GLfloat size){
	glPushMatrix();
	glBegin(GL_TRIANGLES);
		glVertex2i(cx -size, cy+size);
		glVertex2i(cx -size, cy-size);
		glVertex2i(cx+size, cy-size);
	glEnd();
	glPopMatrix();	

}


void Object::drawSector(GLfloat radius, GLfloat cx,GLfloat cy, GLfloat startAngle, GLfloat sweepAngle) {
	int numSegments = 50;
	int lineWidth = 4;
    // Set the color for the sector
    //glColor3f(1.0f, 0.0f, 0.0f); // red

    // Calculate the center of the sector
    // Set the start and end angles in radians
    float startAngleRad = startAngle * M_PI / 180.0f;
    float endAngleRad = (sweepAngle) * M_PI / 180.0f;

    // Calculate the angle increment
    float angleInc = (endAngleRad - startAngleRad) / numSegments;

	glPushMatrix();
	
	
	
    glLineWidth(lineWidth);
    glColor3f(this->borderR,this->borderB,this->borderG);
    glBegin(GL_LINE_STRIP);
		for(int i=0;i<=numSegments;i++){
	    	float angle = startAngle + i * angleInc;
	    	float x = cx + radius * cos(angle);
	        float y = cy + radius * sin(angle);
	        glVertex2f(x, y);
	    }
    glEnd();
	glPopMatrix();
	
	
	glPushMatrix();
    glColor3f(this->filledR,this->filledB,this->filledG);
    // Begin drawing the sector using GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
	    // Add the center vertex
	    glVertex2f(cx, cy);
	    // Add the vertices for the outer rim of the sector
	    for (int i = 0; i <= numSegments; i++) {
	        float angle = startAngleRad + i * angleInc;
	        float x = cx + radius * cos(angle);
	        float y = cy + radius * sin(angle);
	        glVertex2f(x, y);
	    }
	// End drawing the sector
    glEnd();
   
    glPopMatrix();
    
    

}

//drawCircleProgress(_WIDTH/2,_HEIGHT/2,135,ii); //23.85f is full speed  , 100 is start
void Object::drawCircleProgress(GLfloat cx, GLfloat cy,GLfloat r, float progress) {
    // Define the circle's center point, radius, and line thickness
    //float cx = _WIDTH/2-280, cy =_HEIGHT/2, r = 134;
	float t = 0.1f;
    
    // Draw the circle's outline
    glLineWidth(t);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    
    // Draw the progress arc
    float startAngle = 230.0f; // start at the top  //315
    float endAngle = startAngle + 360 * progress / 100.0f;
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = startAngle; i <= endAngle; i++) {
        float angle = i * M_PI / 180.0f;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}


void Object::drawQuad(GLfloat x1, GLfloat y1,
					  GLfloat x2, GLfloat y2,
					  GLfloat x3, GLfloat y3,
					  GLfloat x4, GLfloat y4){
	glPushMatrix();
	glBegin(GL_QUADS);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
		glVertex2i(x4, y4);
	glEnd();
	glPopMatrix();	
}


