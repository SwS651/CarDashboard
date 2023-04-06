#include <windows.h>
#include <gl/glut.h>

#include "Dashboard.h"
#include "Speedometer.h"
#include "Gps.h"
#include "Accelerometer.h"
#include "Symbol.h"
#include "BottomBar.h"

using namespace std;

const int _WIDTH = 1200;
const int _HEIGHT = 600;

GLfloat THEME_R = 0.01569f;
GLfloat THEME_G = 0.14902f; 
GLfloat THEME_B = 0.30196f;

GLfloat BG_R = 0.0118f;
GLfloat BG_G = 0.098f; 
GLfloat BG_B = 0.2f;

GLfloat angle = 0.0f;

GLfloat rotateAngle = 0;  //start from 158 degree
GLfloat pointerAng = 359;//138;
GLfloat ii = 100;
bool pFlag = true;

GLfloat px = (_WIDTH/2)-280;
GLfloat py = _HEIGHT/2;

void drawText(const char *text, GLint length, GLint x, GLint y, void *font,GLfloat size){
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	
	glLoadIdentity();
	glOrtho(0, _WIDTH, 0, _HEIGHT, -5, 5);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(x,y,0);
		glScalef(size,size,1.0f);
		glTranslatef(-x,-y,0);
		glRasterPos2i(x, y);

		for(int i=0; i<length; i++){
			glutBitmapCharacter(font, (int)text[i]);
		}
	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	
	delete[] matrix;
}

void da2hboard(){
	Dashboard* dashboard = new Dashboard();
	Symbol* signals = new Symbol();
	dashboard->setColor(THEME_R,THEME_G,THEME_B);
	dashboard->setPosition(_WIDTH/2,_HEIGHT/2);
	dashboard->draw();
	
	signals->drawSignals(_WIDTH/2,(_HEIGHT/2)-15);

	delete signals;
	delete dashboard;
}
void orbit(GLfloat cx,GLfloat cy, GLfloat radius, GLfloat& angle,GLfloat torque,GLfloat& px,GLfloat& py){

	px = cx - radius*cos(angle*3.14159265/180);
	py = cy - radius*sin(angle*3.14159265/180);
	
	if(angle<360){
		angle+=torque; //Rotational movements.
	}else
		angle = 0.0;
}


void ppp(GLfloat x, GLfloat y,GLint size){
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2i(x,y);

	glEnd();
	glPopMatrix();
}

void speedoPointer(){
	if(pFlag){
		pointerAng+=1;

	}else{
		pointerAng-=1;
	}
}
void spe2dometer(){
	Speedometer* speedometer = new Speedometer();
	speedometer->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	speedometer->setPosition((_WIDTH/2)-280,_HEIGHT/2);
	speedometer->circlePrgs = pointerAng;
	speedometer->outerCircle();
	speedometer->circlePoint();
	
	speedometer->pointer();
	speedometer->coreCircle(); 
	speedoPointer();

	//Speedometer;  360-90 (0 -> full kmh)
	if (pointerAng == 90) 
  		pFlag = true;
	
	if (pointerAng >= 359) 
		pFlag=false;

	delete speedometer;
}
void gps(){
	Gps* gPs = new Gps();
	gPs->setRoadColor(0.8157f,0.8078f,0.8078f);
	gPs->setPosition(_WIDTH/2,(_HEIGHT/2)+20);
	gPs->draw();
	
	delete gPs;
}

void accelerometer(){
	Accelerometer* accmeter = new Accelerometer();
	Symbol* symbols = new Symbol();
	GLfloat px = _WIDTH/2;
	GLfloat py = _HEIGHT/2; 
	
	//Draw an accelerometer
	accmeter->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	accmeter->setPosition(px+300,py+15);
	accmeter->draw();
	
	glColor3f(0.4f,1,1);
	symbols->drawCoolantSymbol(px+300,py+155.5f);
	
	delete accmeter;
	delete symbols;
}

void bottomBar(){
	Symbol* symbols = new Symbol();
	GLfloat px = _WIDTH/2;
	GLfloat py = _HEIGHT/2; 
	
	BottomBar* btmbar = new BottomBar();
	
	btmbar->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	btmbar->setPosition(px,py);
	btmbar->draw();
	
	//draw engine alert, oil pressure alert, and battery symbols at different positions on the bottom bar. 
	//set the color theme for the Battery Symbol.
	symbols->drawEngineAlert(px-150,py-142);
	symbols->drawOilPresureAlert(px-75,py-142);
	symbols->setTheme(THEME_R,THEME_G,THEME_B);
	symbols->drawBatterySymbol(px-5,py-142);
	
	
	glColor3ub(240,80,68);
	symbols->drawABSAlert(px+72.5f,py-130);
	symbols->drawBreakAlert(px+120,py-130);
	glLoadIdentity();
	
	glColor3ub(255,0,0);
	symbols->drawCoolantSymbol(px+170,py-142);
	glLoadIdentity();
	
	
	//The btmbar and symbols objects are deleted to free up memory. 
	delete btmbar;
	delete symbols;
	
}
void renderingText(){

	glPushMatrix();

		glColor3f(1.0f, 1.0f, 1.0f);
		drawText("C", 1, (_WIDTH/2)+245,(_HEIGHT/2)+150, GLUT_BITMAP_HELVETICA_18,0);
		
		glColor3f(1.0f, 1.0f, 1.0f);
		drawText("H", 1, (_WIDTH/2)+345,(_HEIGHT/2)+150, GLUT_BITMAP_HELVETICA_18,0);
		drawText("KMH", 3, (_WIDTH/2)-295,(_HEIGHT/2)-70, GLUT_BITMAP_HELVETICA_12,0);
		drawText("0014750", 7,(_WIDTH/2)-315, (_HEIGHT/2)-135, GLUT_BITMAP_HELVETICA_18,0);
		
		glColor3f(1,0,0);
		drawText("-   +", 5, (_WIDTH/2)+5, (_HEIGHT/2)-135, GLUT_BITMAP_HELVETICA_12,1);
		
		glColor3ub(240,80,68);
		drawText("ABS", 3, (_WIDTH/2)+60, (_HEIGHT/2)-134, GLUT_BITMAP_HELVETICA_12,1);
		drawText("!", 1, (_WIDTH/2)+117, (_HEIGHT/2)-135, GLUT_BITMAP_HELVETICA_18,1);
		
		
		glColor3f(1,1,1);
		drawText("7 KM", 4,(_WIDTH/2)+50, (_HEIGHT/2)-55, GLUT_BITMAP_HELVETICA_18,0);
		drawText("25.0 'C", 7,_WIDTH-280, (_HEIGHT/2)-135, GLUT_BITMAP_HELVETICA_18,0);
		
		
		drawText("0", 1,(_WIDTH/2)+250, (_HEIGHT/2)-51, GLUT_BITMAP_HELVETICA_12,0);
		drawText("1", 1,(_WIDTH/2)+235, (_HEIGHT/2)-37, GLUT_BITMAP_HELVETICA_12,0);
		drawText("2", 1,(_WIDTH/2)+225, (_HEIGHT/2)-20, GLUT_BITMAP_HELVETICA_12,0);
		drawText("3", 1,(_WIDTH/2)+219, (_HEIGHT/2)-3, GLUT_BITMAP_HELVETICA_12,0);
		drawText("4", 1,(_WIDTH/2)+219, (_HEIGHT/2)+17, GLUT_BITMAP_HELVETICA_12,0);
		drawText("5", 1,(_WIDTH/2)+225, (_HEIGHT/2)+39, GLUT_BITMAP_HELVETICA_12,0);
		drawText("6", 1,(_WIDTH/2)+237, (_HEIGHT/2)+59, GLUT_BITMAP_HELVETICA_12,0);
		glColor3f(0.9f,0.25f,0);
		drawText("7", 1,(_WIDTH/2)+252, (_HEIGHT/2)+70, GLUT_BITMAP_HELVETICA_18,0);
		drawText("8", 1,(_WIDTH/2)+272, (_HEIGHT/2)+80, GLUT_BITMAP_HELVETICA_18,0);
		
		glLoadIdentity();
    glPopMatrix();
}

void drawCircleProgress(GLfloat cx, GLfloat cy,GLfloat r, float progress) {
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


void render(){


	glClearColor(BG_R,BG_G,BG_B, 1.0f); // Window background
	// Canvas settings
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, _WIDTH, 0, _HEIGHT); // Set canvas pixels.
	glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Render code here
	da2hboard();
	spe2dometer();
	gps();
	accelerometer();
	bottomBar();
	renderingText();
	

	
	
	


	
	
	glutSwapBuffers(); //Swap foreground and background frames.
	glutPostRedisplay(); //update the canvas display
	glFlush();
	glFinish();
}

int main(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(_WIDTH, _HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Car Dashboard");
	glutDisplayFunc(render); // Load render function.
	glutMainLoop(); // Loop frame forever.
	
	system("PAUSE");
	return 0;
}

