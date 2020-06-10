#pragma once
#ifndef PRIMITIVES
#define PRIMITIVES

#include "cursor_mode.h"
#include <vector>


class primitives : public cursor_mode {
public:
	bool flag = false;
	vector<int>p1{ 0, 0 };
	vector<int>p2{ 0, 0 };

	void set_color(color_type c);

	void mouse_position(int x, int y);

	void change_size(int change) override {};

};

#endif // !PRIMITIVES
