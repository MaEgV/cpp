#pragma once
#ifndef INTERFACE
#define INTERFACE

#include"glut.h"
#include"tree.h"
#include "system.h"

typedef void (*action_type)();

using namespace std;


class menu_launcher : public draw_system {
public:
    menu_launcher(string filename);

    void render() override;

    void mouse_call(int button, int state, int x, int y) override;

    void reg_action(action_type func, string name);
};


class point {
private:
    float x;
    float y;

public:
    point() { x = y = 0; }
    point(float x1, float y1) { x = x1; y = y1; }

    void put_point() { glVertex2d(x, y); }

    bool between(point& a, point& b) {
        if (x > a.x && x < b.x && y > a.y && y < b.y)
            return true;
        return false;
    }

    void set_name_pos() {
        glRasterPos2f(x, y);
    }

    point operator + (point& rv) {
        point res(x + rv.x, y + rv.y);
        return point(x + rv.x, y + rv.y);
    }

    point& operator / (int rv) {
        point res(x / rv, y / rv);
        return res;
    }
};


class menu : public tree{
private:
    vector<point> button = vector<point>(2);
    action_type action;

    void init_buttons(float w, float h);  // Init buttons with window sizes

    void draw_name(menu* ptr);

public:
    menu() : tree() {}

    menu(std::string& S);

    void reg_action(action_type func, string& name);

    bool search_ans(string& ans); // Get answer in dialog and returns 1; if no options - returns 0

    void draw_children(float width, float height);  // Draw menu level

    void click(point p);  // Reaction on mouse button (calling @action@)

};

class text_tree {
private:
    std::string str;

    menu* create_tree(std::string& s);

    vector<text_tree> get_subemu(std::string& tmp, char del1 = ' ', char del2 = ' ');  // Get submenues vector from tmp

    string first_child(string& children);  // Find first submenu

    string::iterator find_separator(string& s, char sym);  // Find separator sym in menu level

    string first_brackets(string& s, char del1, char del2);  // Content of first brackets (first open "(" and last close ")")

public:
    text_tree() { str = string(); }
    text_tree(string& init) { str = init; }

    menu* create_tree() { return create_tree(str); }  // Create tree with menu structure. Dialogs not parsed
};

#endif 
