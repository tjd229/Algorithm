//category : graph, cnt sort, math

#include "grader.h"
#include "encoder.h"
int p[1000];
int visit[1000];
int edge[1000][1000];
int tail[1000];
int dist[36][1000];
int q[1000];
int front;
int back;
void bfs(int nv, int src){
	visit[src] = src + 1;
	dist[src][src] = 0;
	front = back = 0;
	q[back++] = src;
	int i;
 
	while (front != back){
		int curr = q[front++];
		for (i = 0; i < tail[curr]; i++){
			int nxt = edge[curr][i];
			if (visit[nxt] != src + 1){
				visit[nxt] = src + 1;
				q[back++] = nxt;
				p[nxt] = curr;
				dist[src][nxt] = dist[src][curr] + 1;
			}
		}
	}
}
 
void cnt_sort(int len, int *li){
	int cnt[1001] = { 0 };
	int i, j;
	for (i = 0; i < len; i++) cnt[li[i]]++;
	for (i = 1000, j = len; i >= 0; i--){
		while (cnt[i]--) li[--j] = i;
	}
}
void encode(int nv, int nh, int ne, int *v1, int *v2){
	int i, j;
	int u, v;
	int buf[36 * 1000] = { 0 };
	while (ne--){
		u = v1[ne];
		v = v2[ne];
		edge[u][tail[u]++] = v;
		edge[v][tail[v]++] = u;
	}
	for (i = 0; i < nv; i++) cnt_sort(tail[i], edge[i]);
	for (i = nh; i--;){
		bfs(nv, i);
	}
	for (i = 1; i < nv; i++){		//for 0
		u = p[i];
		j = 10;
		while (j--){
			encode_bit(u & 1);
			u >>= 1;
		}
	}
	tail[0] = 0;
	for (i = 1; i < nv; i++){
		v = q[i];
		for (j = 1; j < nh; j++){
			if (v == j) continue;
			int d = dist[j][v] - dist[j][p[v]] + 1;
			buf[tail[0]++] = d;
			//encode_bit(d & 1);
			//encode_bit((d >> 1) & 1);
		}
	}
	for (i = 0; i < tail[0]; ){
		int f = 0;
		for (j = 0; j < 5; j++,i++){
			f = f * 3 + buf[i];
		}
		for (j = 0; j < 8; j++){
			encode_bit(f & 1);
			f >>= 1;
		}
	}
}
