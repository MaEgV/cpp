//#pragma once
//#include"glut.h"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iterator>
//#include <sstream>
//
//using namespace std;
//
//int mainWindow, subWindow1, subWindow2, subWindow3;
//
//void dialog(void) {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLineWidth(1.0f);
//    subWindow1 = glutCreateSubWindow(1, 700 / 2, 600 / 2, 300, 300);
//
//    glColor3f(10, 30, 99);
//
//    menu->draw_children(700, 600);
//
//    glFinish();
//    glutSwapBuffers();
//}
//
//
//void draw_string_bitmap(void* font, string str)
//{
//    for (auto sym = str.begin(); sym < str.end(); sym++) {
//        if (*sym == '<') // Dialogue
//            return;
//        glutBitmapCharacter(font, *sym);
//    }
//}
//
//
//class point {
//private:
//    float x;
//    float y;
//public:
//    point() { x = y = 0; }
//    point(float x1, float y1) {
//        x = x1; y = y1;
//    }
//
//    void put_point() {
//        glVertex2d(x, y);
//    }
//
//    bool between(point& a, point& b) {
//        if (x > a.x && x < b.x && y > a.y && y < b.y)
//            return true;
//        return false;
//    }
//
//    void set_name_pos() {
//        glRasterPos2f(x, y);
//    }
//
//    point operator + (point& rv) {
//        point res(x + rv.x, y + rv.y);
//        return point(x + rv.x, y + rv.y);
//    }
//
//    point& operator / (int rv) {
//        point res(x / rv, y / rv);
//        return res;
//    }
//};
//
//
//class tree {
//private:
//    string data;
//    vector<point> button = vector<point>(2);
//    vector<tree*> children;
//    void(tree::* action)(void) = &tree::pass;
//
//
//    void init_buttons(float w, float h) {
//        float step = h / children.size() / 2;
//        for (int i = 0; i < children.size(); i++) {
//            children[i]->button[0] = point(-w / 8, step * i - h / 4);
//            children[i]->button[1] = point(w / 8, step * (i + 1) - h / 4);
//        }
//    }
//
//    void pass() { return; }
//
//    bool find_option(string& option) {
//        int i;
//        for (i = 0; i < data.size(); i++) {
//            if (data[i] == '<')
//                break;
//        }
//        i++;
//        for (int j = i; j < data.size(); j++) {
//            if (data[j] == '>') {
//                option = data.substr(i, j - i);
//                data.erase(i - 1, j - i + 2);
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void start_dialogue() {
//        string option;
//        while (find_option(option)) {
//            glutDisplayFunc(dialog);
//            tree* node = new tree;
//            *node = tree(option);
//            this->children.push_back(node);
//        }
//        return;
//    }
//
//public:
//
//    tree() { data = ""; }
//    tree(string& root) { 
//        data = root;
//        if (data.find('<') != string::npos) {
//            action = &tree::start_dialogue;
//        }
//    }
//
//    void add_child(tree* child) {
//        children.push_back(child);
//    }
//
//    void draw_children(float width, float height) {
//        init_buttons(width, height);
//        for (auto i = children.begin(); i < children.end(); i++) {
//            point p1 = ((*i)->button[0] + (*i)->button[1]);
//            p1 = p1 / 2;
//            p1.set_name_pos();
//            draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, (*i)->data);
//        }
//    }
//
//    void click(point p) {
//        for (auto i = children.begin(); i < children.end(); i++) {
//            if (p.between((*i)->button[0], (*i)->button[1])) {
//                *this = **i;
//                (this->*action)();
//                return;
//            }
//        }
//    }
//
//};
//
//
//class text_tree {
//private:
//    string str;
//
//    tree* create_tree(string& s) {
//        vector<text_tree> submenu_list = this->get_subemu(s, '(', ')');
//
//        tree* t = new tree();
//        if (submenu_list[0].str.size() == 0) {
//            return t;
//        }
//        tree* tree = new tree(submenu_list[0].str);
//        for (int i = 1; i < submenu_list.size(); i++) {
//            tree->add_child(create_tree(submenu_list[i].str));
//        }
//
//        return tree;
//
//    }
//
//    vector<text_tree> get_subemu(string& tmp, char del1 = ' ', char del2 = ' ') {
//        vector<text_tree> elems; // Root in [0] pos, and children in other positions
//        string name = tmp.substr(0, tmp.find_first_of(del1));
//        elems.push_back(text_tree(name)); // Root name
//        if (tmp.size() == 0)
//            return elems;
//
//        string children = first_brackets(tmp, del1, del2); // All children of root
//
//        string child;
//        /* Divide children and append them to elems*/
//        do {
//            child = first_child(children);
//            elems.push_back(child);
//        } while (child != children);
//
//        return elems;
//    }
//
//    string first_child(string& children) {
//        string::iterator comma_pos = find_separator(children, ',');
//        if (comma_pos == children.end()) {
//            return children;
//        }
//        string tmp = children.substr(0, comma_pos - children.begin());
//        children.erase(children.begin(), comma_pos + 1);
//
//        return tmp;
//    }
//
//    string::iterator find_separator(string& s, char sym) {
//        int counter = 0;
//        for (auto pos = s.begin(); pos < s.end(); pos++) {
//            if (*pos == '(' || *pos == '<')
//                counter++;
//            else if (*pos == ')' || *pos == '>')
//                counter--;
//            else if (*pos == ',' && counter == 0)
//                return pos;
//        }
//        return s.end();
//    }
//
//    /*returns the contents of the first opening bracket*/
//    string first_brackets(string& s, char del1, char del2) {
//        int open_pos = s.find_first_of(del1);
//        int close_pos = s.find_last_of(del2);
//        return s.substr(open_pos + 1, close_pos - open_pos - 1);
//    }
//
//public:
//    text_tree() { str = string(); }
//    text_tree(string& init) { str = init; }
//
//    tree* create() {
//        return
//
//            create_tree(str);
//    }
//};
