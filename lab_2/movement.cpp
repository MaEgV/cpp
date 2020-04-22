#include "movement.h"

using namespace std;


float red = 1.0f, blue = 1.0f, green = 1.0f;


Vec Myline = Vec(Point(-1, 0), Point(1, 1));
Vec speed = Vec(Point(0.01, 0.01), Point(0.01, 0.01));


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


void StandardBorders() {
	glBegin(GL_LINE_STRIP);
	glVertex2d(-3, -3);
	glVertex2d(-3, 3);
	glVertex2d(3, 3);
	glVertex2d(3, -3);
	glVertex2d(-3, -3);
	glEnd();
}

void DrawLine(Vec Myline) {
	glColor3f(red, green, blue);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2d(Myline.GetP1().Getx(), Myline.GetP1().Gety());
	glVertex2d(Myline.GetP2().Getx(), Myline.GetP2().Gety());
	glEnd();
}

void DrawTrace(Vec Myline, Vec speed) {
	glColor3f(red / 2, green / 2, blue / 2);
	glBegin(GL_POLYGON);
	glVertex2d(Myline.GetP1().Getx(), Myline.GetP1().Gety());
	glVertex2d(Myline.GetP2().Getx(), Myline.GetP2().Gety());
	glVertex2d(Myline.GetP2().Getx() - 5 * speed.GetP2().Getx(), Myline.GetP2().Gety() - 5 * speed.GetP2().Gety());
	glVertex2d(Myline.GetP1().Getx() - 5 * speed.GetP2().Getx(), Myline.GetP1().Gety() - 5 * speed.GetP1().Gety());
	glEnd();
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);

	StandardBorders();
	
	DrawLine(Myline);

	DrawTrace(Myline, speed);

	Myline += speed;

	// check position
	if (Myline.GetP1().Getx() <= -3 || Myline.GetP1().Getx() >= 3 || Myline.GetP2().Getx() <= -3 || Myline.GetP2().Getx() >= 3) {
		speed.RevX();
	}
	else if (Myline.GetP1().Gety() <= -3 || Myline.GetP1().Gety() >= 3 || Myline.GetP2().Gety() <= -3 || Myline.GetP2().Gety() >= 3) {
		speed.RevY();
	}

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
