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

	void ReverseX() { x = -x; };
	void ReverseY() { y = -y; };

	int CmpY(Point rv) {
		if (y <= rv.y)
			return 1;
		return 0;
	}

	int CmpX(Point rv) {
		if (x <= rv.x)
			return 1;
		return 0;
	}

	void PutPoint() {
		glVertex2d(x, y);
	}

	Point& operator += (Point& rv) {
		x += rv.x;
		y += rv.y;
		return *this;
	}

	Point operator - (Point rv) {
		return(Point(x - rv.x, y - rv.y));
	}

	Point operator * (int rv) {
		return Point(x * rv, y * rv);
	}

	Point operator - () {
		return(Point(-x, -y));
	}

	Point operator + (Point& rv) {
		return(Point(x + rv.x, y + rv.y));
	}
};


class Vec {
protected:
	Point p1;
	Point p2;

public:
	Vec(Point a, Point b) { p1 = a, p2 = b; };
	
	void ReverseX() {
		p1.ReverseX();
		p2.ReverseX();
	}

	void ReverseY() {
		p1.ReverseY();
		p2.ReverseY();
	}

	int CheckY(Point& rv) {
		if (p1.CmpY(rv) || p2.CmpY(rv))
			return 1;
		return 0;
	}

	int CheckX(Point& rv) {
		if (p1.CmpX(rv) || p2.CmpX(rv))
			return 1;
		return 0;
	}

	Vec& operator += (Vec rv) {
		p1 += rv.p1;
		p2 += rv.p2;
		return *this;
	}

	Vec& operator = (Vec rv) {
		p1 = rv.p1;
		p2 = rv.p2;
		return *this;
	}

	const Vec operator - (Vec rv) {
		return(Vec(p1 - rv.p1, p2 - rv.p2));
	}

	const Vec operator - () {
		return(Vec(-p1, -p2));
	}

	const Vec operator + (Vec rv) {
		return(Vec(p1 + rv.p1, p2 + rv.p2));
	}
};


class Cut : public Vec {
public:
	Cut(Point a, Point b) : Vec(a, b) {};

	void StandardBorders();
	void DrawLine();
	void DrawTrace(Cut& speed);
	void ChekPos(Cut& speed);
};


void renderScene();
void changeSize(int w, int h); // controlling the proportions of the window
void processNormalKeys(unsigned char key, int x, int y); // esc
void processSpecialKeys(int key, int x, int y); // (f1, f2, f3)colors, (up, down,left, right)speed control
