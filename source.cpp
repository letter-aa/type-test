#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <map>

using namespace std;

int main() {
	cout << "click on \"`\" to exit \n";

	for (int i = 0; i != 96;) {
		i = _getch();
		if (i == 8) {
			cout << "\b" << " ";
		}
		if (i == 13) {
			cout << "\n";
		}
		else {
			cout << (char)i;
		}
	}
}
