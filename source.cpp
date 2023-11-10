#include <iostream>
#include <Windows.h>
#include <conio.h>
#define ANY_ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
using namespace std;
int line = 0; //do not change
int numOfStr(string mainString, string strToCount) {
	int amount = 0;
	string tempMain = mainString;
	while (tempMain.find(strToCount) != string::npos) {
		//cout << mainString;
		if (string(1, tempMain[0]) == strToCount) {
			tempMain = tempMain.substr(1);
			amount++;
		}
		else {
			tempMain = tempMain.substr(1);
		}
	}
	return amount;
}
void ok(string input, string pre, int line) {
	COORD c;
	c.X = 0;
	c.Y = line;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << pre << input;
}
string type_t(string pre) {
	cout << pre;
	string input;
	/*
	for (int i = 0; i < line; i++) {
		input.append("\n");
		cout << "\n";
	}*/
	int rowPos = 0;
	//int linePos = 0;
	//13 enter?
	for (int i = 0;;) {
		i = _getch();
		if (i == 8) {
			if (input.size() > 0 && rowPos > 0) {
				if (rowPos == input.size()) {
					//cout << "\b \b";
					input.pop_back();
					ok(input, pre, line);
					cout << " \b";
					/*
					if (input.substr(input.size() - 1) == "\n") {
						linePos = linePos - 1;
					}
					*/
					rowPos = rowPos - 1;
				}
				else {
					input = input.substr(0, rowPos - 1) + input.substr(rowPos);
					ok(input, pre, line);
					cout << " \b\b";
					for (int i = 0; i < input.size() - rowPos; i++) {
						cout << "\b";
					}
					/*
					cout << " \b";*/
					/*
					if (input.substr(input.size() - 1) == "\n") {
						linePos = linePos - 1;
					}
					*/
					rowPos = rowPos - 1;
				}
			}
		}
		else if (GetKeyState(VK_SHIFT) & 0x8000) {
			if (i == 13) {
				if (rowPos >= 0) {
					if (rowPos == input.size()) {
						cout << endl;
						input = input + "\n";
						//linePos = linePos + 1;
						rowPos = rowPos + 1;
					}
					else {
						input = input.substr(0, rowPos - 1) + "\n" + input.substr(rowPos);
						for (int i = 0; i < input.substr(rowPos - 1).size(); i++) {
							cout << " ";
						}
						cout << "\b\b";
						ok(input, pre, line);
						for (int i = 0; i < input.substr(rowPos - 1).size(); i++) {
							cout << "\b";
						}
						//linePos = linePos + 1;
						rowPos = rowPos + 1;
					}
				}
			}
			else {
				if (rowPos == input.size()) {
					input = input + (char)i;
					ok(input, pre, line);
					rowPos = rowPos + 1;
				}
				else {
					input = input.substr(0, rowPos) + (char)i + input.substr(rowPos);
					ok(input, pre, line);
					for (int i = 0; i < input.size() - rowPos; i++) {
						cout << "\b";
					}
					rowPos = rowPos + 1;
				}
			}
		}
		else if (i == 13) {
			if (!(GetKeyState(VK_SHIFT) & 0x8000)) {
				break;
			}
		}
		else {
			switch (i) {
			case ANY_ARROW:
				i = _getch();
				switch (i) {
				case LEFT_ARROW:
					if (rowPos > 0) {
						cout << "\b";
						rowPos = rowPos - 1;
					}
					break;
				case RIGHT_ARROW:
					if (rowPos < input.length()) {
						cout << "\033[C"; //idk how tf this works whoever's reading this pls explain!11
						rowPos = rowPos + 1;
					}
					break;
				case UP_ARROW:
					break;
				case DOWN_ARROW:
					break;
				}
				break;
			default:
				if (rowPos == input.size()) {
					input = input + (char)i;
					ok(input, pre, line);
					rowPos = rowPos + 1;
				}
				else {
					input = input.substr(0, rowPos) + (char)i + input.substr(rowPos);
					ok(input, pre, line);
					for (int i = 0; i < input.size() - rowPos; i++) {
						cout << "\b";
					}
					rowPos = rowPos + 1;
				}
			}
		}
	}
	line++;
	for (int i = 0; i < numOfStr(input, "\n"); i++) {
		line++;
	}
	return input;
}
int main()
{
	//code here	
}
