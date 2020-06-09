#include "menu.h"
#include <iostream>
#include <fstream>
#include "paint.h"

using namespace std;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	//string str;
	//ifstream in("menu.txt");
	//getline(in, str);
	//in.close();

	paint();

	return 0;
}
