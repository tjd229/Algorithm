//implementation
#include <stdio.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
int N, T, G;
int vis[100000];
int B(int n) {
	int x = 1;
	while (x <= n) x *= 10;
	return n - x / 10;
}
int main() {
	queue<pii > q;
	scanf("%d%d%d",&N,&T,&G);
	q.push({N,0});
	vis[N] = 1;
	while (q.size()) {
		int n = q.front().first;
		int turn = q.front().second;
		if (n == G) {
			printf("%d",turn);
			return 0;
		}
		q.pop();
		if (turn == T) continue;
		int nxt = n + 1;
		if (nxt < 100000 && vis[nxt] == 0) {
			q.push({ nxt,turn + 1 });
			vis[nxt] = 1;
		}
		nxt = n + n;
		if (nxt > 99999 || nxt==0) continue;
		nxt = B(nxt);
		if (vis[nxt] == 0) {
			q.push({ nxt,turn + 1 });
			vis[nxt] = 1;
		}
	}
	puts("ANG");
	return 0;
}