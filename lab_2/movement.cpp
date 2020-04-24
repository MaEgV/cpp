#include "movement.h"

using namespace std;


float red = 1, blue = 1, green = 1;

Cut Myline = Cut(Point(-1, 0), Point(1, 1));
Cut speed = Cut(Point(0.01, 0.01), Point(0.01, 0.01));

void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Cut :: StandardBorders() {
	glBegin(GL_LINE_STRIP);
	Point(-3, -3).PutPoint();
	Point(-3, 3).PutPoint();
	Point(3, 3).PutPoint();
	Point(3, -3).PutPoint();
	Point(-3, -3).PutPoint();
	glEnd();
}

void Cut :: DrawLine() {
	glColor3f(red, green, blue);
	glLineWidth(3);
	glBegin(GL_LINES);
	p1.PutPoint();
	p2.PutPoint();
	glEnd();
}

void Cut :: DrawTrace(Cut& speed) {
	glColor3f(red / 2, green / 2, blue / 2);
	glBegin(GL_POLYGON);
	p1.PutPoint();
	p2.PutPoint();
	(p2 - speed.p2 * 5).PutPoint();
	(p1 - speed.p1 * 5).PutPoint();
	glEnd();
}

void Cut :: ChekPos(Cut& speed) {
	if (Myline.p1.CmpX(Point(-3, -3)) || Point(3, 3).CmpX(Myline.p1)) {
		speed.ReverseX();
	}
	else if (Myline.p1.CmpY(Point(-3, -3)) || Point(3, 3).CmpY(Myline.p1)) {
		speed.ReverseY();
	}
	else if (Myline.p2.CmpX(Point(-3, -3)) || Point(3, 3).CmpX(Myline.p2)) {
		speed.ReverseX();
	}
	else if (Myline.p2.CmpY(Point(-3, -3)) || Point(3, 3).CmpY(Myline.p2)) {
		speed.ReverseY();
	}
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);

	Myline.StandardBorders();
	
	Myline.DrawLine();

	Myline.DrawTrace(speed);

	Myline += speed;

	Myline.ChekPos(speed);

	glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}

void processSpecialKeys(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_F1:
		red = 1.0;
		green = 0.0;
		blue = 0.0; break;
	case GLUT_KEY_F2:
		red = 0.0;
		green = 1.0;
		blue = 0.0; break;
	case GLUT_KEY_F3:
		red = 0.0;
		green = 0.0;
		blue = 1.0; break;
	case GLUT_KEY_LEFT:
		speed += Vec(Point(-0.01, 0), Point(-0.01, 0));
		break;
	case GLUT_KEY_DOWN:
		speed += Vec(Point(0, -0.01), Point(0, -0.01));
		break;
	case GLUT_KEY_RIGHT:
		speed += Vec(Point(0.01, 0), Point(0.01, 0));
		break;
	case GLUT_KEY_UP:
		speed += Vec(Point(0, 0.01), Point(0, 0.01));
		break;
	}
}
