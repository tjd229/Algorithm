//game
#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
int mp[102][102];
void color(int b, int i, int j) {
	printf("%d %d %d\n", b, i, j); fflush(stdout);
	mp[i][j] = b;
}
int main() {
	int i,j,n; scanf("%d",&n);
	int nn = n * n;
	queue<pii > f, o;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if ((i + j) & 1) o.push({i,j});
			else f.push({i,j});
		}
	}
	int fc = 0;
	while (nn--) {
		int a; scanf("%d",&a);
		if (fc == 0) fc = a;
		if (fc != a) {
			if (f.size()) {
				i = f.front().first, j = f.front().second;
				color(fc, i, j); f.pop();
			}
			else {
				i = o.front().first, j= o.front().second;
				color(6-a-fc, i, j); o.pop();
			}
		}
		else {//no fc (fc==a)
			if (o.size()) {
				i = o.front().first, j = o.front().second;
				int c = a + 1;
				if (c > 3) c -= 3;
				color(c, i, j); o.pop();
			}
			else {
				i = f.front().first, j = f.front().second;
				int c = a + 2;
				if (c > 3) c -= 3;
				color(c, i, j); f.pop();
			}
		}
	}
 
	return 0;
}