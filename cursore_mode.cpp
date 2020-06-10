#include "cursor_mode.h"

matrix* cursor_mode::field = new matrix(600, 700);

bool cursor_mode::lcm = false;
bool cursor_mode::ccm = false;
bool cursor_mode::rcm = false;