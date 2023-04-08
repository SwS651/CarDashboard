#ifndef _ACCELEROMETER_H_
#define _ACCELEROMETER_H_

#include "Object.h"
class Accelerometer : public Object{
	public:
		Accelerometer();
		~Accelerometer();
		void setBackgroundColor(GLfloat r,GLfloat g,GLfloat b);
		void setPosition(GLint px,GLint py);
		void drawAccelerometerprogressBar();
		void drawAccelerometerPointer();
		void drawAccelerometer();
		void drawCoolantBar();
		void drawFuel();
		void drawGearText();
		void drawMiddleRedAreaRing();
		void draw();
	
	protected:
		GLfloat BG_R,BG_G,BG_B;
		GLint cx,cy;
	public:
		GLfloat accProgress;
};

#endif
