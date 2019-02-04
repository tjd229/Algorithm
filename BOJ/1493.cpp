//greedy

#include <stdio.h>
#define ll long long
int cube[20];
//fill, order
int order(int type, ll x) {
	if (x > 1e8) return -1;
	if (cube[type] < x) {
		if (type == 0) return -1;
		int cnt = cube[type];
		x -= cube[type];
		cube[type] = 0;
		int r=order(type - 1, x << 3);
		if (r < 0) return r;
		return r + cnt;
	}
	cube[type] -= x;
	return x;
}
int fill(int sz[3]) {
	if (sz[1] > sz[2]) sz[1] ^= sz[2] ^= sz[1] ^= sz[2];
	if (sz[0] > sz[1]) sz[1] ^= sz[0] ^= sz[1] ^= sz[0];
	if (sz[1] > sz[2]) sz[1] ^= sz[2] ^= sz[1] ^= sz[2];
	int len = 1 << 19;
	int cnt = 0;
	for (int i = 19; i>=0; --i, len >>= 1) {
		if (len > sz[0]) continue;
		ll d[3];
		int r[3];
		for (int j = 0; j < 3; ++j) d[j] = sz[j] / len, r[j]=sz[j]%len;
		int res = order(i, d[0] * d[1] * d[2]);
		if (res < 0) return -1;
		cnt += res;
		for (int j = 0; j < 2; ++j) {
			if (r[j]) {
				int size[3] = {r[j],len*d[1-j],len*d[2]};
				int res = fill(size);
				if (res < 0) return -1;
				cnt += res;
			}
		}
		if (r[0] && r[1]) {
			int size[3] = {r[0],r[1],len*d[2]};
			int res = fill(size);
			if (res < 0) return -1;
			cnt += res;
		}
		if (r[2]) {
			int size[3] = {sz[0],sz[1],r[2]};
			int res = fill(size);
			if (res < 0) return -1;
			cnt += res;
		}
		return cnt;
	}
	return -1;
}
int main() {
	int sz[3];
	int N;
	int i,j,k;
	for (scanf("%d%d%d%d", sz, sz + 1, sz + 2, &N), i = 0; i < N; ++i) {
		scanf("%d",&j);
		scanf("%d", cube + j);
	}
	printf("%d",fill(sz));
	return 0;
}
