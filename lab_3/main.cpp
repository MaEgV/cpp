#include"menu.h"
#include <iostream>
#include <fstream>


int main(int argc, char** argv) {
	string str;
	ifstream in("menu.txt");
	getline(in, str);
	in.close();
	
	launch_menu(argc, argv, str);

	return 0;
}
