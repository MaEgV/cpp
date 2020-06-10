#include"simple_brush.h"

void simple_brush::change_size(int change) {
	size += change;
}

void simple_brush::draw(int x, int y) {
	for (int i = x - size; i < x + size; i++) {
		for (int j = y - size; j < y + size; j++) {
			field->set(i, j, color);
		}
	}
}

void simple_brush::mouse_position(int x, int y) {
	if (lcm) {
		draw(x, 600 - y);
	}
}
