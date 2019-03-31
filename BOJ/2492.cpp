//dp
#include <stdio.h>
#include <memory.h>
int d[10001][10];
int src[10001], dst[10001];
int hist[10001][10];
int N;
int rotate(int k,int acc) {
	int now = (src[k] + acc) % 10;
	int &ref = d[k][now];
	if (ref >= 0) return ref;
	if (k == N) {
		int l = dst[k] - now;
		if (l < 0) l += 10;
		int r = 10 - l;
		if (l < r) hist[k][now] = l,ref=l;
		else hist[k][now] = -r, ref = r;
		return ref;
	}
	if (now == dst[k]) ref = rotate(k+1,acc);
	else {
		int l = dst[k] - now;
		if (l < 0) l += 10;
		int r = 10 - l;
		int rl = rotate(k + 1, (acc + l) % 10) + l;
		int rr = rotate(k + 1, acc) + r;
		if (rl < rr) hist[k][now] = l, ref = rl;
		else hist[k][now] = -r, ref = rr;
	}
	return ref;
}
int main() {
	int i,acc=0;
	memset(d, -1, sizeof(d));
	for (scanf("%d", &N), i = 1; i <= N; ++i) scanf("%1d",src+i);
	for (i = 1; i <= N; ++i) scanf("%1d",dst+i);
	printf("%d\n",rotate(1,0));
	for (i = 1; i <= N; ++i) {
		int now = (src[i] + acc) % 10;
		printf("%d %d\n",i,hist[i][now]);
		if (hist[i][now] > 0) acc = (acc + hist[i][now]) % 10;
	}
	return 0;
}