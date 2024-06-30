#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void Nepriynatni() {
	ifstream NEPRIYNATNI("C:\\Users\\Opsik\\source\\repos\\C++2\\Project3\\Project3\\неприйнятні це як.txt");
	string word;
	vector<string> nepriynanti_word;

	while (NEPRIYNATNI >> word) {
		transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });
		nepriynanti_word.push_back(word);
	}

	NEPRIYNATNI.close();

	ifstream from_f("C:\\Users\\Opsik\\source\\repos\\C++2\\Project3\\Project3\\Hi.txt");

	string result;

	while (from_f >> word) {

		string buffer_check_word = word;
		transform(buffer_check_word.begin(), buffer_check_word.end(), buffer_check_word.begin(), [](unsigned char c) { return tolower(c); });

		auto it = find(nepriynanti_word.begin(), nepriynanti_word.end(), buffer_check_word);

		if (it == nepriynanti_word.end()) {
			result += word + " ";
		}

	}
	
	from_f.close();

	ofstream to_f("C:\\Users\\Opsik\\source\\repos\\C++2\\Project3\\Project3\\asd.txt");

	to_f << result;

	to_f.close();

}