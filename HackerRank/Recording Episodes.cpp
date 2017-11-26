//category : graph, SCC, 2-SAT, line sweeping
//link : https://www.hackerrank.com/challenges/episode-recording/problem
#include <stdio.h>
#include <vector>

#define pii pair<int,int>
#define NEG 200
using namespace std;
struct Ep{
	int s, e;
	int ep_ix;
	int g_ix;
}ep[NEG+1];
int visit[NEG+NEG+1];
void add_edge(int u,int v,vector<int> *edge){
	if (u < 0) u = NEG - u;
	if (v < 0) v = NEG - v;
	edge[u].push_back(v);
}
void dfs(int ix,int stamp,vector<int> *edge){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size(); i++)
		dfs(edge[ix][i], stamp, edge);
	edge[0].push_back(ix);
}
bool check(vector<int> &v){
	if (v.empty()) return true;
	int cnt[NEG + 1] = { 0 };
	int x;
	for (int i = 0; i < v.size(); i++){
		x = v[i];
		if (x > NEG) x -= NEG;
		cnt[x]++;
		if (cnt[x] > 1) return false;
	}
	return true;
}
pii sat(int L,int R,int &stamp){
	if (L == R) return{ 1, -L };
	int i,j;
	vector<int> edge[NEG+NEG+1];
	vector<int> back[NEG+NEG+1];
	for (i = L; i <= R; i++){
		add_edge(i, -i - 100, edge);
		add_edge(i + 100, -i, edge);
		add_edge(-i - 100, i, edge);
		add_edge(-i, i + 100, edge);
		add_edge(i, -i - 100, back);
		add_edge(i + 100, -i, back);
		add_edge(-i - 100, i, back);
		add_edge(-i, i + 100, back);
	}
	for (i = L; i <= R; i++){
		for (j = L; j <= R; j++){
			if (ep[i].ep_ix == ep[j].ep_ix) continue;
			if (ep[i].s <= ep[j].e && ep[i].e >= ep[j].s){
				add_edge(ep[i].g_ix, -ep[j].g_ix, edge);
				add_edge(-ep[j].g_ix, ep[i].g_ix, back);
			}
		}
		for (j = L; j <= R; j++){
			if (ep[i].ep_ix == ep[j+100].ep_ix) continue;
			if (ep[i].s <= ep[j+100].e && ep[i].e >= ep[j+100].s){
				add_edge(ep[i].g_ix, -ep[j+100].g_ix, edge);
				add_edge(-ep[j+100].g_ix, ep[i].g_ix, back);
			}
		}
	}
	for (i = L; i <= R; i++){
		for (j = L; j <= R; j++){
			if (ep[i+100].ep_ix == ep[j].ep_ix) continue;
			if (ep[i+100].s <= ep[j].e && ep[i+100].e >= ep[j].s){
				add_edge(ep[i+100].g_ix, -ep[j].g_ix, edge);
				add_edge(-ep[j].g_ix, ep[i+100].g_ix, back);
			}
		}
		for (j = L; j <= R; j++){
			if (ep[i+100].ep_ix == ep[j + 100].ep_ix) continue;
			if (ep[i+100].s <= ep[j + 100].e && ep[i+100].e >= ep[j + 100].s){
				add_edge(ep[i+100].g_ix, -ep[j + 100].g_ix, edge);
				add_edge(-ep[j + 100].g_ix, ep[i+100].g_ix, back);
			}
		}
	}
	for (i = L; i <= R; i++) dfs(i, stamp, edge);
	for (i = L; i <= R; i++) dfs(i + 100, stamp, edge);
	for (i = L; i <= R; i++) dfs(i+NEG, stamp, edge);
	for (i = L; i <= R; i++) dfs(i + 100+NEG, stamp, edge);
	stamp++;
	for (i = edge[0].size() - 1; i > 0; i--){
		dfs(edge[0][i], stamp, back);
		if (!check(back[0])) return{ 0, -NEG-NEG };
		back[0].clear();
	}
	return{R-L+1,-L};
}
int main(){
	int i,j;
	int q;
	int n;
	int L, R;
	int f, b;
	int stamp = 0;
	for (scanf("%d", &q); q--;){
		pii ans = {0,-NEG-NEG};
		for (scanf("%d", &n), i = 1; i <= n; i++){
			scanf("%d%d",&L,&R);
			ep[i] = { L, R, i, i };
			scanf("%d%d", &L, &R);
			ep[i + 100] = { L, R, i, i + 100 };
		}
		L = R = 1;
		while (R<=n){
			if (L > R) R++;
			pii p = sat(L,R,++stamp);
			if (p.first == 0){
				L++;
			}
			else R++;
			if (ans < p) ans = p;
		}
		printf("%d %d\n",-ans.second,ans.first-ans.second-1);
		
	}

	return 0;
}
