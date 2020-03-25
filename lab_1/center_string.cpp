#include"center_string.h"

using namespace std;

void DivideWord(vector<string>& words, int max_size) {
	/*
	 * Splitting the first word in the words vector into 2 words, the first of which is long
	 * equal to the length of the string with the addition of the "-"
	*/
	string right_part = (words[0]).substr(max_size - 1);
	(words[0]).erase(max_size - 1);
	(words[0]).append("-");
	words.insert(words.begin() + 1, right_part);
}


void Center(string& str, int max_size) {
	/*
	* Center alignment of the line
	* If the string is of odd length , the alignment is offset to the left
	*/
	if (str.size() >= max_size)
		return;
	int delta = max_size - str.size();
	str.insert(str.begin(), delta / 2 + delta % 2, ' ');
	str.insert(str.end(), delta / 2, ' ');
}


void Proccess(vector<string>& words, int max_size, vector<string>& str_list) {
	/*
	* Creating and filling lines with words from the words vector
	* The resulting rows are added to str_list
	*/
	string new_str;
	while (words.empty() == 0) {
		auto first_word = words.begin();

		// If the current word fits and another word + space is possible
		if (new_str.size() + (*first_word).size() + 1 < max_size) {
			new_str.append(*first_word + " ");
			words.erase(words.begin());
		}
		// If the current word fits
		else if (new_str.size() + (*first_word).size() <= max_size) {
			if (new_str.size() + (*first_word).size() == max_size)
				new_str.append(*first_word);
			else
				new_str.append(*first_word + " ");
			words.erase(words.begin());
		}
		//	If the current word does not fit
		else {
			//	Maybe words length bigger than string size 
			if ((*first_word).size() > max_size) {
				DivideWord(words, max_size);
				continue;
			}

			//	Align a string
			Center(new_str, max_size);
			str_list.push_back(new_str);
			new_str.clear();
		}
	}

	// Last string
	Center(new_str, max_size);
	str_list.push_back(new_str);
}


void PrintAllString(vector<string>& a_vec, const char* file_name) {
	ofstream out;
	out.open(file_name);
	for (auto it = a_vec.begin(); it != a_vec.end(); ++it)
		out << *it << endl;
}
