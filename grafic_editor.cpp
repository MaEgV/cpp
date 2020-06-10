#include "grafic_editor.h"

editor_launcher::editor_launcher(string file_name) {
	if (file_name.size() == 0)
		return;
}

void editor_launcher::render() {
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	current_mode->field->draw();

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
		current_mode->lcm = false;
		if (state == GLUT_DOWN)
			current_mode->lcm = true;
		break;
	case GLUT_RIGHT_BUTTON:
		current_mode->rcm = false;
		if (state == GLUT_DOWN)
			current_mode->rcm = true;
		break;
	case GLUT_MIDDLE_BUTTON:
		current_mode->ccm = false;
		if (state == GLUT_DOWN)
			current_mode->ccm = true;
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
		current_mode->field->change_coef(false);
		break;
	case GLUT_KEY_RIGHT:
		current_mode->field->change_coef(true);
		break;
	}
}

void editor_launcher::save(string& filename) {
	current_mode->field->save(filename);
}

void editor_launcher::load(string& filename) {
	current_mode->field->load(filename);
}
