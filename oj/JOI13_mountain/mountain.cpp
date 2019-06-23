//greedy
#include "grader.h"
const int dx[4] = { 1,1,-1,-1 };//to close peak
const int dy[4] = {-1,1,-1,1};
void Rescue(int R, int C, int RS, int CS, int X) {
	int sx[4] = {1,1,C,C};
	
	for (int i = 0; i < 4; ++i) {
		int cx = sx[i], cy = RS;
		while (0 < cy && cy <= R&&0<cx && cx<=C) {
			int h = Measure(cy, cx);
			if (h == X) {
				Pinpoint(cy, cx);
				return;
			}
			if (h > X) cy += dy[i];
			else cx += dx[i];
		}
	}

}
