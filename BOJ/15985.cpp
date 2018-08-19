//graph, dp

#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
vector<int> candi[10001];
int M[10001];
int d[10001][5001];
int c[10001][2];
int r[10001];
int t[10001];
int nl[10001];
bool save[10001][5001];
int N, K;
int min(int a, int b){
	if (a < 0) return b;
	if (b < 0) return a;
	return a < b ? a : b;
}
int relate(int x,int rel){
	int i;
	r[x] = rel;
	for (i = 1; i>=0;--i){
		int nxt = c[x][i];
		if (nxt){
			t[x]+=relate(nxt, rel)+nl[nxt];
			nl[x] += nl[nxt];
			rel = nxt;
		}
	}
	if (t[x] == 0) nl[x]++;
	return t[x];
}
int dfs(int x,int cost){
	if (cost>K) return -2e9;
	if (x == 0) return 0; //invalid
	if (save[x][cost]) return d[x][cost];
	save[x][cost] = 1;
	if (t[x] == 0){ //leaf
		d[x][cost] = dfs(r[x], cost + M[x]);
		return d[x][cost];
	}
	//if (d[x][cost] >= 0) return d[x][cost];
	int nxt = c[x][0];
	if (nxt){
		d[x][cost] = min(d[x][cost], dfs(nxt, cost));
	}
	nxt = r[x];
	d[x][cost] = min(d[x][cost], dfs(nxt, cost + M[x]) + t[x]);
	
	return d[x][cost];
}
int main(){
	int i;
	int A, B;
	memset(d, -1, sizeof(d));
	for (scanf("%d%d", &N, &K), i = 1; i <= N; i++) scanf("%d",M+i);
	for (i = 1; i < N; i++){
		scanf("%d%d",&A,&B);
		if (c[A][0]) c[A][1] = B;
		else c[A][0] = B;
	}
	relate(1,0);
	printf("%d",dfs(1, 0));
	//for (i = 1; i <= N; i++) printf("%d ",t[i]);
	return 0;
}
