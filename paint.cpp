#include "paint.h"
#include <iostream>


menu_launcher* menu = new menu_launcher(string("menu.txt"));  // initializing the menu
editor_launcher* editor = new editor_launcher(string());
paint* grafic_system;


void normal_keys(unsigned char key, int x, int y) {
	if (key == 27) {
		grafic_system->set_system(menu);
	}
}

void special_keys(int key, int x, int y) {
	grafic_system->keyboard(key);
}

void mouse_click(int button, int state, int x, int y) { 
	grafic_system->click(button, state, x, y); 
}

void mouse_move(int x, int y) {
	grafic_system->active_move(x, y);
}

void passive_mouse_move(int x, int y) {
	grafic_system->passive_move(x, y);
}

void render() {
	grafic_system->draw();
};


void paint::draw() {
	current_system->render();
}

void paint::click(int button, int state, int x, int y) {
	current_system->mouse_call(button, state, x, y);
}

void paint::active_move(int x, int y) {
	static_cast<editor_launcher*>(current_system)->active_move(x, y);
}

void paint::passive_move(int x, int y) {
	static_cast<editor_launcher*>(current_system)->passive_move(x, y);
}

void paint::keyboard(int key) {
	static_cast<editor_launcher*>(current_system)->keys(key);
}

void paint::set_system(draw_system* new_system) { 
	current_system = new_system; 
}

void paint::save(string& filename) {
	static_cast<editor_launcher*>(current_system)->save(filename);
}

void paint::load(string& filename) {
	static_cast<editor_launcher*>(current_system)->load(filename);
}

void size(int wid, int ht) {
	glViewport(0, 0, wid, ht);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-wid / 2, wid / 2, -ht / 2, ht / 2);
	glMatrixMode(GL_MODELVIEW);
}

void end() { exit(0); }

void call_editor() { grafic_system->set_system(editor); }

void save_picture(){
	string filename;
	cin >> filename;
	grafic_system->save(filename);
}

void load_picture() {
	string filename;
	cin >> filename;
	grafic_system->load(filename);
}


paint::paint() {
	grafic_system = this;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!в создание меню приписать!
	menu->reg_action(end, "exit");
	menu->reg_action(call_editor, "start");
	menu->reg_action(save_picture, "save");
	menu->reg_action(load_picture, "load");
	current_system = editor;

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 600);
	glutCreateWindow("Menu");

	glutDisplayFunc(render);
	glutIdleFunc(render);

	glutKeyboardFunc(normal_keys);
	glutSpecialFunc(special_keys);

	glutMouseFunc(mouse_click);
	glutMotionFunc(mouse_move);
	glutPassiveMotionFunc(passive_mouse_move);
	glutReshapeFunc(size);


	glutMainLoop();
}