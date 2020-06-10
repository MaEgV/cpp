#pragma once

#include"simple_primitive.h"

void primitives::set_color(color_type c) {
	color = c;
}

void primitives::mouse_position(int x, int y) {
	if (lcm) {
		if (!flag) {
			flag = !flag;
			p1[0] = x;
			p1[1] = 600 - y;
		}
	}
	else if (flag) {
		draw(x, 600 - y);
		flag = !flag;
	}
}