#pragma once
#ifndef GAME_OBJECTS
#define GAME_OBJECTS

#include"geometry.h"

using namespace std;

int lives;

enum figure_types{
	POLYGON = 1,
	CIRCLE
};

class object_stack {
private:
	vector<object&> stack;

public:
	object_stack();  // something from @level@

	vector<object&> find_collision(object& a);

};


class bonus : public moving_objects {
private:
	void collision(object& a) override { a.action(this); }

public:
	bonus();

	void draw_object() override {
		fig.draw();
	}

	void action(racket* r) override;
	void action(ball* r) override;
	void action(bonus* r) override;
};


class borders : public object {
private:
	int lives;

public:
	borders(int h, int w, int lives) {
		fig = figure(point(w / 2, h / 2), POLYGON, vec(point(w / 2, h / 2), point(w / 2, h / 2) + point(w, 0)));
	}

	void draw_object() override {
		fig.draw();
	}

	void action(racket* r) override;
	void action(ball* r) override;
	void action(bonus* r) override;
};


class ball : public moving_objects {
private:
	void collision(object& a) override { a.action(this); }

public:
	ball(point& center, vec speed) {
		fig = figure(center, CIRCLE, vec(center, center + point(50, 50)));
	}

	void draw_object() {
		fig.draw();
	}

	void reflection();

	void action(racket* r) override;
	void action(ball* r) override;
	void action(bonus* r) override;
};


class racket : public moving_objects {
protected:
	void collision(object& a) override { a.action(this); }

public:
	racket(point& start_pos) {
		fig = figure(start_pos, POLYGON, vec(start_pos, start_pos + point(10, 50)));
		speed = vec();
	}

	void draw_object() override {
		fig.draw();
	}

	void action(racket* r) override;
	void action(ball* r) override;
	void action(bonus* r) override;
};


class object {
protected:
	figure fig;

	virtual void draw_object() = 0;

	object() {}

public:
	// different interactions between objects
	virtual void action(ball* a) = 0;
	virtual void action(racket* a) = 0;
	virtual void action(bonus* a) = 0;

};


class block : public object {
private:
	int lives;

public:
	block(int health, point& center) {
		fig = figure(center, POLYGON, vec(center, center + point(50, 50)));
	}

	void draw_object() override{
		fig.draw();
	}

	void action(ball* r) override;  // can only be affected by the ball
};


class moving_objects : public object {
protected:
	virtual void collision(object& a) = 0;

	object& check_collisions();  

	vec speed;

	moving_objects() {}
};

#endif // !GAME_OBJECTS
