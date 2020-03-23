#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;


void DivideWord(vector<string> &words, int max_size) {
	/*
	*	��������� ������� ����� � ������� words �� 2 �����, ������ �� ������� ����� ����� 
	*	������ ����� ������ � ����������� ������� "-", ������������� �������
	*/
	string right_part = (words[0]).substr(max_size - 1);
	(words[0]).erase(max_size - 1);
	(words[0]).append("-");
	words.insert(words.begin() + 1, right_part);
}


void Center(string &str, int max_size) {
	/*
	*	������������ ������ �� ������
	*	���� ������ �������� �����, ������������ ���������� �� ��������� �����
	*/
	if (str.size() >= max_size)
		return;
	int delta = max_size - str.size();
	str.insert(str.begin(), delta / 2 + delta % 2, ' ');
	str.insert(str.end(), delta / 2, ' ');
}


void Proccess(vector<string> &words, int max_size, vector<string> &str_list) {
	/*
	*	�������� � ���������� ����� ������� �� ������� words
	*	���������� ������ ����������� � str_list
	*/
	string new_str;
	while (words.empty() == 0) {
		auto first_word = words.begin();
		
		//	���� ���������� ������� ����� � �������� ��� ���� ����� + ������
		if (new_str.size() + (*first_word).size() + 1 < max_size) {
			new_str.append(*first_word + " ");
			words.erase(words.begin());
		}
		// ���� ���������� ������ ������� �����
		else if (new_str.size() + (*first_word).size() <= max_size) {
			new_str.append(*first_word);
			words.erase(words.begin());
		}
		//	���� ������� ����� �� ����������
		else {
			//	�������� ����� ������ ������
			if ((*first_word).size() > max_size) {
				DivideWord(words, max_size);
				continue;
			}

			//	���������� ������ � ��������� � � ������ ������� �����
			Center(new_str, max_size);
			str_list.push_back(new_str);
			new_str.clear();
		}
	}
	
	// ��������� ��������� ������
	Center(new_str, max_size);
	str_list.push_back(new_str);
}


void PrintVector(vector<string> & a_vec, const char* file_name){
	ofstream out;
	out.open(file_name);
	for (auto it = a_vec.begin(); it != a_vec.end(); ++it)
		out << *it << endl;
}


int main(int argc, char* argv[]) {
	string str;
	ifstream in("input.txt");
//	ifstream in(argv[0]);
	int max_size;
	in >> max_size;
	in.get();
	
	vector<string> str_list;
	while (getline(in, str)) {
		//	��������� �������� ������ �� �����
		istringstream iss(str);
		vector<string> word_list;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(word_list));
		
		//	��������� ������ ����
		Proccess(word_list, max_size, str_list);
	}
	
	//	������ ����������
	PrintVector(str_list, "test1_out.txt");

	return 0;
}
