#pragma once

#include"primitives.h"

polygon::polygon() {
	color = RED;
}


int max(int cmp1, int cmp2) {
	if (cmp1 > cmp2)
		return cmp1;
	return cmp2;
}

int min(int cmp1, int cmp2) {
	if (cmp1 > cmp2)
		return cmp2;
	return cmp1;
}

void polygon::draw(int x, int y) {
	for (int i = min(p1[0], x); i < max(p1[0], x); i++) {
		field->set(i, p1[1], color);
		field->set(i, y, color);
	}
	for (int i = min(p1[1], y); i < max(p1[1], y); i++) {
		field->set(p1[0], i, color);
		field->set(x, i, color);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


line::line() {
	color = RED;
}

int f(int x, int x1, int x2, int y1, int y2) {
	return float(x - x1) / (x2 - x1) * (y2 - y1) + y1;
}

void line::draw(int x, int y) {
	int x1 = min(p1[0], x);
	int x2 = max(p1[0], x);
	int y2 = y;
	int y1 = p1[1];

	if (x1 == x) {
		y1 = y;
		y2 = p1[1];
	}

	for (int i = x1; i < x2; i++) {
		field->set(i, f(i, x1, x2, y1, y2), color);
	}
	for (int i = y1; i < y2; i++) {
		field->set(f(i, y1, y2, x1, x2), i, color);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////


circle::circle() {
	color = RED;
}

void circle::draw(int x, int y) {
	int x1 = min(p1[0], x);
	int x2 = max(p1[0], x);
	int y2 = y;
	int y1 = p1[1];

	if (x1 == x) {
		y1 = y;
		y2 = p1[1];
	}

	for (int i = 0; i < 400; i++) {
		int r = (x1 - x2);
		float angle = 2.0 * 3.1415926 * float(i) / float(400);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		field->set(x + dx, y + dy, color);
	}
}
