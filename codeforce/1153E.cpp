//bs
#include <stdio.h>
#include <vector>
using namespace std;
int n;
int ask(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int ans; scanf("%d",&ans);
	return ans;
}
int bs(int x1, int y1, int x2, int y2) {
	int l, r;
	if (x1 == x2) l = y1, r = y2;
	else l = x1, r = x2;
	int res = -1;
	while (l <= r) {
		int m = (l + r)>>1;
		int cut;
		if (x1 == x2) cut = ask(x1,1,x2,m);
		else cut = ask(1,y1,m,y2);
		if (cut & 1) res = m, r = m - 1;
		else l = m + 1;
	}
	return res;
}
int main() {
	vector<int> candi;
	int n; scanf("%d",&n);
	int last = 0;
	for (int i = 1; i < n; ++i) {
		int cut = ask(i,1,i,n);
		if (cut & 1) candi.push_back(i);
		last = cut - last;
	}
	if (last & 1) candi.push_back(n);
	if (candi.empty()) {
		last = 0;
		for (int i = 1; i < n; ++i) {
			int cut = ask(1,i,n,i);
			if (cut & 1) candi.push_back(i);
			last = cut - last;
		}
		if (last & 1) candi.push_back(n);
		int y1 = candi[0], y2 = candi[1];
		int x = bs(1, y1, n, y1);
		printf("! %d %d %d %d", x, y1, x, y2); fflush(stdout);
	}
	else {
		int x1 = candi[0], x2 = candi[1];
		int y1 = bs(x1, 1, x1, n), y2 = bs(x2, 1, x2, n);
		printf("! %d %d %d %d", x1, y1, x2, y2); fflush(stdout);
	}
	return 0;
}
