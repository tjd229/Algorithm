//https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
//ts
#include <stdio.h>
int a[50];
int len;

int ask(int i, int j, int k) {
	printf("%d %d %d\n", i, j, k); fflush(stdout);
	int L; scanf("%d",&L);
	return L;
}
int ts(int s, int e, int x) {
	int l = s, r = e;
	while (s <= e) {
		if (e - s == 1) {
			if (l == s) {
				int m = ask(a[s], a[e], x);
				if (m == x) return e;
				return l;
			}
			if (e == r) {
				int m = ask(a[s], a[e], x);
				if (m == x) return e;
				return 1 + e;
			}
			return e;
		}
		if (e - s == 2) {
			if (l == s) {
				int m = ask(a[s], a[s + 1], x);
				if (m == x) return 1 + s;
				else if (m == a[s]) return s;
				return e;
			}
			else if (r == e) {
				int m = ask(a[s + 1], a[e], x);
				if (m == x) return e;
				if (m == a[e])return 1 + e;
				return s + 1;
			}
			else {
				int m = ask(a[s], a[s + 1], x);
				if (m == x) return 1 + s;
				return e;
			}
		}
		int st = 0, ed = e - s;
		int m1 = s + (st + ed) / 3;
		int m2 = s + ((st + ed) << 1) / 3;
		int m = ask(a[m1], a[m2], x);
		if (m == x) {
			s = m1, e = m2;
		}
		else if (a[m1] == m) e = m1;
		else s = m2;
	}

}
void insert(int pos, int x) {
	for (int i = ++len; i > pos; --i) a[i] = a[i - 1];
	a[pos] = x;
}
int main() {
	int T, N, Q; scanf("%d%d%d", &T, &N, &Q);
	

	for (int tc = 1; tc <= T; ++tc) {
		int m = ask(1, 2, 3);
		int i = 1; len = 2; a[0] = 0;
		for (i = 1; i <= 3; ++i) {
			if (i == m) a[1] = m;
			else {
				if (a[0]) a[2] = i;
				else a[0] = i;
			}
		}
		//return 0;
		for (i = 0; i < 2; ++i) {
			int m = ask(a[i], a[i + 1], 4);
			if (m == 4) {
				insert(i + 1, 4);
				break;
			}
			if (m == a[i] && i == 0) {
				insert(0, 4);
				break;
			}
			if (m == a[i + 1] && i == 1) {
				insert(3, 4);
				break;
			}
		}
		for (i = 5; i <= N; ++i) {
			int pos = ts(0, len, i);
			insert(pos, i);
		}
		for (i = 0; i <= len; ++i)
			printf("%d ", a[i]);
		printf("\n"); fflush(stdout);
		int res; scanf("%d",&res);
	}
	return 0;
}