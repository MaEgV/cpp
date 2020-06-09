#ifndef PAINT
#define PAINT

#include "menu.h"
#include "grafic_editor.h"

using namespace std;

class paint {
private:
	draw_system* current_system;

public:
	paint();

	void draw();

	void click(int button, int state, int x, int y);

	void active_move(int x, int y);

	void passive_move(int x, int y);

	void keyboard(int key);

	void set_system(draw_system* new_system);

	void save(string& filename);

	void load(string& filename);

};

#endif // !PAINT
