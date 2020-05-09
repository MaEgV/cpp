#pragma once
#ifndef INTERFACE
#define INTERFACE

#include"myglut.h"
#include"structure.h"

using namespace std;

void launch_menu(int argc, char** argv, string& structure); // Main function of module

void draw_string(std::string& str);

void renderScene(void); // Render (calling the level drawing function)

void proccessMouse(int button, int state, int x, int y);


class menu : public tree {
private:
	vector<point> button = vector<point>(2);
	void(menu::* action)(void) = &menu::pass;

	void pass() { return; }  // Action for submenues (just go to child)

    void init_buttons(float w, float h);  // Init buttons with window sizes

    void draw_name(menu* ptr);


public:
    menu() : tree() {}

    menu(std::string& S) : tree(S) {
        if (S.find('<') != string::npos) {
            this->action = &menu::start_dialogue;
        }
    }

    bool search_ans(string& ans); // Get answer in dialog and returns 1; if no options - returns 0

    void start_dialogue(); // Create dialod window (function for variable @action@)

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
