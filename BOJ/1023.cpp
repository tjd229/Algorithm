//dp
#include <stdio.h>
#define ll long long
ll d[51][101][2];
int N; ll K;
ll stk(int n,int top, bool down) {
	down |= (top < N);
	ll &ref = d[n][top][down];
	if (n == N) {
		ref= (down || (top != N));
	}
	else if (ref == 0) {
		ref += stk(n + 1, top + 1, down)
			+ stk(n + 1, top - 1, down);
	}
	//printf("%d,%d,%d:%d\n",n,top-N,down,ref);
	return ref;
}
int main() {
	int i;
	scanf("%d%lld",&N,&K);
	if (stk(0, N, 0)<=K) {
		printf("-1");
		return 0;
	}
	int top = N;
	bool down = 0;
	for (i = 1; i <= N; ++i) {
		if (K >= d[i][top + 1][down]) {
			printf(")");
			K -= d[i][top + 1][down];
			--top;
		}
		else {
			printf("(");
			++top;
		}
		down |= (top < N);
	}
	
	return 0;
}