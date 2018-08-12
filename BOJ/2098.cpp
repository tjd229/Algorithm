//category : dp

#include <stdio.h>
#include <memory.h>
#include <queue>
#define pii pair<int,int>
using namespace std;
int w[16][16];
int d[1 << 16][16];
int inq[1 << 16][16];
int min(int a, int b){
	
	if (a < 0) return b;
	if (b < 0) return a;
	return a < b ? a : b;
}
int main(){
	int N;
	int i, j;
	memset(d, -1, sizeof(d));
	for (scanf("%d", &N), i = 0; i < N; i++){
		for (j = 0; j < N; j++) scanf("%d",&w[i][j]);
	}
	d[1][0] = 0;
	queue<pii > q;
	q.push({ 1, 0 });
	inq[1][0] = true;
	while (q.size()){
		int city = q.front().second;
		int stat = q.front().first;
		q.pop();
		for (i = 0; i < N; i++){
			if (w[city][i] && (stat&(1 << i)) == 0){
				int nxt = stat | (1 << i);
				d[nxt][i] = min(d[nxt][i], d[stat][city] + w[city][i]);
				if (!inq[nxt][i]) q.push({nxt,i});
				inq[nxt][i] = true;
			}
		}
	}
	int ans = -1;
	int stat = (1 << N) - 1;
	for (i = 1; i < N; i++){
		if (w[i][0] && d[stat][i]>=0)
			ans = min(ans, d[stat][i] + w[i][0]);
	}
	printf("%d",ans);
	return 0;
}
