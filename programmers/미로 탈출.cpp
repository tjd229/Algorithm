//https://programmers.co.kr/learn/courses/30/lessons/81304
//graph, dijkstra

#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define pii pair<int,int>
using namespace std;
int d[1001][1024];
int tr[1001];
tuple<int, int, int> adj[3000];
vector<int > edge[1001];
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	int answer = -1;
	for (int i = 1; i <= n; ++i) tr[i] = -1;
    for(int i=0;i<traps.size();++i) tr[traps[i]]=i;
	for (int i = 0; i < roads.size(); ++i) {
		int P = roads[i][0], Q = roads[i][1], S = roads[i][2];
		adj[i] = { P,Q,S };
		edge[P].push_back(i);
		edge[Q].push_back(i);
	}
	priority_queue<tuple<int,int,int> > q; q.push({-1,start, 0});
	d[start][0] = 1;
	
	while (q.size()) {
		int dist,x, stat; tie(dist,x, stat) = q.top();
		q.pop();
		if (-dist != d[x][stat]) continue;
		if (x == end) {
			if (answer<0 || answer>d[x][stat]-1)
				answer = d[x][stat]-1;
			continue;
		}
		for (auto ix : edge[x]) {
			int P, Q, S; tie(P, Q, S) = adj[ix];
			int swap_flag = 0;			
			if (tr[P] >= 0 && (stat&(1 << tr[P])))
				swap_flag = 1 - swap_flag;
			if (tr[Q] >= 0 && (stat&(1 << tr[Q])))
				swap_flag = 1 - swap_flag;
			if (swap_flag)
				P ^= Q ^= P ^= Q;
			if (P == x) {
				int nxt_stat = stat;
				if (tr[Q] >= 0) nxt_stat ^= (1 << tr[Q]);
				if (d[Q][nxt_stat] == 0 || d[Q][nxt_stat]>d[x][stat]+S) {
					d[Q][nxt_stat] = d[x][stat] + S;
					q.push({ -d[Q][nxt_stat],Q,nxt_stat });
				}
			}
		}
		
	}

	return answer;
}