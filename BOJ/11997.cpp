//implementation
#include <stdio.h>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
pii cow[1000];
int y[1003],x[1003];
bool cmp(pii p1, pii p2) {
	return p1.second < p2.second;
}
int main() {
	int i, j, N;
	for (scanf("%d", &N), i = 0; i < N; ++i) {
		scanf("%d%d", x + i, y + i);
		cow[i] = {x[i],y[i]};
	}
	x[N] =1e6+2;
	y[N] = 1e6 + 2;
	x[N+1] = y[N+1] = 0;
	sort(y, y + N+2); sort(x, x +2+ N);
	unique(y, y + N+2); unique(x, x +2+ N);
	int fx = 0;
	int ans = N;
	for (i = 0; i <= N+1; ++i) {
		if (i > 0 && x[i] <= x[i - 1]) break;
		sort(cow, cow + N);
		while (fx<N && cow[fx].first <= x[i]) ++fx;
		sort(cow, cow + fx, cmp);
		if (fx +1< N) sort(cow + fx + 1, cow + N,cmp);
		int ly = 0;
		int ry = fx;
		//l=fx; r=N-fx
		for (j = 0; j <= N+1; ++j) {
			if (j > 0 && y[j] <= y[j - 1]) break;
			while (ly < fx && cow[ly].second <= y[j]) ++ly;
			while (ry < N && cow[ry].second <= y[j])++ry;
			int mx = ly;
			if (mx < fx - ly) mx = fx - ly;
			if (mx < ry-fx) mx = ry-fx;
			if (mx < N - ry) mx = N - ry;
			if (ans > mx) ans = mx;
			//printf("%d,%d\n",fx,ly);
		}
	}
	printf("%d",ans);

	return 0;
}