//implementation
#include <stdio.h>
const int base[5] = {2,4,1,3,5};
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		int i, n; scanf("%d",&n);
		if (n < 4) printf("-1\n");
		else {
			int d = (n >> 2)-1;
			int last = (n % 4)+4;
			int pad = 0;
			int tail[8] = { 2, };
			for (i = 0; i < d; ++i) {
				for (int j = 0; j < 4; ++j) printf("%d ",base[j]+pad);
				pad += 4;
			}
			if (last <= 5) {
				for (int j = 0; j < last; ++j) tail[j] = base[j];
			}
			else if (last == 6) {
				tail[0] = 2, tail[1] = 5;
				tail[2] = 3, tail[3] = 1;
				tail[4] = 4, tail[5] = 6;
			}
			else {
				tail[0] = 2, tail[1] = 6;
				tail[2] = 4, tail[3] = 1;
				tail[4] = 3, tail[5] = 5, tail[6]=7;
			}
			for (int j = 0; j < last; ++j) printf("%d ",tail[j]+pad);
			printf("\n");
		}
	}
	return 0;
}