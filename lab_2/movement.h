#include <stdlib.h>
#include <math.h>
#include <glut.h>

using namespace std;

class Point {
private:
	float x;
	float y;

public:
	Point() { x = 0, y = 0; };
	Point(float x1, float y1) { x = x1, y = y1; };


	float Getx(void) { return x; };
	float Gety(void) { return y; };


	void Setx(float x1) { x = x1; };
	void Sety(float y1) { y = y1; };


	Point& operator += (Point rv) {
		x += rv.Getx();
		y += rv.Gety();
		return *this;
	}

	const Point operator - (Point rv) {
		return(Point(x - rv.Getx(), y - rv.Gety()));
	}

	const Point operator - () {
		return(Point(-x, -y));
	}

	const Point operator + (Point rv) {
		return(Point(x + rv.Getx(), y + rv.Gety()));
	}
};

class Vec {
private:
	Point p1;
	Point p2;
public:
	Vec(Point a, Point b) { p1 = a, p2 = b; };
	
	
	Point GetP1() { return p1; };
	Point GetP2() { return p2; };


	void RevX() {
		p1.Setx(-p1.Getx());
		p2.Setx(-p2.Getx());
	}
	void RevY() {
		p1.Sety(-p1.Gety());
		p2.Sety(-p2.Gety());
	}


	Vec& operator += (Vec rv) {
		p1 += rv.GetP1();
		p2 += rv.GetP2();
		return *this;
	}

	Vec& operator = (Vec rv) {
		p1 = rv.GetP1();
		p2 = rv.GetP2();
		return *this;
	}

	const Vec operator - (Vec rv) {
		return(Vec(p1 - rv.GetP1(), p2 - rv.GetP2()));
	}

	const Vec operator - () {
		return(Vec(-p1, -p2));
	}

	const Vec operator + (Vec rv) {
		return(Vec(p1 + rv.GetP1(), p2 + rv.GetP2()));
	}
};

void changeSize(int w, int h); // controlling the proportions of the window

void renderScene(void); // the render function

void processNormalKeys(unsigned char key, int x, int y); // esc

void processSpecialKeys(int key, int x, int y); // (f1, f2, f3)colors, (up, down,left, right)speed control
