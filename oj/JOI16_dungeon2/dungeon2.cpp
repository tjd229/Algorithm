//graph, math
#include "dungeon2.h"
#include <vector>
#include <queue>
#define pii pair<int,int>
#define reg register
using namespace std;
int d[201][201];
int it[201];
int last[201];
int N;
vector<pii > edge[201]; //ix,forw or rev or back
void bfs(int src) {
	queue<int> q;
	q.push(src);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (reg int i = 1; i < edge[u].size(); ++i) {
			int v = edge[u][i].first;
			if (v == src) continue;
			if (d[src][v]) continue;
			d[src][v]  = d[src][u] + 1;
			q.push(v);
		}
	}
}
void dfs(int x,int d) {
	int clr = (x / d) % 3;
	
	for (int i = 1; i < edge[x].size(); ++i) {
		//printf("%d,%d/%d : (%d,%d)\n",x,i,edge[x].size(),edge[x][i].first,edge[x][i].second);
		if (i==last[x]) continue;
		if (edge[x][i].second == 3) {
			Move(i, clr + 1);
			int c = Color()-1;
			edge[x][i].first += d * c;
			Move(LastRoad(), c+1);
			continue;
		}
		else if (edge[x][i].second == 4) continue;
		Move(i,clr+1);
		dfs(edge[x][i].first,d);
	}
	if(x>1)
		Move(last[x], clr+1);
}
void Inspect(int R)
{
	bool last_op = 1;//1: stk_push, 0: stk_pop
	vector<int > stk;
	stk.push_back(++N); 
	edge[N].resize(NumberOfRoads() + 1, { 0,0 });
	
	Move(++it[N], 2); 
	last[N] = -1; 
	while (stk.size()) {
		if (Color() == 1) {
			edge[++N].resize(NumberOfRoads() + 1, { 0,0 });
			last[N] = LastRoad();
			int p = stk.back();
			edge[N][last[N]] = {p,1};
			edge[p][it[p]] = {N,2};
			stk.push_back(N);
		}
		else if (Color() == 2 && last_op) {
			int top = stk.back();
			edge[top][it[top]] = { 0,3 };//back_edge
			Move(LastRoad(),2);
		}
		else if (Color() == 3) {
			int top = stk.back();
			edge[top][it[top]] = { 0,4 };//back_edge
			Move(LastRoad(), 3);
		}

		int top = stk.back();
		while (it[top]+1 < edge[top].size() 
			&&edge[top][it[top]+1].second!=0) { //if -> while
			++it[top];
		}
		if (it[top]+1 < edge[top].size()) {
			Move(++it[top],2);
			last_op = 1;
		}
		else {
			stk.pop_back();
			if(last[top]>0)
				Move(last[top], 3);
			last_op = 0;
		}
	}
	for (int d = 1, i = 0; i < 5; ++i, d *= 3) {
		dfs(1, d);
		if (N < d) break;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < edge[i].size(); ++j) {
			if (edge[i][j].second == 3) {
				int v = edge[i][j].first;
				for (int k = 1; k < edge[v].size(); ++k) {
					if (edge[v][k].first == 0) {
						edge[v][k].first = i;
						break;
					}
				}
			}
		}
	}
	/*for (int i = 1; i <= N; ++i) {
		for (auto x : edge[i]) printf("%d,%d ",x.first,x.second);
		puts("");
	}
	return;*/
	for (int i = 1; i <= N; ++i) bfs(i);
	int hist[201] = { 0 };
	for (reg int i = 1; i <= N; ++i) {
		for (reg int j = i + 1; j <= N; ++j) ++hist[d[i][j]];
	}
	for (int i = 1; i <= R; ++i) Answer(i,hist[i]);
	/*for (reg int i = 1; i <= N; ++i) {
		for (reg int j = i + 1; j <= N; ++j) 
			printf("%d->%d:%d\n",i,j,d[i][j]);
	}*/
	//BFS -> dist calc
	//report val calc
	//answer
}