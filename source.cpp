#include <iostream>
#include <conio.h>
#define ANY_ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
using namespace std;
void ok(string input) {
	for (int i = 0; i < 100; i++) {
		cout << "\033[A";
	}
	cout << "\r" << input;
}
int main()
{
	string input;
	int rowPos = 0;
	int linePos = 0;

	for (int i = 0;;) {
		i = _getch();
		if (i == 8) {
			if (rowPos > 0) {
				rowPos = rowPos - 1;
				cout << "\b \b";
				input.pop_back();
			}
		}
		else {
			switch (i) {
			case ANY_ARROW:
				i = _getch();
				switch (i) {
				case LEFT_ARROW:
					cout << "\b";
					if (rowPos > 0) {
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
					ok(input);
					rowPos = rowPos + 1;
				}
				else {
					input = input.substr(0, rowPos) + (char)i + input.substr(rowPos);
					ok(input);
					for (int i = 0; i < input.size() - rowPos; i++) {
						cout << "\b";
					}
					rowPos = rowPos + 1;
				}
			}
		}
	}
}
