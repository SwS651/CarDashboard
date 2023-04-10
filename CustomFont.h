#ifndef _CUSTOMFONT_H_
#define _CUSTOMFONT_H_


#include "Object.h"
class CustomFont:public Object{
		public:
			CustomFont();
			~CustomFont();
			void setBackground(GLfloat r,GLfloat g,GLfloat b);
			void setPosition(GLfloat px,GLfloat py);
			void setFontText(GLfloat px,GLfloat py, string text);
			void setFontColor(GLfloat r,GLfloat g,GLfloat b);
			void draw0(GLfloat px,GLfloat py);
			void draw1(GLfloat px,GLfloat py);
			void draw2(GLfloat px,GLfloat py);
			void draw3(GLfloat px,GLfloat py);
			void draw4(GLfloat px,GLfloat py);
			void draw5(GLfloat px,GLfloat py);
			void draw6(GLfloat px,GLfloat py);
			void draw7(GLfloat px,GLfloat py);
			void draw8(GLfloat px,GLfloat py);
			void draw9(GLfloat px,GLfloat py);
			
		
		
		
	protected:
		GLfloat cx;
		GLfloat cy;
		GLfloat r,g,b;
		GLfloat BG_R,BG_G,BG_B;
	private:
		
	
	
};

#endif
