#pragma once
#ifndef POLYGON
#define POLYGON

#include "simple_primitive.h"

class polygon : public primitives {
public:
	polygon();

	void draw(int x, int y) override;
};


class line : public primitives {
public:
	line();

	void draw(int x, int y) override;
};


class circle : public primitives {
public:
	circle();

	void draw(int x, int y) override;
};

#endif // !POLYGON
