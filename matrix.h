#pragma once
#ifndef MATRIX
#define MATRIX

#include <vector>
#include <glut.h>
#include <string>

using namespace std;

typedef enum {
	RED = 1,
	GREEN,
	BLUE
}color_type;

class matrix {
private:
	char** field;
	int n;
	int m;
	float coef = 1;
public:
	matrix(int n1, int m1);

	void set(int i, int j, char value);

	void draw();

	void save(string& filename);

	void load(string& filename);

	void change_coef(bool change);

};


#endif // !MATRIX
