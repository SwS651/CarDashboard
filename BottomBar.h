#ifndef _BOTTOMBAR_H_
#define _BOTTOMBAR_H_

#include "Object.h"

class BottomBar : public Object{
	public:
		BottomBar();
		~BottomBar();
		void setBackgroundColor(GLfloat r,GLfloat g,GLfloat b);
		void setPosition(GLint px,GLint py);
		void drawBottomBar();
		void drawSpeedText(int number);
		void draw();
	
	protected:
		GLfloat BG_R,BG_G,BG_B;
		GLint cx,cy;
};

#endif
