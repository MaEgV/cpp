#pragma once
#ifndef SYSTEM
#define SYSTEM
#include <string>

using namespace std;

class draw_system {
public:
	virtual void render() = 0;

	virtual void mouse_call(int button, int state, int x, int y) = 0;
};

#endif // !SYSTEM
