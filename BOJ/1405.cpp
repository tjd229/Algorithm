//graph, math
#include <stdio.h>
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int vis[29][29];
int N;
double prob[4];
double ans;
void bf(int x,int y,int turn,double p) {
	if (turn == N) {
		ans += p;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (prob[i] == 0.0) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (vis[ny][nx] == 0) {
			vis[ny][nx] = 1;
			bf(nx, ny, 1 + turn, p*prob[i]);
			vis[ny][nx] = 0;
		}
	}
}
int main() {
	int i;
	for (scanf("%d", &N), i = 0; i < 4; ++i) {
		int p;
		scanf("%d",&p);
		prob[i] = p / 100.0;
	}
	vis[14][14] = 1;
	bf(14,14,0,1);
	printf("%.9f",ans);
	return 0;
}
