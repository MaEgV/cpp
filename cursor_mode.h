#pragma once
#ifndef CURSOR_MODE
#define CURSOR_MODE

#include "matrix.h"

class cursor_mode {
public:
	static matrix* field;
	static bool lcm;
	static bool ccm;
	static bool rcm;

	int size;
	color_type color;

	virtual void draw(int x, int y) = 0;

	virtual void mouse_position(int x, int y) = 0;  // Обработка движений мыши, учитывая нажатые кнопки

	virtual void set_color(color_type c) = 0;

	virtual void change_size(int change) = 0;  // changing with button ('-'/'+')

};

#endif // !CURSOR_MODE
