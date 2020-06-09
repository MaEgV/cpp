#ifndef  GRAFIC_EDITOR
#define GRAFIC_EDITOR

#include "system.h"
#include "matrix.h"


class cursor_mode {
private:


public:
	int size;

	color_type color;

	virtual void draw(int x, int y) = 0;

	virtual void mouse_position(int x, int y) = 0;  // Обработка движений мыши, учитывая нажатые кнопки

	virtual void set_color(color_type c) = 0;

	virtual void change_size(int change) = 0;  // changing with button ('-'/'+')

};


class editor_launcher : public draw_system {
public:
	editor_launcher(string file_name);

	void render() override; // Главный цикл отрисовки

	void mouse_call(int button, int state, int x, int y) override;  // Меняет состояние кнопок

	void active_move(int x, int y);  // Захват положения курсора

	void passive_move(int x, int y);

	void save(string& filename);

	void load(string& filename);

	void keys(int key);

};


class main_brush : public cursor_mode {
public:
	virtual void change_size(int change) override;  // changing with button ('-'/'+')

	void draw(int x, int y) override;

	void mouse_position(int x, int y) override;

};


class brush : public main_brush {
public:
	brush();

	void set_color(color_type c) override;
	
};


class eraser : public main_brush {
public:
	eraser();

	void set_color(color_type c) override {};

};


class primitives : public cursor_mode {
public:
	bool flag = false;
	vector<int>p1{ 0, 0 };
	vector<int>p2{ 0, 0 };

	void set_color(color_type c);

	void mouse_position(int x, int y);

	void change_size(int change) override {};

};


class polygon : public primitives {
public:
	polygon();

	void draw(int x, int y) override;
};


class line : public primitives {
public:
	line();

	void draw(int x, int y) override;
};


class circle : public primitives {
public:
	circle();

	void draw(int x, int y) override;
};


#endif // ! GRAFIC_EDITOR
