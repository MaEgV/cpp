#pragma once
#ifndef LEVEL
#define LEVEL

#include "game_objects.h"
#include <vector>
#include<string>

using namespace std;

class level {
private:
	void end_game(); // lives = 0

public:
	level(string& file_name);  // init level

	void start_game();  // draw level
}

#endif // !LEVEL
