#pragma once
#ifndef ERASER
#define ERASER

#include "simple_brush.h"

class eraser : public simple_brush {
public:
	eraser();

	void set_color(color_type c) override {};

};

#endif