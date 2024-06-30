#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Windows.h"

using namespace std;

void Trans() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream trans("C:\\Users\\Opsik\\source\\repos\\C++2\\Project3\\Project3\\trans.txt");
	string word;
	vector<string> translate_words;

	while (trans >> word) {
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });
		translate_words.push_back(word);
	}

	trans.close();

	ifstream from_f("C:\\Users\\Opsik\\source\\repos\\C++2\\Project3\\Project3\\Hi.txt");

	string result;

	while (from_f >> word) {

		string buffer_check_word = word;
		string buffer_buffer_check_word;

		transform(buffer_check_word.begin(), buffer_check_word.end(), buffer_check_word.begin(), [](unsigned char c) { return tolower(c); });

		for (int i = 0; i<buffer_check_word.length(); i++) {

			if (isalpha(buffer_check_word[i])) {
				buffer_buffer_check_word += buffer_check_word[i];
			}
		}
		if (buffer_buffer_check_word == "your") {
			string your = "Твоє";
			result += your + " ";
			continue;
		}
		else if (buffer_buffer_check_word == "message") {
			string mess = "повідомлення";
			result += mess + " ";
			continue;
		}
		result += word + " ";
		
	}

	from_f.close();

	ofstream to_f("C:\\Users\\Opsik\\source\\repos\\C++2\\Project3\\Project3\\asd2.txt");

	to_f << result;

	to_f.close();
}