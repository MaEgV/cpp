#pragma once
#ifndef BRUSH
#define BRUSH

#include "simple_brush.h"

class brush : public simple_brush {
public:
	brush();

	void set_color(color_type c) override;

};

#endif