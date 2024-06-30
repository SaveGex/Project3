#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "NepriynaTni.h"
#include "trans.h"
using namespace std;

int main() {
	while (true) {
		cout << "\nNeptiynaTni[1]\
\nTranslate[2]\
\nExit[0]";
		char quest;
		cin >> quest;
		switch (quest) {
		case '1':Nepriynatni(); break;
		case '2':Trans(); break;
		case '0': return 0;
		}
	}








	return 0;
}