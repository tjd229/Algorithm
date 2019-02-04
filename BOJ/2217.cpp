//greedy
#include <stdio.h>
#include <algorithm>
using namespace std;
int rope[100000];
int main() {
	int i;
	int N;
	int mx = 0;
	for (scanf("%d", &N), i = 0; i < N; ++i) scanf("%d",rope+i);
	sort(rope, rope + N);
	int cnt = N;
	for (i = 0; i < N; ++i,--cnt) {
		int w = rope[i] * cnt;
		if (mx < w) mx = w;
	}printf("%d",mx);
	return 0;
}
