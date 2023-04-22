#ifndef _DASHBOARD_H_
#define _DASHBOARD_H_

#include "Object.h"
class Dashboard : public Object{
	public:
		Dashboard();
		~Dashboard();
		void setColor(GLfloat r,GLfloat g,GLfloat b,GLfloat alpha);
		void setPosition(GLint px,GLint py);
		void drawDashboard(GLfloat cx,GLfloat cy);
		void draw();
	
	protected:
		GLfloat r,g,b,alpha;
		GLint cx,cy;
};

#endif
