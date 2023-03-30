#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include "Object.h"

class Symbol : public Object{
	public:
		Symbol();
		~Symbol();
		void drawABSAlert(GLfloat px,GLfloat py);
		void drawBatterySymbol(GLfloat px,GLfloat py);
		void drawBreakAlert(GLfloat px, GLfloat py);
		void drawCoolantSymbol(GLfloat px,GLfloat py);
		void drawEngineAlert(GLfloat px,GLfloat py);
		void drawOilPresureAlert(GLfloat px,GLfloat py);
		void drawSignals(GLfloat px, GLfloat py);
		
		GLfloat THEME_R,THEME_G,THEME_B;
		void setTheme(GLfloat r,GLfloat g,GLfloat b);
};
#endif
