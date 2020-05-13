#pragma once
#ifndef GEOMETRY
#define GEOMETRY

#include "myglut.h"
#include <vector>
#include <string>

using namespace std;

class point {
private:
	int x;
	int y;

public:
    point() { x = y = 0; }
    point(float x1, float y1) { x = x1; y = y1; }

    void put_point() { glVertex2d(x, y); }

    point operator == (point& rv) {}

    point operator + (point rv) {
        point res(x + rv.x, y + rv.y);
        return point(x + rv.x, y + rv.y);
    }

    point& operator / (int rv) {
        point res(x / rv, y / rv);
        return res;
    }
};


class vec {
private:
    point a;
    point b;

public:
    vec() { a = b = point(0, 0); }
    vec(point p1, point p2) { a = p1, b = p2; }

    vec& operator + (vec& rv){}
    vec& operator == (vec& rv) {}
    vec& operator - () {}
    vec& operator * (int rv) {}
};


class figure {
private:
    point center;
    void(figure::* draw_function)(void);
    
    vector<point> additional_points; 
    void draw_circle(){}
    void draw_polygon(){}

public:
    figure() { center = point(0, 0); }
    figure(point center, int figure, vec param) {  // figure: 0 - circle, 1 - polygon, param: radius/diagonal
        draw_function = &draw_circle;
    }

    void draw() { (this->*draw_function)(); }
    void change_center(vec& speed) {}
};
#endif // !GEOMETRY
