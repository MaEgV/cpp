#pragma once
#ifndef SIMPLE_BRUSH
#define SIMPLE_BRUSH

#include "cursor_mode.h"

class simple_brush : public cursor_mode {
public:
	virtual void change_size(int change) override;  // changing with button ('-'/'+')

	void draw(int x, int y) override;

	void mouse_position(int x, int y) override;

};

#endif // !SIMPLE_BRUSH
