//category : string, AC, dp

#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
#define pii pair<int,int>
using namespace std;
int nix[21];
pii mat[21][21];//dist, val
int d[1001][21];
int cnt;
int N, K;
string S[21];
struct Node{
	int pi;
	int depth;
	int edge[3];
	int valid;
	int tail;
}node[15*20+1];
int visit[15 * 20 + 1];
int max(int a, int b){ return a < b ? b : a; }
void make_trie(string &s,int six){
	int ix = 0;
	int curr = 0;
	while (curr != s.size()){
		if (node[ix].edge[s[curr] - 'A'] == 0){
			node[ix].edge[s[curr] - 'A'] = ++cnt;
			node[cnt].depth = node[ix].depth + 1;
		}
		ix = node[ix].edge[s[curr] - 'A'];
		curr++;
	}
	node[ix].valid = six;
	nix[six] = ix;
}
void set_pi(int s){
	queue<pair<int, pii > > q;
	q.push({ s, { 0, 0 } });
	int curr, nxt;
	int i;
	while (q.size()){
		curr = q.front().first;
		int dist = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		node[curr].tail = node[node[curr].pi].tail + (node[curr].valid > 0);
		cnt += node[curr].tail;	
		d[dist][node[curr].valid] = cnt;
		
		for (i = 0; i < 3; i++){
			nxt = node[curr].edge[i];
			if (nxt){
				int p = node[curr].pi;
				while (p > 0 && node[p].edge[i] == 0) p = node[p].pi;
				if (nxt != node[p].edge[i]){
					node[nxt].pi = node[p].edge[i];
					
				}
				q.push({ nxt, {dist+1,cnt} });
			}
		}
	}
}

int bfs(int src,int bnd,int stamp){
	long long end_stat = 0;
	int i;
	int maxv = 0;
	for (i = 1; i <= N; i++) end_stat |= (1LL << i);
	queue<pair<int, pii > > q;
	q.push({ nix[src], {0,0} });
	while (q.size() && end_stat){
		int curr = q.front().first;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		if (d > bnd) break;

		//printf("%d\n",d);
		if (maxv < cnt) maxv = cnt;
		q.pop();

		for (i = 0; i < 3; i++){
			int ix = curr;
			int nxt = node[ix].edge[i];
			while (nxt==0 && ix != 0){
				ix = node[ix].pi;
				nxt = node[ix].edge[i];
			}

			if (end_stat & (1LL << (node[nxt].valid))){
				end_stat ^= (1LL << (node[nxt].valid));
				mat[src][node[nxt].valid] = { d + 1, cnt + node[nxt].tail };
			}
			if (visit[nxt] != stamp){
				visit[nxt] = stamp;
				q.push({ nxt, { d + 1, cnt + node[nxt].tail } });
			}
		}
	}
	return maxv;
}
int main(){
	int i,j,k;
	int last[21] = { 0 };
	memset(d, -1, sizeof(d));
	cin >> N >> K;
	for (i = 1; i <= N; i++){
		cin >> S[i];
		make_trie(S[i], i);
	}
	set_pi(0);
	for (i = 1; i <= N; i++) bfs(i, 15,i);
	//return 0;
	//for (i = 1; i <= N; i++){
	//	int dist = mat[i][i].first;
	//	int cnt = mat[i][i].second;
	//	d[dist][i] = cnt;
	//}
	for (i = 1; i < K; i++){
		for (j = 1; j <= N; j++){
			if (d[i][j] < 0) continue;
			for (k = 1; k <= N; k++){
				int dist = mat[j][k].first;
				int cnt = mat[j][k].second;
				if (i + dist > K || dist==0) continue;
				d[i + dist][k] = max(d[i + dist][k], d[i][j] + cnt);
				if (i + dist < K)
					last[k] = max(last[k], i + dist);
			}
		}
	}
	int ans = 0;
	for (i = 1; i <= N; i++){
		d[K][i] = max(d[K][i], d[last[i]][i] + bfs(i, K - last[i],i+N));
		ans = max(ans, d[K][i]);
		//printf("%d\n",d[K][i]);
	}
	printf("%d",ans);

	return 0;
}
