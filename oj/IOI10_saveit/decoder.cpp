//category : graph, cnt sort, math
#include "grader.h"
#include "decoder.h"
 
int tmp[1000];
int par[1000];
int que[1000];
 
void msort(int s, int e, int *li){
	if (s >= e) return;
	int m = (s + e) >> 1;
	msort(s, m, li);
	msort(m + 1, e, li);
	int i, l, r;
	l = s;
	r = m + 1;
	for (i = s; i <= e; i++){
		if (l > m) tmp[i] = li[r++];
		else if (r > e) tmp[i] = li[l++];
		else{
			tmp[i] = li[l] < li[r] ? li[l++] : li[r++];
		}
	}
	for (i = s; i <= e; i++) li[i] = tmp[i];
}
void bfs0(int nv, int *dist, int *tail, int edge[1000][1000]){
	bool visit[1000] = { 0 };
	int front, back;
	visit[0] = 1;
	dist[0] = 0;
	front = back = 0;
	que[back++] = 0;
	int i;
 
	while (front != back){
		int curr = que[front++];
		for (i = 0; i < tail[curr]; i++){
			int nxt = edge[curr][i];
			if (!visit[nxt]){
				visit[nxt] = 1;
				que[back++] = nxt;
				par[nxt] = curr;
				dist[nxt] = dist[curr] + 1;
			}
		}
	}
}
void decode(int nv, int nh) {
	int i, j, k;
	int edge[1000][1000];
	int tail[1000] = { 0 };
	int dist[36][1000] = { 0 };
	for (i = 1; i < nv; i++){
		int p = 0;
		for (j = 0; j < 10; j++){
			int b = decode_bit();
			p += (b << j);
		}
		edge[p][tail[p]++] = i;
	}
	for (i = 0; i < nv; i++) msort(0, tail[i] - 1, edge[i]);
	bfs0(nv, dist[0], tail, edge);
	for (i = 1; i < nh; i++) dist[i][0] = dist[0][i];
	int div = 0;
	int f;
	for (i = 1; i < nv; i++){
		int v = que[i];
		for (j = 1; j < nh; j++){
			if (v == j) continue;
			if (div == 0){
				div = 3 * 3 * 3 * 3;
				f = 0;
				for (k = 0; k < 8; k++){
					int b = decode_bit();
					f += (b << k);
				}
			}
			int rd = f / div;
			f %= div;
			div /= 3;
 
			dist[j][v] = dist[j][par[v]] + rd - 1;
		}
	}
 
	for (i = 0; i < nh; i++) for (j = 0; j < nv; j++) hops(i, j, dist[i][j]);
 
}
