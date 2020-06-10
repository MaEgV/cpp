#pragma once
#include"brush.h"


brush::brush() {
	size = 4;
	color = RED;
}


void brush::set_color(color_type c) {
	color = c;
}