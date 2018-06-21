//category : string, graph, SCC

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, q;
int a[10], b[10];
int visit[40000];
int id[40000];
int d[40000];
string mat[200];
vector<int> edge[40000], back[40000];
int sz[40001];
int stat[40001];
vector<int> sback[40001];
int cnt;
int to1D(int x,int y){
	return x + y*m;
}
void dfs(int ix,int stamp,vector<int> *edge, vector<int> &hist){
	if (visit[ix] == stamp) return;
	visit[ix] = stamp;
	for (int i = 0; i < edge[ix].size();i++)
		dfs(edge[ix][i], stamp, edge, hist);
	hist.push_back(ix);
}
bool search(int ix,int pt,string &s){
	if (s[pt] - '0' == d[ix]) pt++;
	if (pt == s.size()) return true;
	for (int i = 0; i < back[ix].size(); i++)
		if (search(back[ix][i], pt, s)) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int u, v;
	cin >> n >> m >> q;
	for (i = 0; i < n; i++)
		cin >> mat[i];
	
	for (i = 0; i < 10; i++) cin >> b[i] >> a[i];
	
	for (i = 0, u = 0; i < n; i++){
		for (j = 0; j < m; j++,u++){
			d[u] = mat[i][j] - '0';
			int x = j + a[d[u]];
			int y = i + b[d[u]];
			if (x < 0 || y < 0 || x >= m || y >= n) continue;
			v = to1D(x, y);
			edge[u].push_back(v);
			back[v].push_back(u);
		}
	}
	int nm = n*m;
	vector<int> candi,hist;
	int stamp = -1;
	for (i = 0; i < nm; i++) dfs(i, stamp, edge, hist);
	--stamp;
	while (hist.size()){
		vector<int> scc;
		dfs(hist.back(), stamp, back, scc);
		if (scc.size()){
			sz[++cnt]=scc.size();
			
			for (i = 0; i < scc.size(); i++)
				id[scc[i]] = cnt;
			for (i = 0; i < scc.size(); i++){
				u = scc[i];
				stat[cnt] |= (1 << d[u]);
				for (j = 0; j < back[u].size(); j++){
					v = back[u][j];
					if (id[u] != id[v]) sback[cnt].push_back(v);
				}
			}
			if (sz[cnt] > 1 || edge[scc[0]].empty()) candi.push_back(cnt);
		}
		hist.pop_back();
	}

	while (q--){
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		bool find = false;
		for (i = 0; i < candi.size() && !find; i++){
			int pt = 0;
			u = candi[i];
			while (pt < s.size() && (stat[u] & (1 << (s[pt] - '0')))) pt++;
			find = (pt == s.size());
			for (j = 0; j < sback[u].size() && !find; j++)
				find = search(sback[u][j], pt, s);
		}
		cout << (find? "YES":"NO") << "\n";
	}


	return 0;
}
