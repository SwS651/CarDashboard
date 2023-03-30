#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <iostream>
#include "math.h"

#include <GL/glut.h>

using namespace std;


//This class provides a set of useful functions for drawing basic shapes
class Object {
public:
	Object();
	~Object(); 
	
	void drawPoint(GLfloat x, GLfloat y, GLfloat size);
	void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness);
    void drawCircle(GLfloat radius, GLfloat px, GLfloat py,GLfloat thickness);
    void drawEllipse(GLfloat pX, GLfloat pY, GLfloat radiusW, GLfloat radiusH); 
    
    void drawSolidCircle(GLfloat r,GLfloat px, GLfloat py,GLfloat thickness);
    void drawRingedCircle(GLfloat radius,GLfloat cx,GLfloat cy, GLfloat thickness, GLfloat progress, GLfloat emptyRadius);
    void drawRect(GLfloat x,GLfloat y, GLfloat width, GLfloat height);
    void drawTriangle(GLfloat cx,GLfloat cy,GLfloat size);
    void drawRightTriangle(GLfloat cx, GLfloat cy, GLfloat size);
    void drawSector(GLfloat radius, GLfloat cx,GLfloat cy, GLfloat startAngle, GLfloat sweepAngle);
    
    //Rotate the object by a certain angle around a given point.
	void rotate(GLfloat t,GLfloat pX, GLfloat pY);
    
    // Set the colors of the border, filled, and unfilled areas of the object.
    void setBorderColor( GLfloat borderR,GLfloat borderG,GLfloat borderB);
	void setFilledColor(GLfloat filledR,GLfloat filledG,GLfloat filledB);
	void setUnfilledColor(GLfloat unfilledR,GLfloat unfilledG,GLfloat unfilledB);
    
protected:
	GLfloat borderR,borderG,borderB;
	GLfloat filledR,filledG,filledB;
	GLfloat unfilledR, unfilledG, unfilledB;

    
};

#endif
