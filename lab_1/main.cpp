#include"center_string.h"

using namespace std;

int main(int argc, char* argv[]) {
	string str;
	ifstream in("input.txt");
//	ifstream in(argv[0]);
	int max_size;
	in >> max_size;
	in.get();
	
	vector<string> str_list;
	while (getline(in, str)) {
		//	Divide string on the words list
		istringstream iss(str);
		vector<string> word_list;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(word_list));
		
		//	For all words
		Proccess(word_list, max_size, str_list);
	}
	
	//    Print res
	PrintAllString(str_list, "test1_out.txt");

	return 0;
}
