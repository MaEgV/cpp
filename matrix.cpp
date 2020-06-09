#include"matrix.h"
#include <fstream>

using namespace std;

matrix::matrix(int n1, int m1) {
	n = n1;
	m = m1;
	field = new char*[n];
	for (int i = 0; i < n; i++) {
		field[i] = new char[m];
	}
}

void matrix::set(int i, int j, char value) {
	if (i < 600 && j < 600 && i > 0 && j > 0)
		field[i][j] = value;
}

void set_color(char param) {
	switch (param)
	{
	case 0:
		glColor3b(1, 1, 1);
		break;
	case 1:
		glColor3f(1, 0, 0);
		break;
	case 2:
		glColor3b(0, 1, 0);
		break;
	case 3:
		glColor3b(0, 0, 1);
		break;
	default:
		glColor3f(1, 1, 1);
		break;
	}
}

void matrix::change_coef(bool change){
	if (change)
		coef *= 1.1;
	else
		coef *= 0.9;
}

void matrix::draw() {
	glBegin(GL_POINTS);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			set_color(field[i][j]);
			glVertex2d((i - 350)*coef, (j - 300)*coef);
		}
	}
	glEnd();
}

void matrix::save(string& filename) {
	ofstream out;
	out.open(filename);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			out << field[i][j];
		}
		out << ' ';
	}
	out.close();
}

void matrix::load(string& filename) {
	ifstream in;
	in.open(filename);
	char tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> field[i][j];
		}
		in >> tmp;
	}
	in.close();
}
