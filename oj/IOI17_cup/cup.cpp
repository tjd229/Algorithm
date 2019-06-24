//math
#include "cup.h"
const int s = -1e9;
std::vector<int> find_cup() {
	int x = s, y = s;
	int diff = ask_shahrasb(x, y);
	int common = 0;
	int b = 1;
	int px = 0, py = 0;
	for (int i = 0; i < 31; ++i,b+=b) {
		int d = ask_shahrasb(x + b, y);
		if (diff&b) {
			if (diff -b==d) px += b;
			else py += b;
		}
		else if (diff + b == d) common += b;
	}
	x += px + common;
	y += py + common;
	return{x,y};
}
