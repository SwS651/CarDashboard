#include <windows.h>
#include <gl/glut.h>
#include <string>
#include <sstream>

#include "Dashboard.h"
#include "Speedometer.h"
#include "Gps.h"
#include "Accelerometer.h"
#include "Symbol.h"
#include "BottomBar.h"

#include "CustomFont.h"

using namespace std;

const int _WIDTH = 1200;
const int _HEIGHT = 720;

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

// Keyboard Event Variable
bool leftSignalFlag = false;
bool rightSignalFlag = false;
bool accelerateFlag = false;
bool deccelerateFlag = false;
bool reverseGearFlag = false;

GLfloat acceleration = 0.0f;
GLfloat decceleration = 0.0f;

GLint speed = 0;//in KM/H
GLfloat speed_float = 0.0f;
GLfloat distanceTravel = 14750.0f; //in KM

GLfloat px = (_WIDTH/2)-280;
GLfloat py = _HEIGHT/2;

bool isCarBooting = false;
bool isCarStarted = false;
bool isGPSSet = false;

GLfloat yNavVel = 10;
GLfloat navline = 160;
GLboolean isMove = false; //default = true
GLfloat distanceRemaining = 756; //default = 756

string int2StringConvert(GLint value){
	//Convert int to string
	stringstream ss;
	ss << value;
	
	string valueStr = ss.str();
	
	return valueStr;
}

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
	if(pFlag)
		pointerAng+=1;
	else
		pointerAng-=1;
	
	
	//Speedometer;  360-90 (0 -> full kmh)
	if (pointerAng == 90) 
  		pFlag = true;
	if (pointerAng >= 359) 
		pFlag=false;
}

void accelerationCalculate(){
	GLfloat pointerAng_temp = pointerAng;
	if(pointerAng <= 90){
		pointerAng_temp = 90;
		acceleration = 0;
	}
	if(pointerAng >= 359){
		pointerAng_temp = 359;
		decceleration = 0;
	}

	if (pointerAng_temp >= 90 && accelerateFlag){ //accelerate
		if(decceleration > 0.0)
			decceleration -= 0.0015;
		
		else if(acceleration < 1.0)
			acceleration += 0.0005;
		pointerAng_temp -= acceleration;
	}
	if(pointerAng_temp >= 90 && !accelerateFlag){
		if(acceleration > 0.0)
			acceleration -= 0.0015;
		if(acceleration <= 0)
			acceleration = 0;
		pointerAng_temp -= acceleration;
	}
	
	if (pointerAng_temp <= 359 && deccelerateFlag){ //deccelerate
		if(acceleration > 0.0)
			acceleration -= 0.0015;
			
		else if(decceleration < 1.0)
			decceleration += 0.0005;
		pointerAng_temp += decceleration;
	}
	if(pointerAng_temp <= 359 && !deccelerateFlag){
		if(decceleration > 0.0)
			decceleration -= 0.0015;
		if(decceleration <= 0)
			decceleration = 0;
		pointerAng_temp += decceleration;
	}
	
	//change position of the speedometer's needel
	//if(isGPSSet)
		pointerAng = pointerAng_temp;
	
	speed = 359 - pointerAng;
	
	if(speed > 0){
		isMove = true;
		distanceTravel = distanceTravel + (static_cast<float>(speed)/ 2400); //default: 1000
	}
}
void spe2dometer(GLfloat px, GLfloat py){
	GLfloat cx = (px/2)+23;
	GLfloat cy = py+9;
	Speedometer* speedometer = new Speedometer();
	speedometer->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	speedometer->setPosition(cx,cy);
	speedometer->circlePrgs = pointerAng;
	speedometer->outerCircle();
	speedometer->circlePoint();
	
	speedometer->pointer();
	speedometer->coreCircle(); 
	//speedoPointer();   //Animation

	if(isCarStarted)
		accelerationCalculate();

	delete speedometer;
}

//CenterPoint => X: 600  Y: 160
//Y =115  set the crossroad above the map 
void gps(GLfloat px, GLfloat py,GLboolean isGPSSet){
	GLfloat cx = px;
	GLfloat cy = py;
	Gps* gPs = new Gps();
	gPs->setRoadColor(0.8157f,0.8078f,0.8078f);
	gPs->setPosition(px,py+20);
	gPs->draw();
	gPs->drawCrossRoad(yNavVel);  
		
	if(isGPSSet){
		gPs->drawNavigation(navline);
		glColor3f(1,1,1);
		drawText("7 KM", 4,cx+50, cy-55, GLUT_BITMAP_HELVETICA_18,0);
	}
		
	//GPS Animation here
	/*
		Car starts moving.
		If the roadintersection drops out of sight, 
		set its position above the map and stop moving.
	*/
	
	//Control Speed of the nav moving
	speed_float = static_cast<float>(speed);
	speed_float = (speed_float/100) * 0.5;
	
	//if(reverseGearFlag) //got problem!!!
	//	speed_float *= -1;
	
	if(isMove)
	{
		if(yNavVel>=(py-313))
			//yNavVel-=0.5f;
			yNavVel = yNavVel - speed_float;
		else
		{
			yNavVel=115;
			isMove=false;
		}
	}
	
	/*If the remaining distance is equal to this number, 
	its position is at the road intersection position above the map. 
	The road intersection starts moving with cyan navigation
	*/
	if(distanceRemaining==220)
		isMove = true;
	if(distanceRemaining <=160)
		//navline-=1;
		navline = navline - speed_float; //length of cyan line decreassing in nav
		
	if(distanceRemaining>=0)
		//distanceRemaining-=1;
		distanceRemaining = distanceRemaining - speed_float;
	else{
		navline = 0;
		isMove = false;
	}
		 
	
	delete gPs;
}

void accelerometer(GLfloat cx, GLfloat cy){
	GLfloat px = cx;
	GLfloat py = cy;
	/*Rotation Angle
		0  	= 0
		1 	= -12
		2 	= -26
		3	= -40
		4	= -55
		5	= -70
		6	= -88
		7	= -105
		8	= -122 and above
	*/
	Accelerometer* accmeter = new Accelerometer();
	Symbol* symbols = new Symbol();

	//Draw an accelerometer
	accmeter->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	accmeter->setPosition(px+300,py+15);
	
	//Set variable pointer
	

	accmeter->accProgress = -30;  
	accmeter->status = false;
	accmeter->display();
	
	glColor3f(0.4f,1,1);
	symbols->drawCoolantSymbol(px+300,py+155.5f);
	
	delete accmeter;
	delete symbols;
}

GLint pnn = 0;


void bottomBar(GLfloat cx, GLfloat cy){
	
	GLfloat px = cx;
	GLfloat py = cy;
	
	BottomBar* btmbar = new BottomBar();
	Symbol* symbols = new Symbol();
	
	if(isCarStarted) isCarBooting = false;  //If car started, car warning signs will not appear
		
	btmbar->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	btmbar->setPosition(px,py);
	btmbar->drawBottomBar();
	
	
	//Set speed at here!!!
	if(isCarStarted || isCarBooting)
		btmbar->drawSpeedText(122);
	

		
	//draw engine alert, oil pressure alert, and battery symbols at different positions on the bottom bar. 
	//set the color theme for the Battery Symbol.
	//When car is bootting, all symbols will display
	//If car is not started and booting = true
	if(!isCarStarted && isCarBooting){
		symbols->drawEngineAlert(px-150,py-142);
		symbols->drawOilPresureAlert(px-75,py-142);
		symbols->setTheme(THEME_R,THEME_G,THEME_B);
		
		
		symbols->drawBatterySymbol(px-5,py-142);
		glColor3f(1,0,0);
		drawText("-   +", 5, cx+5, cy-135, GLUT_BITMAP_HELVETICA_12,1);
		
		glColor3ub(240,80,68);
		drawText("ABS", 3, cx+60, cy-134, GLUT_BITMAP_HELVETICA_12,1);
		symbols->drawABSAlert(px+72.5f,py-130);

	}
	
	//If car is started
	if(isCarStarted || isCarBooting){
		drawText("!", 1, cx+117, cy-135, GLUT_BITMAP_HELVETICA_18,1);
		glColor3ub(240,80,68);
		symbols->drawBreakAlert(px+120,py-130);
		glLoadIdentity();
	}
	
	
	glColor3ub(255,0,0);
	//symbols->drawCoolantSymbol(px+170,py-142);
	glLoadIdentity();
	
	
	//The btmbar and symbols objects are deleted to free up memory. 
	delete btmbar;
	delete symbols;
	
}
void renderingText(GLfloat px, GLfloat py){
	GLfloat cx = px;
	GLfloat cy = py;

	glPushMatrix();

	if(isCarStarted || isCarBooting){
		glColor3f(1.0f, 1.0f, 1.0f);
		drawText("KMH", 3, cx-295,cy-70, GLUT_BITMAP_HELVETICA_12,0);
		drawText(int2StringConvert(distanceTravel).data(), 7,cx-315, cy-135, GLUT_BITMAP_HELVETICA_18,0);
		
		glColor3f(1,1,1);
		drawText("25.0 'C", 7,_WIDTH-280, cy-135, GLUT_BITMAP_HELVETICA_18,0);
		
	}
		glColor3f(1.0f, 1.0f, 1.0f);
		drawText("C", 1, cx+245,cy+150, GLUT_BITMAP_HELVETICA_18,0);
		drawText("H", 1, cx+345,cy+150, GLUT_BITMAP_HELVETICA_18,0);
		
		drawText("0", 1,cx+250, cy-51, GLUT_BITMAP_HELVETICA_12,0);
		drawText("1", 1,cx+235, cy-37, GLUT_BITMAP_HELVETICA_12,0);
		drawText("2", 1,cx+225, cy-20, GLUT_BITMAP_HELVETICA_12,0);
		drawText("3", 1,cx+219, cy-3, GLUT_BITMAP_HELVETICA_12,0);
		drawText("4", 1,cx+219, cy+17, GLUT_BITMAP_HELVETICA_12,0);
		drawText("5", 1,cx+225, cy+39, GLUT_BITMAP_HELVETICA_12,0);
		drawText("6", 1,cx+237, cy+59, GLUT_BITMAP_HELVETICA_12,0);
		glColor3f(0.9f,0.25f,0);
		drawText("7", 1,cx+252, cy+70, GLUT_BITMAP_HELVETICA_18,0);
		drawText("8", 1,cx+272, cy+80, GLUT_BITMAP_HELVETICA_18,0);
		
		glLoadIdentity();
    glPopMatrix();
}

int signalCount = 0; // To make signals flashing
void signalsAnimation(string signal ="both"){
	Symbol* signals = new Symbol();
	
	if(signalCount>=20 && signalCount<=40 && !isCarBooting){
		
		if(signal=="left" || signal == "both")
			signals->drawLeftSignal(_WIDTH/2,_HEIGHT/2-215);
		if(signal=="right"|| signal == "both")
			signals->drawRightSignal(_WIDTH/2,_HEIGHT/2-215);
	}else if(isCarBooting){
		
		if(signal=="left" || signal == "both")
			signals->drawLeftSignal(_WIDTH/2,_HEIGHT/2-215);
		if(signal=="right"|| signal == "both")
			signals->drawRightSignal(_WIDTH/2,_HEIGHT/2-215);
	}
	
	//Reset countdown
	if(signalCount >= 40)
		signalCount =0;
	else
		signalCount+=1;
	
	delete signals;
}

void carDashboard(){
	GLfloat px = _WIDTH/2;
	GLfloat py = _HEIGHT/2 - 200;
	Dashboard* dashboard = new Dashboard();
	Accelerometer* accelerometer = new Accelerometer();
	Symbol* symbols = new Symbol();
	
	
	//Car started, 
	//isCarStarted = true;
	//isCarBooting = false;
	
	//If car is started, then booting state change to false
	if(isCarStarted && isCarBooting){
		Sleep(1000); //Set Delay 1 second
		isCarBooting =false;
	}
		
	//All render code at here!!!
	dashboard->setColor(THEME_R,THEME_G,THEME_B,1);
	dashboard->setPosition(px,py);
	dashboard->draw();
	
	
	//Accelerometer Configuration 
	accelerometer->setBackgroundColor(THEME_R,THEME_G,THEME_B);
	accelerometer->setPosition(px+300,py+15);
	
	if(isCarStarted)
		accelerometer->accProgress = -10 + speed_float * -85;//default = -70; //Set variable here !!!
	else
		accelerometer->accProgress = 0;
	
	if(isCarStarted || isCarBooting)
		accelerometer->status = true;
	else accelerometer->status = false;
	accelerometer->display();
	
	if(isCarBooting)
		signalsAnimation();   //Parameter: left, right, both
	else if(isCarStarted){
		//signalsAnimation();
		if(leftSignalFlag){
			signalsAnimation("left");
		}
		if(rightSignalFlag){
			signalsAnimation("right");
		}
		if(leftSignalFlag && rightSignalFlag){
			signalsAnimation("both");
		}
	}
	
	if(isCarStarted || isCarBooting){
		//accelerometer->displayGear("N");  //Parameter: N, R, D4
		
		//if set GPS
			//gps(px,py,true);
		//else	
			//gps(px,py,true);
		if(isGPSSet){
			gps(px, py, true);
			//accelerometer->displayGear("D4");
			if(!reverseGearFlag)
				accelerometer->displayGear("D4");
			else
				accelerometer->displayGear("R");
		}
		else{
			gps(px, py, false);
			accelerometer->displayGear("N");
		}
		glColor3f(0.4f,1,1);
		symbols->drawCoolantSymbol(px+300,py+155.5f);
	}
	spe2dometer(px,py);
	bottomBar(px,py);

	//	A dark overlay covers the dashboard when the car is in not started state
	if(!isCarStarted && !isCarBooting){
		dashboard->setColor(0.0147,0.1418,0.2902,0.5);
		dashboard->setPosition(px,py);
		dashboard->draw();
	}
	renderingText(px,py);
	
	//In Car on Booting State
	if(isCarBooting){ 
		isCarStarted = true;
	}
	
	delete accelerometer;
	delete symbols;
	delete dashboard;
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
	//carDashboard(true);
	carDashboard();

	
	/****Test CustomFont****/
	//CustomFont* number = new CustomFont();
	//number->setPosition(_WIDTH/2-70,_HEIGHT/2);
	//glColor3f(1,0,1);
	//number->drawRect(_WIDTH/2,_HEIGHT/2,30,38);
	//number->draw1(_WIDTH/2,_HEIGHT/2);
	//number->setFontText(_WIDTH/2-260,_HEIGHT/2,"102131415161718191");
	//delete number;
	
	glutSwapBuffers(); //Swap foreground and background frames.
	glutPostRedisplay(); //update the canvas display
	glFlush();
	glFinish();
}


void onKeyboardReleased(unsigned char key, GLint x, GLint y){
	switch(key){
		case 'w': case 'W': accelerateFlag = false; // Accelerate
			break;
		case 'a': case 'A': //leftSignalFlag = false; // Left Signal
			break;
		case 's': case 'S': deccelerateFlag = false; // Deccelerate
			break;
		case 'd': case 'D': //rightSignalFlag = false; // Right Signal
			break;
		case 'p': case 'P': // Refill fuel
			break;
		case 27: break;
	}
	glutPostRedisplay();
}

void onKeyboardPressed(unsigned char key, GLint x, GLint y){
	switch(key){
		case 'w': case 'W': accelerateFlag = true; // Accelerate
			break;
		case 'a': case 'A': //leftSignalFlag = true; // Left Signal
			if(leftSignalFlag)
				leftSignalFlag = false; // Left Signal
			else
				leftSignalFlag = true;
			break;
		case 's': case 'S': deccelerateFlag = true; // Deccelerate
			break;
		case 'd': case 'D': //rightSignalFlag = true; // Right Signal
			if(rightSignalFlag)
				rightSignalFlag = false; // Right Signal
			else
				rightSignalFlag = true;
			break;
		case 'l': case 'L': isGPSSet = true;
			break;
		case 'o': case 'O': isCarBooting = true;
			break;
		case 'p': case 'P': // Refill fuel
			break;
		case 'r': case 'R': //reverseGearFlag = true;//Reverse Gear
			if(reverseGearFlag)
				reverseGearFlag = false;
			else
				reverseGearFlag = true;
			break;
		case 27: break;
	}
	glutPostRedisplay();
}

void onSpecialKeyboardReleased(GLint key, GLint x, GLint y){
	switch(key){
		case GLUT_KEY_UP: accelerateFlag = false;// Accelerate
		break;
		case GLUT_KEY_DOWN: deccelerateFlag = false; // Deccelerate
		break;
		case GLUT_KEY_LEFT: //leftSignalFlag = false; // Left Signal
		break;
		case GLUT_KEY_RIGHT: //rightSignalFlag = false; // Right Signal
		break;
		case GLUT_KEY_HOME: break;
	}
}

void onSpecialKeyboardPressed(GLint key, GLint x, GLint y){
	switch(key){
		case GLUT_KEY_UP: accelerateFlag = true;// Accelerate
		break;
		case GLUT_KEY_DOWN: deccelerateFlag = true;// Deccelerate
		break;
		case GLUT_KEY_LEFT: //leftSignalFlag = true;// Left Signal
			if(leftSignalFlag)
				leftSignalFlag = false; // Left Signal
			else
				leftSignalFlag = true;
			break;
		case GLUT_KEY_RIGHT: //rightSignalFlag = true;// Right Signal
			if(rightSignalFlag)
				rightSignalFlag = false; // Right Signal
			else
				rightSignalFlag = true;
			break;
		case GLUT_KEY_HOME: break;
	}
}

int main(){
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(_WIDTH,_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Car Dashboard");
	glutDisplayFunc(render); // Load render function.
	
	glutKeyboardFunc(onKeyboardPressed);
	glutKeyboardUpFunc(onKeyboardReleased);
	
	glutSpecialFunc(onSpecialKeyboardPressed);
	glutSpecialUpFunc(onSpecialKeyboardReleased);
	
	glutMainLoop(); // Loop frame forever.
	
	system("PAUSE");
	return 0;
}

