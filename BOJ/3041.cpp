//implementation
#include <iostream>
#include <string>
using namespace std;
int main() {
	int i, j;
	int ansx[16],ansy[16];
	int ix = 0;
	int dist = 0;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			ansx[ix] = j;
			ansy[ix] = i;
			++ix;
		}
	}
	for (i = 0; i < 4; ++i) {
		string puzzle;
		cin >> puzzle;
		for (j = 0; j < 4; ++j) {
			if (puzzle[j] == '.') continue;
			ix = puzzle[j]-'A';
			int dx = ansx[ix] - j;
			int dy = ansy[ix] - i;
			if (dx < 0) dx = -dx;
			if (dy < 0) dy = -dy;
			dist += dx + dy;
		}
	}
	cout << dist;
	return 0;
}