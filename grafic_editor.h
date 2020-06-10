#ifndef  GRAFIC_EDITOR
#define GRAFIC_EDITOR

#include "system.h"
#include "matrix.h"
#include "brush.h"
#include "eraser.h"
#include "primitives.h"

class editor_launcher : public draw_system {
private:
	brush* brush_mode = new brush;
	eraser* eraser_mode = new eraser;
	polygon* polygon_mode = new polygon;
	line* line_mode = new line;
	circle* circle_mode = new circle;

	cursor_mode* current_mode = brush_mode;
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

#endif // ! GRAFIC_EDITOR
