#ifndef _SPEEDOMETER_H_
#define _SPEEDOMETER_H_

#include "Object.h"

class Speedometer : public Object{
	public:
		Speedometer();
		~Speedometer(); 
		void setBackgroundColor(GLfloat r,GLfloat g,GLfloat b);
		void setPosition(GLint px,GLint py);
		void outerCircle();
		void circlePoint();
		void pointer();
		void coreCircle();
		void progressOrbit(GLfloat& px,GLfloat& py, GLfloat radius, GLfloat& angle,GLfloat torque);
		void draw();
	
	protected:
		GLfloat BG_R,BG_G,BG_B;
		GLint cx,cy;
		
	public:
		GLfloat circlePrgs;  //Progress Bar
};

#endif
