#include <iostream>
#include <conio.h>
#define ANY_ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
using namespace std;
int main()
{
	string input;
	int rowPos = 0;
	cout << "click on enter to exit\n";
	for (int i = 0; i != 13;) {
		i = _getch();
		if (i == 8) {
			cout << "\b \b";
			input.pop_back();
			if (rowPos > 0) {
				rowPos = rowPos - 1;
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
				cout << (char)i;
				rowPos = rowPos + 1;
				input = input + (char)i;

			}
		}
	}
}
