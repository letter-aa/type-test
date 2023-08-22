#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <map>
/*
struct {
	int q = 113;
	int w = 119;
	int e = 101;
	int r = 114;
	int t = 116;
	int y = 121;
	int u = 117;
	int i = 105;
	int o = 111;
	int p = 112;
	int a = 97;
	int s = 115;
	int d = 100;
	int f = 102;
	int g = 103;
	int h = 104;
	int j = 106;
	int k = 107;
	int l = 108;
	int z = 122;
	int x = 120;
	int c = 99;
	int v = 118;
	int b = 98;
	int n = 110;
	int m = 109;
	int enter = 13;
} key;
*/

using namespace std;
map<string, int> key = {
	{"q", 113},
	{"w", 119},
	{"e", 101},
	{"r", 114},
	{"t", 116},
	{"y", 121},
	{"u", 117},
	{"i", 105},
	{"o", 111},
	{"p", 112},
	{"a", 97},
	{"s", 115},
	{"d", 100},
	{"f", 102},
	{"g", 103},
	{"h", 104},
	{"j", 106},
	{"k", 107},
	{"l", 108},
	{"z", 122},
	{"x", 120},
	{"c", 99},
	{"v", 118},
	{"b", 98},
	{"n", 110},
	{"m", 109},
	{"\n", 13},
	{" ", 32},
	{"\b",8}
};
map<char, int> capKey = {
	{'Q', 81},
	{'W', 87},
	{'E', 69},
	{'R', 82},
	{'T', 84},
	{'Y', 89},
	{'U', 85},
	{'I', 73},
	{'O', 79},
	{'P', 80},
	{'A', 65},
	{'S', 83},
	{'D', 68},
	{'F', 70},
	{'G', 71},
	{'H', 72},
	{'J', 74},
	{'K', 75},
	{'L', 76},
	{'Z', 90},
	{'X', 88},
	{'C', 67},
	{'V', 86},
	{'B', 66},
	{'N', 78},
	{'M', 77},
	{'1', 49},
	{'2', 50},
	{'3', 51},
	{'4', 52},
	{'5', 53},
	{'6', 54},
	{'7', 55},
	{'8', 56},
	{'9', 57},
	{'0', 48},
	{'!', 33},
	{'@', 64},
	{'#', 35},
	{'$', 36},
	{'%', 37},
	{'^', 94},
	{'&', 38},
	{'*', 42},
	{'(', 40},
	{')', 41},
	{'_', 95},
	{'+', 43},
	{'-', 45},
	{'=', 61},
	{'[', 91},
	{']', 93},
	{'\\', 92},
	{'{', 123},
	{'}', 125},
	{'|', 124},
	{';', 59},
	{'\'', 39},
	{':', 58},
	{'"', 34},
	{',', 44},
	{'.', 46},
	{'/', 47},
	{'<', 60},
	{'>', 62},
	{'?', 63},
	{'~', 126}
};
int main() {
	/*
	for (int i = 0; i < sizeof("qwertyuiopasdfghjklzxcvbnm"); i++) {
		cout << _getch() << endl;
	}
	*/
	//reinterpret_cast<string*>(&var);
	/*
	string s;
	std::cin >> s;
	*/
	/////////
	cout << "click on \"`\" to exit \n";
	string cO = "";
	for (int i = 0; i != 96;) {
		i = _getch();
		if (i != key["\n"]) {
			for (const auto& name : key) {
				if (i == key["\b"]) {
					if (!cO.empty()) {
						//cO = cO.substr(0, cO.size() - 1);
						//cout << "\n" << cO.substr(0, cO.size() - 1
						cO = cO.substr(0, cO.size() - 1);
						cout << "\r";
						cout << cO << " " << "\b";
						break;
						/*
						cout << "\r";
						cout << cO << " ";
						*/
						//add = add + 1;
					}

				}
				else if (i == key[name.first]) {
					cO = cO + name.first;
					cout << name.first;
				}
			}
			for (const auto& name : capKey) {
				if (i == capKey[name.first]) {
					cO = cO + name.first;
					cout << name.first;
				}
			}
		}
		else if (i == key["\n"]) {
			cO = "";
			cout << "\n";
		}
	}
}
