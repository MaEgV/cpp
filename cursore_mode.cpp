#include "cursor_mode.h"

matrix* cursor_mode::field = new matrix(600, 700);

bool cursor_mode::mouse_left = false;
bool cursor_mode::mouse_central = false;
bool cursor_mode::mouse_right = false;