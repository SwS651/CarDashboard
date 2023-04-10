#ifndef _GPS_H_
#define _GPS_H_

#include "Object.h"
class Gps : public Object{
	public:
		Gps();
		~Gps(); 
		void setRoadColor(GLfloat r,GLfloat g,GLfloat b);
		void setPosition(GLint px,GLint py);
		void drawGPS();
		void drawNavigation();
		void draw();
	
	protected:
		GLfloat RD_R,RD_G,RD_B;
		GLint cx,cy;
};

#endif
