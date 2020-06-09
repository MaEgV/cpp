#include "grafic_editor.h"

matrix* field = new matrix(600, 700);
brush* brush_mode = new brush;
eraser* eraser_mode = new eraser;
polygon* polygon_mode = new polygon;
line* line_mode = new line;
circle* circle_mode = new circle;
cursor_mode* current_mode = brush_mode;

bool lcm = false;
bool ccm = false;
bool rcm = false;


///////////////////////////////////////////////////////////////////////////////////////////


editor_launcher::editor_launcher(string file_name) {
	if (file_name.size() == 0)
		return;
}

void editor_launcher::render() {
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	field->draw();

	glutSwapBuffers();
}

void editor_launcher::active_move(int x, int y){
	current_mode->mouse_position(x, y);
}

void editor_launcher::passive_move(int x, int y) {
	current_mode->mouse_position(x, y);
}

void editor_launcher::mouse_call(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		lcm = false;
		if (state == GLUT_DOWN)
			lcm = true;
		break;
	case GLUT_RIGHT_BUTTON:
		rcm = false;
		if (state == GLUT_DOWN)
			rcm = true;
		break;
	case GLUT_MIDDLE_BUTTON:
		ccm = false;
		if (state == GLUT_DOWN)
			ccm = true;
		break;
	}
}

void editor_launcher::keys(int key) {
	switch (key) {
	case GLUT_KEY_F1:
		current_mode = brush_mode;
		break;
	case GLUT_KEY_F2:
		current_mode = eraser_mode;
		break;
	case GLUT_KEY_F3:
		current_mode = line_mode;
		break;
	case GLUT_KEY_F4:
		current_mode = polygon_mode;
		break;
	case GLUT_KEY_F5:
		current_mode = circle_mode;
		break;
	case GLUT_KEY_F6:
		current_mode->set_color(RED);
		break;
	case GLUT_KEY_F7:
		current_mode->set_color(BLUE);
		break;
	case GLUT_KEY_UP:
		current_mode->change_size(1);
		break;
	case GLUT_KEY_DOWN:
		current_mode->change_size(-1);
		break;
	case GLUT_KEY_LEFT:
		field->change_coef(false);
		break;
	case GLUT_KEY_RIGHT:
		field->change_coef(true);
		break;
	}
}

void editor_launcher::save(string& filename) {
	field->save(filename);
}

void editor_launcher::load(string& filename) {
	field->load(filename);
}


///////////////////////////////////////////////////////////////////////////////////////////

void main_brush::change_size(int change) {
	size += change;
}

void main_brush::draw(int x, int y) {
	for (int i = x - size; i < x + size; i++) {
		for (int j = y - size; j < y + size; j++) {
			field->set(i, j, color);
		}
	}
}

void main_brush::mouse_position(int x, int y) {
	if (lcm) {
		draw(x, 600 - y);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////

brush::brush() {
	size = 4;
	color = RED;
}


void brush::set_color(color_type c) {
	color = c;
}


///////////////////////////////////////////////////////////////////////////////////////////


eraser::eraser() {
	size = 4;
}


///////////////////////////////////////////////////////////////////////////////////////////


void primitives::set_color(color_type c) {
	color = c;
}

void primitives::mouse_position(int x, int y) {
	if (lcm) {
		if (!flag) {
			flag = !flag;
			p1[0] = x;
			p1[1] = 600 - y;
		}
	}
	else if (flag) {
		draw(x, 600 - y);
		flag = !flag;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


polygon::polygon() {
	color = RED;
}


int max(int cmp1, int cmp2) {
	if (cmp1 > cmp2)
		return cmp1;
	return cmp2;
}

int min(int cmp1, int cmp2) {
	if (cmp1 > cmp2)
		return cmp2;
	return cmp1;
}

void polygon::draw(int x, int y) {
	for (int i = min(p1[0], x); i < max(p1[0],x); i++) {
		field->set(i, p1[1], color);
		field->set(i,y, color);
	}
	for (int i = min(p1[1], y); i < max(p1[1], y); i++) {
		field->set(p1[0],i, color);
		field->set(x,i, color);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////


line::line() {
	color = RED;
}

int f(int x, int x1, int x2, int y1, int y2) {
	return float(x - x1) / (x2 - x1) * (y2 - y1) + y1;
}

void line::draw(int x, int y) {
	int x1 = min(p1[0], x);
	int x2 = max(p1[0], x);
	int y2 = y;
	int y1 = p1[1];

	if (x1 == x) {
		y1 = y;
		y2 = p1[1];
	}

	for (int i = x1; i < x2; i++) {
		field->set(i, f(i, x1, x2, y1, y2), color);
	}
	for (int i = y1; i < y2; i++) {
		field->set(f(i, y1, y2, x1, x2), i, color);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////


circle::circle() {
	color = RED;
}

void circle::draw(int x, int y) {
	int x1 = min(p1[0], x);
	int x2 = max(p1[0], x);
	int y2 = y;
	int y1 = p1[1];

	if (x1 == x) {
		y1 = y;
		y2 = p1[1];
	}

	for (int i = 0; i < 400; i++) {
		int r = (x1 - x2);
		float angle = 2.0 * 3.1415926 * float(i) / float(400);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		field->set(x + dx, y + dy, color);
	}
}
