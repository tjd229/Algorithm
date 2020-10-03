//graph

#include <stdio.h>
#include <queue>
using namespace std;
int F, S, G, U, D;
int mv[1000001];
int main() {

	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
	if (S == G) {
		printf("0");
		return 0;
	}
	if (S < G&&U < 1) {
		printf("use the stairs");
		return 0;
	}
	if (S > G&&D < 1) {
		printf("use the stairs");
		return 0;
	} 
	queue<int> q; q.push(S);
	while (q.size()) {
		int x = q.front(); q.pop();
		int u = x + U;
		if (u != S && u <= F && mv[u] == 0) {
			mv[u] = mv[x] + 1;
			q.push(u);
		}
		int d = x - D;
		if (d != S && d > 0 && mv[d] == 0) {
			mv[d] = mv[x] + 1;
			q.push(d);
		}
	}
	if(mv[G]==0) printf("use the stairs");
	else printf("%d",mv[G]);

	return 0;
}
